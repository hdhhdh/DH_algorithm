#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;

    for(int i = 0 ; i<clothes.size(); i++)
    {
        m[clothes[i][clothes[i].size()-1]] += clothes[i].size() - 1;    //clothes의 마지막index가 의상의 종류이므로 의상의 종류를 key로 설정한 후 value에 의상의 이름 개수를 넣음
    }
    map<string, int> :: iterator it;    //map을 순회하기 위해 반복자 생성
    for(it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1);     //조합 경우의 수를 위해 의상의 종류 + 1한값을 answer에 곱하기
    }
    
    return answer - 1;  //아무것도 선택안한경우(1) 빼기
}
