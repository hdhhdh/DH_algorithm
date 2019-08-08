#include <iostream>
using namespace std;

int dp[100];

int T;

int main()
{
	cin >> T;
	int n = 0;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	for(int i = 5; i<100; i++)
	{
		dp[i] = dp[i-2] + dp[i-3];
	}
	
	for(int i = 0; i<T; i++)
	{
		int n = 0;
		cin >> n;
		cout << dp[n-1] << '\n';
	}
	return 0;
	
}
