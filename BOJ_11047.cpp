#include <iostream>

using namespace std;

int won[13];
int n;
int k;
int main()
{
	int result = 0;
	cin >> n >> k;
	for(int i = 0; i<n; i++)
	{
		cin >> won[i];
	}
	
	for(int i = n-1; i>=0; i--)
	{
		result += k/won[i];
		k %= won[i];
	}
	
	cout << result;
	return 0;
}
