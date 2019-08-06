#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
int N, M;
int cnt;
queue<int> q;
int way[101][101];

vector<int> a[101];
int c[101];

void bfs(int start)
{
	q.push(start);
	c[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		//cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			//cout << a[i].size() << endl;
			if (!c[y])
			{
				cnt++;
				if (y == (M + 1))
				{
					cnt++;
					return;
				}
				q.push(y);
				c[y] = true;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string temp;
        cin >> temp;
        for(int j = 1; j <= M; j++)
        {
        	way[i][j] = temp[j]-'0';
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (way[i][j] == 1)
			{
				if (way[i - 1][j]) a[(M*i) + j].push_back((M*(i - 1)) + j);
				if (way[i][j - 1]) a[(M*i) + j].push_back((M*i) + j - 1);
				if (way[i + 1][j]) a[(M*i) + j].push_back((M*(i + 1)) + j);
				if (way[i][j + 1]) a[(M*i) + j].push_back((M*i) + j + 1);
			}
		}
	}
	
	bfs((M*N) + M);
	cout << cnt << endl;
	return 0;

}
