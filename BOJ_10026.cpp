#include <iostream>
#include <queue>
using namespace std;

char color;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char map[100][100];
char r_g_map[100][100];
int normal_cnt;
char pre_color;
int r_g_cnt;
int n;

void bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	pre_color = map[x][y];
	map[x][y] = 0;
	
	while(!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		
		for(int i = 0; i<4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if(nx >= 0 && ny >= 0 && nx<n && ny<n && map[nx][ny] != 0)
			{
				if(map[nx][ny] == pre_color)
				{
					q.push(make_pair(nx, ny));
					map[nx][ny] = 0;
				}
			}
		}
	}
}

void r_g_bfs(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	pre_color = r_g_map[x][y];
	r_g_map[x][y] = 0;
	
	while(!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		
		for(int i = 0; i<4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			
			if(nx >= 0 && ny >= 0 && nx<n && ny<n && r_g_map[nx][ny] != 0)
			{
				if(r_g_map[nx][ny] == pre_color)
				{
					q.push(make_pair(nx, ny));
					r_g_map[nx][ny] = 0;
				}
				else if(r_g_map[nx][ny] == 'G' && pre_color == 'R')
				{
					q.push(make_pair(nx, ny));
					r_g_map[nx][ny] = 0;
				}
				else if(r_g_map[nx][ny] == 'R' && pre_color == 'G')
				{
					q.push(make_pair(nx, ny));
					r_g_map[nx][ny] = 0;
				}
			}
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
			cin >> color;
			map[i][j] = color;
			r_g_map[i][j] = color;
		}
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(map[i][j] != 0)
			{
				bfs(i,j);
				normal_cnt++;
			}
		}
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(r_g_map[i][j] != 0)
			{
				r_g_bfs(i, j);
				r_g_cnt++;
			}
		}
	}
	
	cout << normal_cnt << ' ' << r_g_cnt;
	return 0;
}
