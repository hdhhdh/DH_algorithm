#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int index = 0;
int main()
{
	cin >> n;
	
	vector<int> arr(n);
	
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	vector<int> answer;
	answer.push_back(arr[0]);
	for(int i = 1; i<n; i++)
	{
		if(answer[index] < arr[i])
		{
			index++;
			answer.push_back(arr[i]);
			continue;
		}
		auto it = lower_bound(answer.begin(), answer.end(), arr[i]);
		*it = arr[i];	
	}
	
	cout << answer.size();
	
	return 0;
	
}
