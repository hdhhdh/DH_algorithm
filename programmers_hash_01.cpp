#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end(), greater<string>());
    sort(completion.begin(), completion.end(), greater<string>());
    for(int i = 0; i<participant.size(); i++)
    {
        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
