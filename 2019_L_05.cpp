#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool visited[200000];

using namespace std;
int cnt = 0;
int main()
{
	int c = 0, b = 0;
	cin >> c >> b;

	queue<int> q;
	q.push(b);

	if (c == b)
	{
		cout << cnt;
		return 0;
	}

	int pop_value = 0;

	for (int i = 0; c <= 200000; i++)
	{
		c += i;				//�ڴ��� �̵��Ÿ�
		int size = q.size();				//���� ť�� �ִ°͸�ŭ ��� ����� �ٽ� �־�����ϹǷ�
		for (int j = 0; j < size; j++)
		{
			pop_value = q.front();
			q.pop();
			if (pop_value == c)
			{
				cout << cnt;
				return 0;
			}

			if (pop_value - 1 >= 0 && visited[pop_value - 1] == false)
			{
				q.push(pop_value - 1);
				visited[pop_value - 1] = true;
			}
			if (pop_value + 1 <= 200000 && visited[pop_value + 1] == false)
			{
				q.push(pop_value + 1);
				visited[pop_value + 1] = true;
			}
			if (pop_value * 2 <= 200000 && visited[pop_value * 2] == false)
			{
				q.push(pop_value * 2);
				visited[pop_value * 2] = true;
			}
		}
		cnt++;
	}

	cout << -1;
	return 0;
}
