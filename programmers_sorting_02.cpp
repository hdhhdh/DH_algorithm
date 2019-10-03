#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)        //a와 b를 2가지 방법으로 합쳐서 큰 숫자를 만들 수 있도록 return
{                                   //ex) a = 3, b = 34  a + b = 334, b + a = 343 -> 343가 더 큼
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i = 0; i<numbers.size(); i++)
    {
        v.push_back(to_string(numbers[i]));     //int를 string으로 변환해서 다시 vector에 push
    }
    sort(v.begin(), v.end(), cmp);              //정렬
    for(int i = 0; i<v.size(); i++)
    {
        answer += v[i];
    }
    if(answer[0] == '0') return "0";    //ex) 0, 0 -> 그냥 0만 return
    return answer;
}
