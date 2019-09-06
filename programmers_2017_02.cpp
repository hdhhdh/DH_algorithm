#include <string>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int pre_1 = -1;
    int pre_2 = -2;
    string num = "";
    vector<int> number;
    
    for(int i = 0; i<dartResult.size(); i++)
    {
        num = "";
        while(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            num += dartResult[i];
            i++;
        }
        
        switch(dartResult[i])
        {
            case 'S': number.push_back(stoi(num)); pre_1++; pre_2++; break;
            case 'D': number.push_back(stoi(num) * stoi(num)); pre_1++; pre_2++; break;
            case 'T': number.push_back(stoi(num) * stoi(num) * stoi(num)); pre_1++; pre_2++; break;
            case '*': 
                if(pre_1 < 0)
                {
                    number[0] = number[0] * 2;
                    break;
                }
                else{
                    number[pre_1] = number[pre_1] * 2;
                    number[pre_2] = number[pre_2] * 2;
                    break;
                }
            case '#': number[pre_1] = number[pre_1] * -1; break;
        }
    }
    for(int i = 0; i<number.size(); i++)
    {
        answer += number[i];
    }
    return answer;
}
