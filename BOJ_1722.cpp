#include <iostream>
#include <vector>

using namespace std;

long long ary[21];
bool visited[21];

int main()
{
	int N;
	cin >> N;
	
	ary[0] = 1;
	for (int i = 1; i < 21; i++)
	{
		ary[i] = ary[i - 1] * i;
	}
	
	int in;
	cin >> in;

	if (in == 1)
	{
		long long k;
		cin >> k;
		vector<int> v(N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visited[j]) continue;
				if (ary[N - i - 1] < k)
				{
					k -= ary[N - i - 1];
				}
				else
				{
					v[i] = j;
					visited[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			cout << v[i] << ' ';
		}
		return 0;
	}
	else
	{
		vector<int> v(N);

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		long long cnt = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < v[i]; j++)
			{
				if (!visited[j]) cnt += ary[N - i - 1];
			}
			visited[v[i]] = true;
		}
		cout << cnt + 1;
		return 0;
	}
}
