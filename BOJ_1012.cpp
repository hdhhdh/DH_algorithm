#include <iostream>
#include <cstring>
using namespace std;

int xy[50][50];
int visited[50][50];

int nx[4] = {0, 0, -1, 1};
int ny[4] = {-1, 1, 0, 0};

int t;
int x_n, y_n, n;
int x,y;
int cnt;

void is_near(int origin_x, int origin_y)
{
	for(int i = 0; i<4; i++)
	{
		int cx = origin_x + nx[i];
		int cy = origin_y + ny[i];
		
		if(cx < 0 || cy < 0 || cx > x_n - 1 || cy > y_n -1) continue;
		if(visited[cx][cy] == 0 && xy[cx][cy] == true)
		{
			visited[cx][cy] = true;
			is_near(cx,cy);
		}
	}
	return;
}

void dfs()
{
	for(int i = 0; i<x_n; i++)
	{
		for(int j = 0; j<y_n; j++)
		{
			if(xy[i][j] == 0 || visited[i][j] == 1) continue;
			visited[i][j] = true;
			cnt++;
			is_near(i,j);
		}
	}
	cout << cnt << '\n';
	cnt = 0;
	memset(visited,0,sizeof(visited));
	memset(xy, 0, sizeof(xy));
	return;
}

int main()
{
	cin >> t;
	
	for(int i = 0; i<t; i++)
	{
		cin >> x_n >> y_n >> n;
		for(int j = 0; j<n; j++)
		{
			cin >> x >> y;
			xy[x][y] = true;
		}
		dfs();
	}
	return 0;
}
