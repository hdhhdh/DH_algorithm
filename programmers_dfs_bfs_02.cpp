#include <string>
#include <vector>
#include <queue>

using namespace std;
int visited[200];
int cnt = 0;

void dfs(int start, vector<vector<int>> &computers, int n)
{
    visited[start] = true;
    for(int i = 0; i<n; i++)
    {
        if(visited[i] == 0 && computers[start][i] == 1)
        {
            dfs(i ,computers,n);
        }   
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<n; i++)
    {
        if( visited[i] == 0)
        {
            answer++;
            dfs(i, computers, n);
        }
    }
    return answer;
}
