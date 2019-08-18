#include <iostream>
using namespace std;

int dp[1001][1001];
int map[1001][1001];

int n, m;

int main()
{
	cin >> n >> m;
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			cin >> map[i][j];	
		}
	}
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
		{
			int a = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
			dp[i][j] = a + map[i][j];
		}
	}
	
	cout << dp[n][m];
	return 0;
	
}
