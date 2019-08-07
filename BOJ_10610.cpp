#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int m = 100001;
int sum;
bool check_z = false;
int main()
{
	char a[m];
	cin >> a;
	int length = strlen(a);
	
	for(int i = 0; i<length; i++)
	{
		if(a[i] == '0') check_z = true;
		sum += a[i] - '0';
	}
	
	if(sum % 3 == 0 && check_z == true)
	{
		sort(a, a + length);
		for(int i = length-1; i>=0; i--)
		{
			cout << a[i];
		}

	}
	else cout << -1;
	
	return 0;
}
