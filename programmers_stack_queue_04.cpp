#include <string>
#include <vector>
#include <queue>

using namespace std;

int queue_sum(queue<int> q)
{
    int sum = 0;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        sum += t;
    }
    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
        
    queue<int> q;
    for(int i = 0; i<bridge_length; i++)
    {
        q.push(0);
    }
    int truck_next = 0;
    while(1)
    {
        q.pop();
        int q_sum = queue_sum(q);
        if(q_sum + truck_weights[truck_next] <= weight)
        {
            q.push(truck_weights[truck_next]);
            truck_next++;
        }
        else
        {
            q.push(0);
        }
        
        answer++;
        if(truck_next == truck_weights.size())
        {
            return answer + bridge_length;
        }
    }
}
