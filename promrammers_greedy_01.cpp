#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    for(int i = 0; i<reserve.size(); i++)
    {
        for(int j = 0; j<lost.size(); j++)
        {
            if(reserve[i] == lost[j])
            {
                lost[j] = 99;
                reserve[i] = 99;
                answer++;
                break;
            }
        }
    }
    for(int i = 0; i<lost.size(); i++)
    {
        for(int j = 0; j<reserve.size(); j++)
        {
            if(lost[i] != 99 && reserve[j] != 99 && abs(reserve[j] - lost[i]) == 1)
            {
                reserve[j] = 99;
                answer++;
                break;
            }
        }
    }
    
    
    
    return answer;
}
