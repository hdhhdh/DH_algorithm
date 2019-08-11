#include <iostream>
#include <queue>

using namespace std;
int n, k;
int cnt;

bool c[100001];

void bfs(int start, int arrive)
{
	queue<int> q;
	q.push(start);
	c[start] = true;

	while(!q.empty())
	{
		int size = q.size();
		for(int i = 0; i<size; i++)
		{
			int x = q.front();
			q.pop();
			
			if(x == arrive)
			{
				cout << cnt;
				return;
			}
	
			if(x> 0 && !c[x-1])
			{
				q.push(x-1);
				c[x-1] = true;
			}
			if(x < 100000 && !c[x+1])
			{
				q.push(x+1);
				c[x+1] = true;
			}
			if(2*x <= 100000 && !c[2*x])
			{
				q.push(2*x);
				c[2*x] = true;
			}
		}
		cnt ++;
	}
}

int main()
{
	cin >> n >> k;
	bfs(n, k);
	return 0;
}
