#include <string>
#include <vector>
using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    dp[1][1] = 1;
    
    for(int i = 0; i<puddles.size(); i++)
    {
        int y = puddles[i][0];
        int x = puddles[i][1];
        dp[x][y] = -1;
    }
    
    
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(i == 1 && j == 1) continue;
            if(dp[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    answer = dp[n][m];
    
    return answer;
}
