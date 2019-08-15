#include <string>
#include <vector>

using namespace std;
int cnt = 0;

void dfs(vector<int> &numbers, int target, int sum, int deep_idx)
{
    if(deep_idx >= numbers.size()) 
    {
        if(sum==target) cnt++;
        return;
    }
    
    dfs(numbers, target, sum + numbers[deep_idx], deep_idx+1);
    dfs(numbers, target, (sum + numbers[deep_idx]) * -1, deep_idx+1);
    
    return;
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, numbers[0], 1);
    dfs(numbers, target, numbers[0] * -1, 1);
    return cnt;
}
