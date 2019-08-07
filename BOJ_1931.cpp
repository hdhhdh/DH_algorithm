#include <iostream>
#include <algorithm>
using namespace std;

int n;
int limit;
int cnt;
struct conference
{
	int start;
	int end;
}con;

struct conference a[100001];

bool compare(struct conference a, struct conference b)
{
	if(a.end == b.end) return a.start < b.start;
	return a.end < b.end;
} 

int main()
{
	cin >> n;
	
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i].start >> a[i].end;
	}
	
	sort(a, a+n+1, compare);
	
	for(int i = 1; i<=n; i++)
	{
		if(a[i].start >= limit)
		{
			cnt++;
			limit = a[i].end;
		}
	}
	
	cout << cnt;
	return 0;
	
}
