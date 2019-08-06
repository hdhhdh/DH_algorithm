#include <iostream>
#include <algorithm>
using namespace std;

int main(){


	int n;
	int scale[501][501]={0};
	int dp[501][501] = {0};
	
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			cin >> scale[i][j];
		}
	}
	dp[0][0] = scale[0][0];
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j == 0)
			{
				dp[i][j] = dp[i-1][j] + scale[i][j];
			}
			else if(i == j)
			{
				dp[i][j] = dp[i-1][j-1] + scale[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + scale[i][j];
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i<n; i++)
	{
		if(dp[n-1][i] > max)
		{
			max = dp[n-1][i];
		}
	}
	cout << max << endl;
	
	return 0;
}
