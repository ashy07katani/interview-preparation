#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &heights)
{
	if(n==0)
	{
		return 0;
	}
	int left = f((n)-1,heights) + abs(heights[(n)]-heights[(n)-1]);
    int right = INT_MAX;
    if((n)>1)
    {
        right = f((n)-2,heights) + abs(heights[(n)]-heights[(n)-2]);
    }
    return min(left,right);
}

int fm(int n, vector<int> &heights,vector<int> &dp)
{
	//how to convert recursion to memoized 
	//declare a dp array of size n, in this case it is coming in the function parameter
	
	//base case
	if(n==0)
	{
		return 0;
	}
	//solve it first, if not solved
	if(dp[n]==-1)
	{
		//store it
		int left = abs(heights[n-1] - heights[n]) + fm(n-1,heights,dp);
		int right = INT_MAX;
		if(n>1)
			right = abs(heights[n-2] - heights[n]) + fm(n-2,heights,dp);
		dp[n] = min(left,right);
	}
	//return if already stored
	return dp[n];
	
	
}

int ft (int n, vector<int> &heights,vector<int> &dp)
{

	dp[0] = 0;
	for(int i=1;i<=n;i++)
	{
			if(i>1)
				dp[i] = min(abs(heights[i-2] - heights[i]) + dp[i-2], abs (heights[i-1] - heights[i]) + dp[i-1]);
			else
				dp[i] = abs (heights[i-1] - heights[i]) + dp[i-1];
	}
	
	for(int i=0;i<=n;i++)
	{
		cout<<dp[i]<<endl;
	}
	return dp[n];
}
int frogJump(int n, vector<int> &heights)
{
	//recursive solution
	//return f(n-1,heights);
	vector<int> dp(n,-1);
	//memoized solution
	//return fm(n-1,heights,dp);
	//tabulation solution
	return ft(n-1,heights,dp);
	
}

int main()
{
	
 
	//cout<<"hello world";
	vector<int> a ={7, 5, 5, 8, 4, 9 ,1 ,1 ,10};
	int n = 9;
	cout<<frogJump(n,a);
	
	
}

