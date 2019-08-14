#include <iostream>
int a[13];
int visited[13];

using namespace std;

int k;
int cnt;
void dfs(int v, int cnt)
{
	if(k == v && cnt == 6)
	{
		for(int i = 0; i<k; i++)
		{
			if(visited[i] == 1) cout << a[i] << ' ';
		}
		cout << '\n';
	}
	if(k == v) return;
	
	visited[v] = true;
	dfs(v+1, cnt + 1);
	visited[v] = 0;
	dfs(v+1, cnt);	
}

int main()
{
	while(1)
	{
		cin >> k;
		if(k == 0) break;
	 
		
		for(int i = 0; i<k; i++)
		{
			cin >> a[i];
		}
		
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}
