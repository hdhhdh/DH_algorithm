#include <iostream>
#include <algorithm>
using namespace std;

int n;
int card[1001];
int dp[1001];

int main()
{
	cin >> n;
	for(int i = 1; i<= n; i++)
	{
		cin >> card[i];
	}
	
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=i; j++)
		{
			dp[i] = max(dp[i], dp[i-j] + card[j]);
		}
	}
	
	cout << dp[n];
	return 0;
}
