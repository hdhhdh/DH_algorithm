#include <iostream>
#include <queue>

using namespace std;

int n, kim, lim;
int round_cnt = 1;

int main()
{
	cin >> n >> kim >> lim;

	queue<int> q1;
	queue<int> q2;

	bool q_num = false;

	for (int i = 1; i <= n; i++)
	{
		if (i == kim)
		{
			q1.push(2);
			continue;
		}
		if (i == lim)
		{
			q1.push(2);
			continue;
		}
		q1.push(1);
	}

	while (1)
	{
		if (q_num == false)
		{

			while (!q1.empty())
			{
				int x = q1.front();
				q1.pop();

				if (q1.empty())
				{
					q2.push(x);
					break;
				}

				int y = q1.front();
				q1.pop();

				if (x == 2)
				{
					if (y == 2)
					{
						cout << round_cnt;
						return 0;
					}
					q2.push(x);
					continue;
				}
				if (y == 2)
				{
					q2.push(y);
					continue;
				}
				if (y == 0)
				{
					q2.push(x);
					continue;
				}
				q2.push(x);
			}
			round_cnt++;
			q_num = true;
			continue;
		}
		else
		{
			while (!q2.empty())
			{
				int x = q2.front();
				q2.pop();
				if (q2.empty())
				{
					q1.push(x);
					break;
				}
				int y = q2.front();
				q2.pop();

				if (x == 2)
				{
					if (y == 2)
					{
						cout << round_cnt;
						return 0;
					}
					q1.push(x);
					continue;
				}
				if (y == 2)
				{
					q1.push(y);
					continue;
				}
				if (y == 0)
				{
					q1.push(x);
					continue;
				}
				q1.push(x);
			}
			round_cnt++;
			q_num = false;
			continue;
		}
	}
	return 0;
}
