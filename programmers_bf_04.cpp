#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    int sum = brown + red;
    int w = 0, h = 0;
    for(int i = 1; i<= red/i; i++)
    {
        if(red % i == 0)
        {
            int w = red / i;
            
            if((w + 2) * (i + 2) == sum)
            {
                answer.push_back(w+2);
                answer.push_back(i+2);
                break;
            }
        }
    }
    
    return answer;
}
