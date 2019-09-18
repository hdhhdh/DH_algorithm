#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	long long N = 0;
	long long w = 0, h = 0;
	cin >> N;
	long long small = N + 1;

	for (long long i = 1; i < N / 2; i++)
	{
		if (N % i == 0)
		{
			w = i;
			h = N / i;
			small = min(small, abs(w - h));
		}
	}

	cout << small;
	return 0;
}
