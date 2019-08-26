#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int sum;
int main()
{
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	if(arr[0] != 1) cout << 1;
	else
	{
		int sum = 0;
		for(int i = 0; i<n; i++)
		{
			if(arr[i] > sum + 1) break;
			sum += arr[i];
		}
		cout << sum + 1;
	}	
	return 0;	
}
