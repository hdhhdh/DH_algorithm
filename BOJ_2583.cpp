#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int xx, yy, k;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cnt;

vector<int> answer;

void bfs(int start_x, int start_y, vector<vector<int> >& map)
{
	if (map[start_x][start_y] == 1) return;

	queue<pair<int, int> > q;
	q.push(make_pair(start_x, start_y));
	map[start_x][start_y] = 1;
	cnt++;
	int value = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < xx && ny < yy && map[nx][ny] == 0)
			{
				value++;
				q.push(make_pair(nx, ny));
				map[nx][ny] = 1;
			}
		}
	}
	answer.push_back(value);
}

int main()
{
	cin >> xx >> yy >> k;

	vector<vector<int> > map(xx, vector<int>(yy));

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
		{
			for (int z = x1; z < x2; z++)
			{
				map[j][z] = 1;
			}
		}
	}

	for (int i = 0; i < xx; i++)
	{
		for (int j = 0; j < yy; j++)
		{
			bfs(i, j, map);
		}
	}

	sort(answer.begin(), answer.end());
	cout << cnt << endl;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}
	return 0;
}
