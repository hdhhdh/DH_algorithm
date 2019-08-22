#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char map[21][21];
int step_cnt = 1;
int column, row;
bool visited[26];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int answer;

void dfs(int x, int y, int cnt)
{
	visited[map[x][y] - 65] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visited[map[nx][ny] - 65] != true && nx >= 1 && ny >= 1 && nx <= column && ny <= row)
		{
			dfs(nx, ny, cnt + 1);
			visited[map[nx][ny] - 65] = false;
		}
	}
	answer = max(answer, cnt);
}

int main()
{
	cin >> column >> row;

	for (int i = 1; i <= column; i++)
	{
		string a;
		cin >> a;
		for (int j = 1; j <= row; j++)
		{
			map[i][j] = a[j - 1];
		}
	}

	dfs(1, 1, step_cnt);

	cout << answer;
	return 0;
}
