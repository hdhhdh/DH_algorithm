#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> q;

int c_bfs[1001];
int c_dfs[1001];
vector<int> a[1001];

void dfs(int x)
{
	if(c_dfs[x]) return;
	c_dfs[x] = true;
	cout<< x << ' ';
	for(int i = 0; i< a[x].size(); i++)
	{
		int y = a[x][i];
		dfs(y);
	}	
}


void bfs(int start)
{
	q.push(start);
	c_bfs[start] = true;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for(int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if(!c_bfs[y])
			{
				q.push(y);
				c_bfs[y] = true;
			}
		}
	}
}

int main()
{
	int N, M, V;
	cin >> N >> M >> V;
	
	for(int i = 1; i<= M; i++)
	{
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	
	for(int i = 1; i<=N; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	
	dfs(V);
	cout << '\n';
	bfs(V);
	return 0;
}
