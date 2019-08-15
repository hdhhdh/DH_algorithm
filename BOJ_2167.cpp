#include <iostream>
using namespace std;

int n, m;
int dp[301][301];
int map;

int k;

int i, j, x, y;

int main()
{
	cin >> n >> m;
	
	for(int a = 1; a<=n; a++)
	{
		for(int b = 1; b<=m; b++)
		{
			cin >> map;
			dp[a][b] = dp[a-1][b] + dp[a][b-1] - dp[a-1][b-1] + map;
		}
	}
	
	cin >> k;
	
	for(int z = 0; z<k; z++)
	{
		cin >> j >> i >> y >> x;
		cout << dp[y][x] - dp[y][i-1] - dp[j-1][x] + dp[j-1][i-1] << '\n';
	}
	return 0;
}
