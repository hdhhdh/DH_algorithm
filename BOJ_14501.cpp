#include <iostream>

using namespace std;

int n;
int ti[15];
int pi[15];
int dp[15];

int main()
{
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> ti[i] >> pi[i];
	}
	
	for(int i = n-1; i>=0; i--)
	{
		if(i + ti[i] >= n + 1)
		{
			dp[i] = max(dp[i+1], 0);
			continue;
		} 
		dp[i] = max(dp[i+1], dp[i + ti[i]] + pi[i]);
	}
	
	cout << dp[0];
	return 0;
	
}
