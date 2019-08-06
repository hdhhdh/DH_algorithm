#include <iostream>
#define max 1000000000
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int dp[101][101] = {};
	
	for(int i = 1; i<=9; i++) dp[1][i] = 1;
	
	for(int i = 2; i<=n; i++)
	{
		for(int j = 0; j<=9; j++)
		{
			if(j == 0) dp[i][j] = dp[i-1][j+1] % max;
			else if(j == 9) dp[i][j] = dp[i-1][j-1] % max;
			else{
				dp[i][j] = ((dp[i-1][j-1] % max) + (dp[i-1][j+1] % max)) % max;
			}
		}
	}
	
	int num = 0;
	for(int i=0; i<=9; i++)
	{
		num = (num + dp[n][i]) % max;
	}
	
	cout << num << endl;
	return 0;
	
}
