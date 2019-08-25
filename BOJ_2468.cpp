#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
bool safety_map[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n;
int maximum_number;
int cnt;
int answer;

void bfs(int x, int y)
{
	if (safety_map[x][y] == true) return;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	cnt++;
	while (!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && safety_map[nx][ny] == false)
			{
				q.push(make_pair(nx, ny));
				safety_map[nx][ny] = true;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			maximum_number = max(maximum_number, map[i][j]);
		}
	}

	for (int i = 0; i <= maximum_number; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (map[j][k] <= i) safety_map[j][k] = true;
			}
		}

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				bfs(j, k);
			}
		}
		answer = max(answer, cnt);
		cnt = 0;
		memset(safety_map, false, sizeof(safety_map));

	}

	cout << answer;
	return 0;
}
