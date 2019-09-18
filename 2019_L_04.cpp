#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> building_tall(N);
	for (int i = 0; i < N; i++)
	{
		cin >> building_tall[i];
	}
	vector<int> possible_b;
	for (int i = 0; i < N - 1; i++)
	{
		int tallest = building_tall[i] - 1;		//대소 비교하기 편해서 1뺌
		int semi_tallest = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (building_tall[i] == building_tall[j]) continue;

			if (building_tall[j] > building_tall[i])		//다음께 나보다 클때
			{
				if (building_tall[j] > tallest &&building_tall[i] > tallest)		//가장 큰것보다 크고 내가 가장큰것보다 커야함  ex) 뒤에 조건이 없으면 1(나) 2 1 3 일때 2를 무시하고 1 - 3이 가능함
				{
					possible_b.push_back(abs(i - j));
					tallest = building_tall[j];
				}
				continue;
			}
			if (building_tall[i] >= tallest)			//내가 제일 클때
			{
				if (building_tall[j] > semi_tallest)	//나보다 앞에있는것중 제일 큰것보다 커야지 막히지 않고 가능
				{
					possible_b.push_back(abs(i - j));
				}
				semi_tallest = max(semi_tallest, building_tall[j]);		//나보다 앞에있는것중 가장큰것 최신화
			}
		}
	}

	sort(possible_b.begin(), possible_b.end(), greater<int>());
	cout << possible_b[0];

	return 0;
}
