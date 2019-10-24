#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;

bool dfs(string from, vector<vector<string>> &t, vector<bool> &v, int cnt){
    
    answer.push_back(from);
    for(int i = 0; i<t.size(); i++)
    {
        if(t[i][0] == from && v[i] == false)
        {
            v[i] = true;
            bool result = dfs(t[i][1], t, v, cnt+1);
            if(result) return true;
            else v[i] = false;
        }
    }
    if(cnt == t.size()) return true;

    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, visit, 0);
    
    return answer;
}
