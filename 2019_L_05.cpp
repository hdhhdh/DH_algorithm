#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool visited[200000][2];

using namespace std;
int cnt = 0;
int main()
{
	int c = 0, b = 0;
	cin >> c >> b;

	queue<pair<int, int>> q;
	q.push(make_pair(b, 0));

	if (c == b)
	{
		cout << cnt;
		return 0;
	}

	int pop_value = 0;

	for (int i = 0; c <= 200000; i++)
	{
		c += i;				//코니의 이동거리
		int size = q.size();				//현재 큐에 있는것만큼 결과 계산후 다시 넣어줘야하므로
		for (int j = 0; j < size; j++)
		{
			pop_value = q.front().first;
			int new_time = (q.front().second + 1) % 2;
			int new_value;

			q.pop();
			
			
			if (visited[c][cnt % 2])
			{
				cout << cnt;
				return 0;
			}

			new_value = pop_value - 1;

			if (new_value >= 0 && visited[new_value][new_time] == false)
			{
				visited[new_value][new_time] = true;
				q.push(make_pair(new_value, new_time));
			}

			new_value = pop_value + 1;

			if (new_value <= 200000 && visited[new_value][new_time] == false)
			{
				visited[new_value][new_time] = true;
				q.push(make_pair(new_value, new_time));
			}

			new_value = pop_value * 2;
			if (new_value <= 200000 && visited[new_value][new_time] == false)
			{
				visited[new_value][new_time] = true;
				q.push(make_pair(new_value, new_time));
			}
		}
		cnt++;
	}

	cout << -1;
	return 0;
}
