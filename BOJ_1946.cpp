#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<pair<int, int> > a[20];
int main()
{
	cin >> T;
	
	for(int i = 0; i<T; i++)
	{
		int N = 0;
		cin >> N;
		for(int j = 0; j<N; j++)
		{
			int s = 0, m = 0;
			cin >> s >> m;
			a[i].push_back(make_pair(s, m));
		}
	}
	int cnt = 0;
	for(int i = 0; i<T; i++)
	{
		sort(a[i].begin(), a[i].end());
		int s_max = 0, m_max = 0;
		for(int j = 0; j<a[i].size(); j++)
		{
			if(j == 0)
			{
				cnt++;
				s_max = a[i][j].first;
				m_max = a[i][j].second;
			}
			else
			{
				if(s_max > a[i][j].first || m_max > a[i][j].second)
				{
					cnt++;	
					s_max = a[i][j].first;
					m_max = a[i][j].second;
					continue;
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}	
	return 0;	
}
