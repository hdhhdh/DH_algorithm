#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> pq;
queue<pair<int, int> > q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    for(int i = 0; i<priorities.size(); i++)
    {
        pq.push(priorities[i]);
		q.push(make_pair(i, priorities[i]));
    }
    
    while(!pq.empty())
    {
        int index = q.front().first;
        int value = q.front().second;
        q.pop();
        if(pq.top() == value)
        {
            pq.pop();
            answer++;
            if(index == location) return answer;
        }
        {
            q.push(make_pair(index, value));
        }
    }
}
