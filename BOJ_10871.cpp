#include <iostream>
using namespace std;

int main()
{
    int n, number;
    cin >> n >> number;
    for(int i = 0; i<n; i++)
    {
        int a;
        cin >> a;
        if(a < number) cout << a << ' ';
    }
    
    return 0;
}
