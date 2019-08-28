#include <iostream>
#include <queue>
using namespace std;

int m, n, h;
int box[100][100][100];

typedef struct {
	int zz, yy, xx;
}tomato;

bool zero_check = true;

queue<tomato> q;

int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { 0, 0, 0, 0, -1, 1 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };

int day_cnt;

bool box_check()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if(box[i][j][k] == 0) return false;
			}
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
			int qx = q.front().xx;
			int qy = q.front().yy;
			int qz = q.front().zz;
			q.pop();
			
			for(int j = 0; j<6; j++)
			{
				int nx = qx + dx[j];
				int ny = qy + dy[j];
				int nz = qz + dz[j];
				
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < m && ny < n && nz < h && box[nz][ny][nx] == 0)
				{
					box[nz][ny][nx] = 1;
					q.push({ nz, ny, nx });
				}
			}			
			
			if(q.size() == 0)
			{
				if(box_check() == false)
				{
					cout << -1;
					return;
				}
				if(box_check() == true)
				{
					cout << day_cnt;
					return;
				}
			}
		}
		day_cnt++;
	}
}

int main()
{
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> box[i][j][k];
				if(box[i][j][k] == 0) zero_check = false;
				if (box[i][j][k] == 1) q.push({ i, j, k });
			}
		}
	}

	if(zero_check == true)
	{
		cout << 0;
		return 0;
	}
	bfs();

	return 0;
}
