#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int value[100001]={};
	int dp[100001]={};
	for(int i=1; i<=n; i++)
	{
		cin >> value[i];
	}
	
	dp[1] = value[1];
	int big = dp[1];
	for(int i = 2; i<=n; i++)
	{	
		dp[i] = max(dp[i-1] + value[i], value[i]);
		big = max(big, dp[i]);
		
	}
	
	cout << big << endl;
	
	return 0;
}
