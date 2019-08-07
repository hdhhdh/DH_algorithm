#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int cnt = 0;
	while(n!=0)
	{
		cnt += n%2;
		n /= 2;
	}
	cout << cnt;
	return 0;	
}
