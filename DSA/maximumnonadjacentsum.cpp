#include<bits/stdc++.h>
using namespace std;

int mNASR(vector<int>&nums,int n)
{
	if(n < 0)
	{
		return 0;
	}
	if(n==0)
	{
		return nums[0];
	}
	int pick = nums[n] + mNASR(nums,n-2);
	int notpick = 0 + mNASR(nums,n-1);
	return max(pick,notpick);
}
int mNASM(vector<int>&nums,int n,vector<int>& dp)
{
	if(n==0)
	{
		dp[n] = nums[0];
	}
	if(n<0)
	{
		return 0;
	}
	if(dp[n] ==-1)
	{
		int pick = nums[n]+mNASM(nums,n-2,dp);
		int notpick = 0 + mNASM(nums,n-1,dp);
		dp[n] = max(pick,notpick);
	}
		return dp[n];
	
}

int mNAST(vector<int>&nums,int n,vector<int>& dp)
{
	int pick=0,notpick=0;
	for(int i=0;i<=n;i++)
	{
		if(i==0)
		{
			dp[i]=nums[i];
		}
		else
		{
			pick = nums[i];
			if(i>1)
			{
				pick+=dp[i-2];
			}
			notpick = dp[i-1];
			dp[i] = max(pick,notpick);
		}
		
		cout<<dp[i]<<endl;
	}
	cout<<n<<dp[n]<<endl;
	return dp[n];
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp (nums.size(),-1);
    //int m =  mNASR(nums,nums.size()-1);
    //int m =  mNASM(nums,nums.size()-1,dp);
    int m = mNAST(nums,nums.size()-1,dp);
	return m;
    
}
int main()
{
	vector<int> nums = {2 ,1 ,4 ,9};
	cout<<maximumNonAdjacentSum(nums);
}

