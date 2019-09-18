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
		int tallest = building_tall[i] - 1;		//��� ���ϱ� ���ؼ� 1��
		int semi_tallest = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (building_tall[i] == building_tall[j]) continue;

			if (building_tall[j] > building_tall[i])		//������ ������ Ŭ��
			{
				if (building_tall[j] > tallest &&building_tall[i] > tallest)		//���� ū�ͺ��� ũ�� ���� ����ū�ͺ��� Ŀ����  ex) �ڿ� ������ ������ 1(��) 2 1 3 �϶� 2�� �����ϰ� 1 - 3�� ������
				{
					possible_b.push_back(abs(i - j));
					tallest = building_tall[j];
				}
				continue;
			}
			if (building_tall[i] >= tallest)			//���� ���� Ŭ��
			{
				if (building_tall[j] > semi_tallest)	//������ �տ��ִ°��� ���� ū�ͺ��� Ŀ���� ������ �ʰ� ����
				{
					possible_b.push_back(abs(i - j));
				}
				semi_tallest = max(semi_tallest, building_tall[j]);		//������ �տ��ִ°��� ����ū�� �ֽ�ȭ
			}
		}
	}

	sort(possible_b.begin(), possible_b.end(), greater<int>());
	cout << possible_b[0];

	return 0;
}
