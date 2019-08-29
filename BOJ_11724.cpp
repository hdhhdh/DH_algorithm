#include <iostream>
#include <vector>
using namespace std;

int n, m, u, v;
bool visited[1001];
vector<int> map[1001];

int cnt;

bool visited_check()
{
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false) return false;
	}
	return true;
}

void dfs(int index)
{
	visited[index] = true;
	
	for (int i = 0; i < map[index].size(); i++)
	{
		int y = map[index][i];
		
		if(visited[y] == false) dfs(y);
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		
		map[u].push_back(v);
		map[v].push_back(u);
	}
	for(int i = 1; i<=n; i++)
	{
		if(visited[i] == false)
		{
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}
