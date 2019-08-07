#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int sum = 0;
	int get_on = 0, get_off = 0;
	for(int i = 0; i<4;i++)
	{
		cin >> get_off >> get_on;
		sum = max(sum, sum - get_off + get_on);
	}
	
	cout << sum;
	return 0;
}
