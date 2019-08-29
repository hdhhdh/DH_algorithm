#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int m, n;
int day_cnt;

queue<pair<int, int> > q;

bool map_check()
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(box[i][j] == 0) return false;
		}
	}
	return true;
}

void bfs()
{	
	while(!q.empty())
	{
		int q_size = q.size();
		
		for(int i = 0; i<q_size; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for(int j = 0; j<4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx >=0 && ny >= 0 && nx < m && ny < n)
				{
					if(box[ny][nx] == 0)
					{
						box[ny][nx] = 1;
						q.push(make_pair(ny, nx));
					}
				}
			}
			
			if(q.size() == 0)
			{
				if(map_check() == false)
				{
					cout << -1;
					return;
				}
				cout << day_cnt;
				return;
			}
		}
		day_cnt++;
	}
}

int main()
{
	cin >> m >> n;
	bool zero_check = false;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin >> box[i][j];
			if(box[i][j] == 0) zero_check = true;
			if(box[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	if(zero_check == false)
	{
		cout << 0;
		return 0;
	}
	
	bfs();
	return 0;
}
