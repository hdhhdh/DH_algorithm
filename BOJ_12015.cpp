#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000000];

int n;
int main()
{
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	vector<int> dp;
	dp.push_back(-1);
	for(int i = 0; i<n; i++)
	{
		if(dp.back() < arr[i])
		{
			dp.push_back(arr[i]);
		}
		else
		{
			auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
			*it = arr[i];
		}
	}
	
	cout << dp.size() - 1;
	return 0;
}
