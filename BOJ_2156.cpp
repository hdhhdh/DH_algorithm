#include <iostream>
#include <algorithm>
using namespace std;

int main(){


	int n;
	cin >> n;
	int table[10001] = {};
	int dp[10001] = {};
	for(int i = 1; i<=n; i++)
	{
		cin >> table[i];
	}
	
	dp[1] = table[1];
	dp[2] = dp[1] + table[2];
	
	for(int i = 3; i<=n; i++)
	{
		int big=0;
		big = max(dp[i-1], dp[i-2] + table[i]);
		dp[i] = max(big, dp[i-3] + table[i-1] + table[i]);
		
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
