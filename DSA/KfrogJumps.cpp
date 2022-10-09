#include<bits/stdc++.h>
using namespace std;

//tabulation
int KfrogJumpsT(int n,vector<int> heights,int k,vector<int>&dp)
{
	dp[0] = 0;
	
	 for(int i=1;i<=n;i++)
	 {
	 	dp[i] = INT_MAX;
	 	for(int j=1;i-j>=0 && j<=k; j++)
	 	{
	 		dp[i] = min(dp[i],dp[i-j]+abs(heights[i] - heights[i-j]));
		}
	 }
	 		
	return dp[n];

}
//memoization
int KfrogJumpsM(int n,vector<int> heights,int k,vector<int>&dp)
{
	if(n==0)
	{
		return 0;
	}
	if(dp[n]==-1)
	{
	 int min_ = INT_MAX;
	 for(int i=1;i<=k && n-i>=0;i++)
	 {
		min_ = min(min_,KfrogJumpsM(n-i,heights,k,dp)+abs(heights[n-i] - heights[n]));
		dp[n] = min_;
	 }
}
	return dp[n];

}
//recursion
int KfrogJumpsR(int n,vector<int> heights,int k)
{
	if(n==0)
	{
		return 0;
	}
	int min_ = INT_MAX;
	for(int i=1;i<=k && n-i>=0;i++)
	{
		min_ = min(min_,KfrogJumpsR(n-i,heights,k)+abs(heights[n-i] - heights[n]));
	}
	return min_;
}
int solve(int n,vector<int> heights,int k)
{
	
	vector<int>dp(n,-1);
	//return KfrogJumpsR(n-1,heights,k);
	//return KfrogJumpsM(n-1,heights,k,dp);
	return KfrogJumpsT(n-1,heights,k,dp);
}
int main()
{
	vector<int> heights{30,10,60, 10 , 60 , 50};
	int k=2;
	int n=heights.size();
	cout<<solve(n,heights,k);
}

