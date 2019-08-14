#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2;
	int minimum = 50;
	int cnt = 0;
	cin >> s1 >> s2;
	
	int size1 = s1.length();
	int size2 = s2.length();
	int len_diff = size2 - size1;

	for(int i = 0; i<= len_diff; i++)
	{
		cnt = 0;
		for(int j = 0; j<size1; j++)
		{
			if(s1[j] != s2[i + j]) cnt++;
		}
		
		if(minimum >= cnt) minimum = cnt;
		else minimum = minimum;
		
	}
	
	cout << minimum;
	return 0;
	
}
