#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	map<string, bool> name;
	for (int i = 0; i < N; i++)
	{
		string temp = "";
		cin >> temp;
		name[temp] = true;
	}
	vector<string> v;
	for (int i = 0; i < M; i++)
	{
		string temp = "";
		cin >> temp;
		if (name[temp] == true)
		{
			v.push_back(temp);
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;

}
