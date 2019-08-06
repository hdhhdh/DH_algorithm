#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][3];

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i< N; i++)
    {
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
        if(i ==0) continue;
        dp[i][0] += min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0],dp[i-1][1]);
    }
    cout << min(dp[N-1][0],min(dp[N-1][1],dp[N-1][2])) << endl;
    return 0;
}
