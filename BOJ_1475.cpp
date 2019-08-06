#include <iostream>
#include <algorithm>
using namespace std;
int idx[10];
int main()
{
	int n;
	cin >> n;
	int number = 0;
	while(1)
	{
		idx[n%10]++;
		if(n/10 == 0) break;
		n = n/10;
	}
	
	for(int i = 0; i<10; i++)
	{
		if(i != 9 && i!=6)
		{
			number = max(number, idx[i]);
		}
	}
	
	cout << max(number, (idx[6] + idx[9] + 1)/2 );
	return 0;
	
}
