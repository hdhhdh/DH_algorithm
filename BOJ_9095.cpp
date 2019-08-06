#include <iostream>
using namespace std;
int dp[12];

int solve(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    else
    {
        dp[n] = solve(n-1) + solve(n-2) + solve(n-3);
    }
    
    
    return dp[n];
}

int main()
{
    int a, n, p;
    cin >> n;
    while(n--)
    {
        cin >> a;
        p = solve(a);
        cout << p << endl;
    }
    return 0;
}
