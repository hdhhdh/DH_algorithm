#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;
    int real_size = food_times.size();
	int size = food_times.size();
	vector<pair<int, int> > with_index;
	for (int i = 0; i < real_size; i++)
	{
		with_index.push_back(make_pair(i + 1, food_times[i]));
	}
	sort(with_index.begin(), with_index.end(), compare);
	int index = 0;
    
    while(1)
    {
        if(k >= (long long)with_index[index].second * (long long)size)
        {
            k -= (long long)with_index[index].second * (long long)size;
            int value = with_index[index].second;
            for(int i = index; i<real_size; i++)
            {
                with_index[i].second -= value;
            }
            index++;
            if(index >= real_size) return -1;       //�þ� ���Ұ� 1�� �ִµ� k���� ������� ����ó��
            while(with_index[index].second == 0)
            {
                index++;
                if(index == real_size)      //���̻� �������� ���� ���ܻ���
                {
                    return -1;
                }
            }
            size = real_size - index;
        }
        else break;
    }
    vector<int> order_index;
    for(int i = index; i<real_size; i++)                
    {
        order_index.push_back(with_index[i].first);         //���� ���ĵ鳢�� index������ ����
    }
    sort(order_index.begin(), order_index.end());
    return order_index[k%(long long)size];
}
