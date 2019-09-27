#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	string temp = "";
	temp = to_string(a * b * c);
	map<char, int> m;
	for (int i = 0; i < temp.size(); i++)
	{
		m[temp[i]]++;
	}
	for (char i = '0'; i <= '9'; i++)
	{
		if (m[i]) cout << m[i] << endl;
		else cout << 0 << endl;
	}
	return 0;
}
