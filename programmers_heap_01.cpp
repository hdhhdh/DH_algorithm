#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i<scoville.size(); i++)
    {
        q.push(scoville[i]);
    }
    
    while(q.top() < K && q.size() > 1)
    {   
        int b1 = q.top();
        q.pop();        
        int b2 = q.top();
        q.pop();
        answer++;
        
        b1 = b1 + (2 * b2);        
        q.push(b1);
    }
    if(q.top() < K) return -1;
    
    return answer;
}
