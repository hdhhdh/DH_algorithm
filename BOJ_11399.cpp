#include <iostream>
#include <algorithm>

using namespace std;
int n;

int n_time[1001];

int main()
{
	cin >> n;
	
	for(int i = 1; i<=n; i++)
	{
		cin >> n_time[i];		
	}
	
	sort(n_time, n_time+n+1);
	
	for(int i = 1; i<=n; i++)
	{
		n_time[i] += n_time[i-1];	
	}
	for(int i = 1; i<=n; i++)
	{
		n_time[i] += n_time[i-1];	
	}
	cout << n_time[n];
	return 0;
}
