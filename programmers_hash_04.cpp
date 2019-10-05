#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
	return p1.second > p2.second;	//���Ƚ���� ���� ��������
}

struct compare {
	bool operator()(pair<int, int> const& a, pair<int, int> const& b) const
	{
		if (a.second == b.second)		//����ð��� ������
		{
			return a.first > b.first;		//index�� ���������
		}
		return a.second < b.second;			//����ð��� ū�����
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m1;		//���� �帣�� ���ȸ���� ������ map
	map < string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare>> m2;	//�����帣���� ����� ȸ���� �̾ ���� map, value�� �켱���� ť�� �������ν� compare ���ǿ� ���� Ƚ���� ������ index�� �������� ������ ���Բ�
																					//���� value������ vector�� ��������� �ߴµ� ������ sort�� �� ���� �ʾ� �켱���� ť�� ����
	for (int i = 0; i < plays.size(); i++)
	{
		m1[genres[i]] += plays[i];	//m1���� �帣�� ���Ƚ���� ����
		m2[genres[i]].push(make_pair(i, plays[i]));	//m2���� �帣�� index�� ���Ƚ���� push
	}

	vector<pair<string, int>> v;	//m1�� ����־� ���Ƚ���� ���� �����ϱ� ���� vector ����
	map<string, int>::iterator iter1;	//m1�� ��ȸ�ϱ� ���� �ݺ��� ����
	for (iter1 = m1.begin(); iter1 != m1.end(); iter1++)
	{
		v.push_back(make_pair(iter1->first, iter1->second));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		int j = 0;
		while (j != 2)	//�帣�� 2� �̱����� count j ����
		{
			answer.push_back(m2[v[i].first].top().first);
			m2[v[i].first].pop();
			if (m2[v[i].first].empty()) break;	//�帣�� ���� ���� 1�����(1���� pop�ߴµ� queue�� ���������) while�� Ż��
			j++;
		}
	}
	return answer;
}
int main()
{
	vector<string> g;
	g.push_back("classic");

	g.push_back("pop");
	g.push_back("classic");
	g.push_back("pop");
	g.push_back("classic");
	g.push_back("classic");

	vector<int> p;
	p.push_back(400);

	p.push_back(600);
	p.push_back(150);
	p.push_back(2500);
	p.push_back(500);
	p.push_back(500);
	vector<int> a = solution(g, p);

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ' ';
	}
	
	return 0;
}
