#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[50];
int min_cnt = 1000000000;

void dfs(string b, string t, vector<string> words, int index, int cnt){
    
    visited[index] = true;  //��湮�� ��츦 �����ϱ����� visited üũ
    for(int i = 0; i<words.size(); i++)
    {
        if(visited[i]) continue;    //�湮�Ѱ��̶�� �������� �ѱ�
        int same_cnt = 0;
        for(int j = 0; j<words[i].size(); j++)
        {
            if(b[j] == words[i][j]) same_cnt++;
        }
        if(same_cnt == b.size() - 1)    //solution�Լ� ������ ����
        {
            if(t == words[i])   //�ٲܴܾ�(words[i])�� ����target �ܾ��� ��ȯ���� Ƚ���� �� �Լ�����
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
    for(int i = 0 ;i<words.size(); i++) //target�� words�� �ִ��� �˻�
    {
        if(words[i] == target)
        {
            is_in = true;
        }
    }
    if(!is_in) return 0;    //������ return 0
    
    for(int i = 0 ;i<words.size(); i++)
    {
        int same_cnt = 0;
        for(int j = 0; j<words[i].size(); j++)
        {
            if(begin[j] == words[i][j]) same_cnt++; //begin�� words�� i��° �ܾ ���ڸ��� ���ϸ� ������ġ ���ĺ� ���� ����
        }
        if(same_cnt >= begin.size() - 1)    //������ġ �ո��� ������ begin�� ũ��-1, �� �Ѱ��� ���ĺ��� �ٸ����
        {
            if(target == words[i])   //�ѹ����� ó���Ǵ°�� -> �̰��� ó���� �������ؼ� �׽�Ʈ���̽� 1,4�� Ʋ��, 
            {
                return 1;
            }
            dfs(words[i], target, words, i, 1); //�ٲܴܾ�(words[i])�� dfs
            fill_n(visited, 50, false); //�湮üũ �迭 false�� �ʱ�ȭ
        }
    }
    answer = min_cnt;
    return answer;
}
