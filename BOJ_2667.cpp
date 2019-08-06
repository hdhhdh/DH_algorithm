#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
int v[25][25];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int cnt;
int n;
void dfs(int x, int y)
{
	for(int i = 0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
        if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1) continue;
		if(map[nx][ny] == 1 && !v[nx][ny])
		{
			v[nx][ny] = true;
			cnt++;
			dfs(nx, ny);
		}
	}
	
}


int main()
{
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	vector<int> a;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(map[i][j] == !v[i][j] )
			{
				v[i][j] = true;
				cnt++;
				dfs(i,j);
				a.push_back(cnt);
				cnt = 0;
			}
		}
	}
	
	sort(a.begin(), a.end());
	
	cout << a.size() << '\n';
	for(int i = 0; i<a.size(); i++)
	{
		cout << a[i] << '\n';
	}
	
	return 0;
	
}
