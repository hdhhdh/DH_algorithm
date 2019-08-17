#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int cnt = 0;
    
    
    vector<int> arr;
    vector<int> cp_arr;
    
    dp[0][0] = triangle[0][0];
    int size = triangle.size();
    for(int i = 1; i<size; i++)
    {
        for(int j = 0; j<triangle[i].size(); j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(i == j)
            {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    for(int i = 0; i<size; i++)
    {
        answer = max(answer, dp[size-1][i]);
    }
    return answer;
}
