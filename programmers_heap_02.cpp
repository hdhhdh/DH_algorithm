#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, less<int> > pq;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int d_cnt = 0;
    for(int i = 0; i<k; i++)
    {
        if(dates[d_cnt] == i)
        {
            pq.push(supplies[d_cnt]);
            if(d_cnt != supplies.size() - 1) d_cnt++;
        }
        
        if(stock == 0)
        {
            stock += pq.top();
            pq.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}
