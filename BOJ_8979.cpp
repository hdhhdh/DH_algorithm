#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct country
{
	int index;
	int gold;
	int silver;
	int bronze;
};

bool cmp(struct country a, struct country b)
{
	if (a.gold == b.gold)
	{
		if (a.silver == b.silver)
		{
			return a.bronze > b.bronze;
		}
		else
		{
			return a.silver > b.silver;
		}
	}
	return a.gold > b.gold;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<struct country> v;
	for (int i = 0; i < N; i++)
	{
		struct country a;
		cin >> a.index >> a.gold >> a.silver >> a.bronze;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);

	int top_number = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].index == K)
		{
			top_number = i;
			break;
		}
	}
	int rank = 0;
	for (int i = top_number; i > 0; i--)
	{
		if (v[i].gold == v[i - 1].gold && v[i].silver == v[i - 1].silver && v[i].bronze == v[i - 1].bronze)
		{

		}
		else
		{
			rank = i;
			break;
		}
	}
	cout << rank + 1;
	return 0;
}
