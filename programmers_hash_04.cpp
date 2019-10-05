#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
	return p1.second > p2.second;	//재생횟수에 따라 오름차순
}

struct compare {
	bool operator()(pair<int, int> const& a, pair<int, int> const& b) const
	{
		if (a.second == b.second)		//재생시간이 같으면
		{
			return a.first > b.first;		//index가 작은놈부터
		}
		return a.second < b.second;			//재생시간이 큰놈부터
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m1;		//음악 장르와 재생회수를 축적할 map
	map < string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare>> m2;	//음악장르마다 재생된 회수를 이어서 붙힐 map, value를 우선순위 큐로 만듬으로써 compare 조건에 따라 횟수가 같으면 index가 작은놈이 앞으로 오게끔
																					//원래 value값으로 vector를 집어넣을려 했는데 구현중 sort가 잘 되지 않아 우선순위 큐로 구현
	for (int i = 0; i < plays.size(); i++)
	{
		m1[genres[i]] += plays[i];	//m1에는 장르별 재생횟수를 적립
		m2[genres[i]].push(make_pair(i, plays[i]));	//m2에는 장르별 index와 재생횟수를 push
	}

	vector<pair<string, int>> v;	//m1을 집어넣어 재생횟수에 따라 정렬하기 위해 vector 생성
	map<string, int>::iterator iter1;	//m1을 순회하기 위한 반복자 생성
	for (iter1 = m1.begin(); iter1 != m1.end(); iter1++)
	{
		v.push_back(make_pair(iter1->first, iter1->second));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		int j = 0;
		while (j != 2)	//장르별 2곡씩 뽑기위해 count j 조건
		{
			answer.push_back(m2[v[i].first].top().first);
			m2[v[i].first].pop();
			if (m2[v[i].first].empty()) break;	//장르에 속한 곡이 1개라면(1개만 pop했는데 queue가 비어있을떄) while문 탈출
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
