#include <iostream>

using namespace std;

int n;
int value[10001];

int main()
{
	cin >> n;
	for(int i = 0; i<n;i++)
	{
		int v;
		cin.tie(NULL);
		ios::sync_with_stdio(false);
		cin >> v;
		value[v]++;
	}
	
	for(int i = 1; i<10001; i++)
	{
		while(value[i] != 0)
		{
			value[i]--;
			cout << i << '\n';
		}
	}
	
	return 0;
	
}
