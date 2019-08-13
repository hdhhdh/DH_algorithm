#include <iostream>
using namespace std;

int room[55][55];
int n, m;
int x, y, nx, ny, d;
int cnt, check;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	cin >> n >> m;
	cin >> x >> y >> d;
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin >> room[i][j];
		}	
	}
	
	cnt = 1;
	
	while(1)
	{
		room[x][y] = 2;
		d = (d - 1 + 4) % 4;
		check++;
		
		nx = x + dx[d];
		ny = y + dy[d];
		
		
		if(nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if(room[nx][ny] == 0)
			{
				cnt++;
				x = nx;
				y = ny;
				check = 0;
				continue;
			}
			else if(room[nx][ny] != 0)
			{
				if(check >= 4)
				{
					if(d == 0)
					{
						nx = x + dx[2];
						ny = y + dy[2];
					}
					else if(d == 1)
					{
						nx = x + dx[3];
						ny = y + dy[3];
					}
					else if(d == 2)
					{
						nx = x + dx[0];
						ny = y + dy[0];
					}
					else
					{
						nx = x + dx[1];
						ny = y + dy[1];
					}
					
					if(nx < 0 || ny < 0 || nx >= n || ny >= m || room[nx][ny] == 1)
					{
						break;
					}
					else
					{
						x = nx;
						y = ny;
						check = 0;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;	
}
