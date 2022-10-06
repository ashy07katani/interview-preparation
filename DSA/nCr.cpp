#include<bits/stdc++.h>
using namespace std;
int nCr(int n, int r){
        
        int count =0 ;
        int dp[r+1][n+1];
        
        for(int i=0;i<=r;i++)
        {
        	dp[i][0] = 0;
        	
		}

		 for(int i=0;i<=n;i++)
        {
        	dp[0][i] = 0;
        	dp[1][i] = i;
		}
	
		for(int i=2;i<=r;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i > j)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
				}
			}
		}
		
        return dp[r][n];
    }
int main()
{
	cout<<nCr(9,5);
}

