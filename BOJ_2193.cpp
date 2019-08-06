#include <iostream>
using namespace std;

int main()
{
    long dp[91] = {0};
    int n;
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 1;
    
    if(n>=3)
    {
        for(int i = 3; i<= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}
