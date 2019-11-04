#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.push_back(0);
    for(int i = 1; i<heights.size(); i++)
    {
        bool check = true;
        for(int j = i - 1; j >= 0; j--)
        {
            if(heights[i] < heights[j])
            {
                check = false;
                answer.push_back(j+1);
                break;
            }
        }
        if(check) answer.push_back(0);
    }
    
    return answer;
}
