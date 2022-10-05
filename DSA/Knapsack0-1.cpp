#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int,int>a,pair<int,int>b)
{
	return a.first < b.first;
}
int knapsack(int wt[],int val[],int N,int W)
{
	vector<pair<int,int>>wtval;
	for(int i=0;i<N;i++)
	{
		wtval.push_back({wt[i],val[i]});
	}
	sort(wtval.begin(),wtval.end(),comparator);
	int dp[N+1][W+1];
	for(int i=0;i<=N;i++)
	{
		dp[i][0]=0;
	}
	for(int j=0;j<=W;j++)
	{
		dp[0][j] = 0;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(wtval[i-1].first > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-wtval[i-1].first]+wtval[i-1].second);
			}
		}
	}
	return dp[N][W];
	
}
int main()
{
int N = 5;
int W = 10;
int values[] = {1 ,2 ,5 ,9 ,4};
int weight[] = {2 ,3, 3, 4, 6};
cout<<knapsack(weight,values,N,W);
}

