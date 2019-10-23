#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[50];
int min_cnt = 1000000000;

void dfs(string b, string t, vector<string> words, int index, int cnt){
    
    visited[index] = true;  //재방문을 경우를 제외하기위해 visited 체크
    for(int i = 0; i<words.size(); i++)
    {
        if(visited[i]) continue;    //방문한곳이라면 다음경우로 넘김
        int same_cnt = 0;
        for(int j = 0; j<words[i].size(); j++)
        {
            if(b[j] == words[i][j]) same_cnt++;
        }
        if(same_cnt == b.size() - 1)    //solution함수 과정과 같음
        {
            if(t == words[i])   //바꿀단어(words[i])가 최종target 단어라면 변환과정 횟수비교 및 함수종료
            {
                min_cnt = min(min_cnt, cnt+1);
                return;
            }
            dfs(words[i], t, words, i, cnt+1);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool is_in = false;
    for(int i = 0 ;i<words.size(); i++) //target이 words에 있는지 검사
    {
        if(words[i] == target)
        {
            is_in = true;
        }
    }
    if(!is_in) return 0;    //없으면 return 0
    
    for(int i = 0 ;i<words.size(); i++)
    {
        int same_cnt = 0;
        for(int j = 0; j<words[i].size(); j++)
        {
            if(begin[j] == words[i][j]) same_cnt++; //begin과 words중 i번째 단어를 한자리씩 비교하며 같은위치 알파벳 개수 증가
        }
        if(same_cnt >= begin.size() - 1)    //같은위치 앞마벳 개수가 begin의 크기-1, 즉 한개의 알파벳만 다를경우
        {
            if(target == words[i])   //한번만에 처리되는경우 -> 이것을 처음에 생각못해서 테스트케이스 1,4번 틀림, 
            {
                return 1;
            }
            dfs(words[i], target, words, i, 1); //바꿀단어(words[i])로 dfs
            fill_n(visited, 50, false); //방문체크 배열 false로 초기화
        }
    }
    answer = min_cnt;
    return answer;
}
