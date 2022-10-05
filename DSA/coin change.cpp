#include<bits/stdc++.h>
using namespace std;
int coinChanage(int sum,int arr[],int size)
{
    int ROW = size+1;
    int COL = sum+1;
    int dp[ROW][COL];
    for(int i=0;i< COL;i++)
    {
        dp[0][i] = 0;
    }
    for(int i=0;i< ROW;i++)
    {
        dp[i][0] = 1;
    }
    for(int i=1;i<ROW;i++)
    {
        for(int j=1;j<COL;j++)
        {
        	if(j < arr[i-1] )
        	{
        		dp[i][j] = dp[i-1][j];
			}
			else
            	dp[i][j] = dp[i][j-arr[i-1]] + dp[i-1][j]; 
        }
    }

    return dp[ROW-1][COL-1];
}
int main()
{
int sum = 4 ;
int N = 3;
int coins[] = {1,2,3};
cout<< coinChanage(sum,coins,N);
}
