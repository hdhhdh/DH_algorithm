#include <iostream>
#include <queue>

using namespace std;
int t, n, m;
int importance;

priority_queue<int> pq;
queue<pair<int ,int> > q;

int main()
{
	cin >> t;
	for(int i = 0; i<t; i++)
	{
		int cnt = 0;
		cin >> n >> m;
		
		priority_queue<int> pq;
		queue<pair<int ,int> > q;
		
		for(int j = 0; j<n; j++)
		{
			cin >> importance;
			pq.push(importance);
			q.push(make_pair(j, importance));
		}
		
		while(!pq.empty())
		{
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if(pq.top() == value)
			{
				pq.pop();
				cnt++;
				if(index == m)
				{
					cout << cnt << '\n';
					break;
				}
			}
			else
			{
				q.push(make_pair(index, value));
			}
		}
	}
	return 0;
}
