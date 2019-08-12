#include <iostream>
using namespace std;

int n, m, k, team;

int main()
{
	cin >> n >> m >> k ;
	
	team = min((n + m - k) / 3, n / 2);
	team = min(team, m);
	
	cout << team;
	
	return 0;
}
