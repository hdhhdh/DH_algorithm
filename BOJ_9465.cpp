#include <iostream>
using namespace std;
int T;
int dp[2][100000];
int sti[2][100000];

int main()
{
	cin >> T;
	int n = 0;
	for(int i = 0; i<T; i++)
	{
		cin >> n;
		for(int re = 0; re<2; re++)
		{
			for(int j = 0; j<n;j++)
			{
				cin >> sti[re][j];
			}
		}
		
		dp[0][0] = sti[0][0];
		dp[0][1] = dp[1][0] + sti[0][1];
		dp[1][0] = sti[1][0];
		dp[1][1] = dp[0][0] + sti[1][1];
		
		for(int i = 0; i<n; i++)
		{
			dp[0][i] = sti[0][i] + max(dp[1][i-1], dp[1][i-2]);
			dp[1][i] = sti[1][i] + max(dp[0][i-1], dp[0][i-2]);
		}
		cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
	}
	return 0;
}
