#include <iostream>
#include <algorithm>

int dp[1000];
int arr[1000];
using namespace std;

int n;
int main()
{
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    for(int i = 0; i<n; i++)
    {
        if(dp[i] == 0) dp[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                if(dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
        }
    }
    sort(dp, dp + n);
    cout << dp[n-1];
    return 0;    
}
