#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L, C;
string temp = "";

int aeiou = 0;
int aeiou_else = 0;

void solve(string ary, int n, vector<char> v)
{	
	if(ary.length() == L)
	{
		for(int i = 0; i<ary.length(); i++)
		{
			if(ary[i] == 'a' || ary[i] == 'e' ||ary[i] == 'i' ||ary[i] == 'o' ||ary[i] == 'u') aeiou++;
			else aeiou_else++;
		}
		if(aeiou >= 1 && aeiou_else >= 2)
		{
			cout << ary << '\n';
		}
		aeiou = 0;
		aeiou_else = 0;
	}
	for(int i = n; i<C; i++)
	{
		solve(ary + v[i], i+1, v);
	}
}

int main()
{
	int cnt = 1;
	cin >> L >> C;
	vector<char> v(C);
	for(int i = 0; i<C; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	solve(temp, 0, v);
	
	return 0;
}
