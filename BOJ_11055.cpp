#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int arr[1001];

int n;

int main()
{
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 1; i<=n; i++)
	{
		if(dp[i] == 0) dp[i] = arr[i];
		for(int j = 1; j<=i; j++)
		{
			if(arr[i] > arr[j])
			{
				if(dp[i] < dp[j] + arr[i])
				{
					dp[i] = dp[j] + arr[i];
				}				
			}
		}
	}
	sort(dp, dp+n+1, greater<int>());
	cout << dp[0];
	
	return 0;
}
