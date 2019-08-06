#include <iostream>
#include <algorithm>
using namespace std;

string serial[1000];
int n;

int getSum(string a)
{
	int lenght = a.length();
	int sum = 0;
	for(int i = 0; i < lenght; i++)
	{
		if(a[i] - '0' <= 9 && a[i] - '0' >= 0)
		{
			sum += a[i] - '0';
		}
	}
	return sum;
	
}

bool compare(string a, string b)
{
	if(a.length() < b.length())
	{
		return 1;
	}
	else if(a.length() > b.length())
	{
		return 0;
	}
	else
	{
		int aSum = getSum(a);
		int bSum = getSum(b);
		
		if(aSum != bSum)
		{
			return aSum < bSum;
		}
		else
		{
			return a < b;
		}
	}
}

int main()
{
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		cin >> serial[i];
	}
	
	sort(serial, serial + n, compare);
	for(int i = 0; i<n;i++)
	{
		cout << serial[i] << endl;
	}
	
	return 0;
	
}
