#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int index = 0;
    int i = 0;
    for(i = people.size()-1; i>index; i--)
    {
        if(people[i] + people[index] <= limit)
        {
            index++;
            answer++;
        }
        else answer++;
    }
    if(i == index) answer++;
    return answer;
}
