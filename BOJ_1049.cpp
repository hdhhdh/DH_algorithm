#include <iostream>
#include <algorithm>
using namespace std;
int N;
int M;
int sum;
int pack[50];
int nonpack[50];
int main()
{
	cin >> N >> M;
	
	for(int i = 0; i<M; i++)
	{
		cin >> pack[i] >> nonpack[i];
	}
	
	sort(pack, pack + M);
	sort(nonpack, nonpack + M);
	
	if(pack[0] < nonpack[0] * 6)
	{
		sum += N/6 * pack[0];
		N %= 6;
		if(N*nonpack[0] > pack[0])
		{
			sum += pack[0];
		}
		else
		{
			sum += nonpack[0] * N;
		}
	}
	else
	{
		sum = N * nonpack[0];
	}
	
	cout << sum;
	return 0;
}
