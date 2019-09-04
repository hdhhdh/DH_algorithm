#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int bfs_cnt;
int year_cnt;
int pre_x, pre_y;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void melt(vector<vector<int>> &arr, vector<vector<int>> fake)
{
	year_cnt++;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && fake[nx][ny] == 0)
			{
				if (arr[x][y] != 0) arr[x][y] -= 1;
			}
		}
	}
}

void check_mt(vector<vector<int>> arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] != 0) q.push(make_pair(i, j));
		}
	}
}
void bfs(vector<vector<int>> arr, int x, int y)
{
	queue<pair<int, int>> bfs_q;
	bfs_q.push(make_pair(x, y));
	arr[x][y] = 0;
	bfs_cnt++;
	while (!bfs_q.empty())
	{
		int xx = bfs_q.front().first;
		int yy = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && arr[nx][ny] != 0)
			{
				bfs_q.push(make_pair(nx, ny));
				arr[nx][ny] = 0;
				bfs_cnt++;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<int>> copy_arr(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (1)
	{
		check_mt(arr);
		while (!q.empty())
		{
			int first_x = q.front().first;
			int first_y = q.front().second;
			q.pop();
			copy_arr[first_x][first_y] = 1;
			pre_x = first_x;
			pre_y = first_y;
		}
		bfs(copy_arr, pre_x, pre_y);
		for (int i = 0; i < copy_arr.size(); i++)
		{
			fill(copy_arr[i].begin(), copy_arr[i].end(), 0);
		}
		check_mt(arr);
		if (q.empty() == 1 && year_cnt > 0)
		{
			cout << 0;
			return 0;
		}
		if (bfs_cnt != q.size())
		{
			cout << year_cnt;
			return 0;
		}
		vector<vector<int>> fake_arr(n, vector<int>(m, 0));
		fake_arr = arr;
		melt(arr, fake_arr);
		bfs_cnt = 0;
	}
	
	return 0;
}
