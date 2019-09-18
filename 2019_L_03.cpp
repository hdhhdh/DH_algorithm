#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;
int cnt = 0;

map<string, pair<string, string>> m1;
map<string, pair<string, string>> m2;

bool cmp(string a, string b)
{
	return stoi(a) < stoi(b);
}

int main()
{
	vector<string> v1;
	vector<string> v2;
	vector<string> for_sort;
	vector<string> second_id;

	for (int a = 0; a < 2; a++)
	{
		int n = 0;
		cin >> n;
		std::cin.ignore(32767, '\n');

		for (int i = 0; i < n; i++)
		{
			string temp = "";
			getline(cin, temp);
			istringstream is_temp(temp);

			if (a == 0 && i == 0)
			{
				string s1 = "";
				while (is_temp >> s1)
				{
					v1.push_back(s1);
				}
			}
			else if (a == 1 && i == 0)
			{
				string s2 = "";
				while (is_temp >> s2)
				{
					v2.push_back(s2);
				}
			}
			else
			{
				if (a == 0)
				{
					string id;
					string name;
					string occupation;
					is_temp >> id;
					is_temp >> name;
					is_temp >> occupation;

					for_sort.push_back(id);
					m1[id].first = name;
					m1[id].second = occupation;
				}
				else
				{
					string id;
					string name;
					string occupation;
					is_temp >> id;
					is_temp >> name;
					is_temp >> occupation;

					second_id.push_back(id);
					m2[id].first = name;
					m2[id].second = occupation;
				}
			}
		}
	}
	sort(for_sort.begin(), for_sort.end(), cmp);
	cout << '\n';
	for (int i = 0; i < for_sort.size() + 1; i++)
	{
		string out = "";
		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				out.append(v1[j]);
				out.append(" ");
			}
			for (int j = 0; j < 3; j++)
			{
				if (out.find(v2[j]))
				{
					out.append(v2[j]);
					out.append(" ");
				}
			}
		}
		else
		{	
			out.append(for_sort[i - 1]);
			out.append(" ");
			out.append(m1[for_sort[i - 1]].first);
			out.append(" ");
			out.append(m1[for_sort[i - 1]].second);
			out.append(" ");

			if (find(second_id.begin(), second_id.end(), for_sort[i - 1]) != second_id.end())
			{
				out.append(m2[for_sort[i - 1]].first);
				out.append(" ");
				out.append(m2[for_sort[i - 1]].second);
				out.append(" ");
			}
			else
			{

				for (int k = 0; k < v2.size(); k++)
				{
					if (find(v1.begin(), v1.end(), v2[k]) != v1.end()) continue;
					out.append("NULL");
					out.append(" ");
				}
			}
		}
		cout << out << endl;
	}
	return 0;
}
