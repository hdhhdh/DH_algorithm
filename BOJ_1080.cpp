#include <iostream>
#include <stdio.h>
using namespace std;

int ary[50][50];
int trans_ary[50][50];

int n, m;
int cnt;
bool check = true;

void trans(int x, int y)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (ary[i][j] == 1) ary[i][j] = 0;
			else ary[i][j] = 1;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &ary[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &trans_ary[i][j]);
		}
	}

	for (int i = 0; i <= n - 3; i++)
	{
		for (int j = 0; j <= m - 3; j++)
		{
			if (ary[i][j] != trans_ary[i][j])
			{
				trans(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ary[i][j] != trans_ary[i][j]) check = false;
		}
	}
	if (check) printf("%d", cnt); 
	else printf("-1");
	return 0;

}
