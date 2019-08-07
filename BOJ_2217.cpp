#include <iostream>
#include <algorithm>
using namespace std;

int n;
int rope[100000];

int main()
{
	cin >> n;
	int k = n;
	for(int i = 0; i<n; i++)
	{
		cin >> rope[i];
	}
	
	sort(rope, rope+n);
	
	for(int i = 0; i<n; i++)
	{
		rope[i] = rope[i] * k;
		k = k-1;
	}
	
	sort(rope, rope+n);

	cout << rope[n-1];
	return 0;
}
