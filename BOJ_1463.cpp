#include <iostream>
using namespace std;

int what_is_fast(int n, int* a)
{
    if(a[n]) return a[n];

    switch(n)
    {
        case 1:    a[n]=0;    break;
        case 2:
        case 3:
            a[n] = 1;
            break;
        default:
            if(!(n % 3)){
                a[n] = what_is_fast(n/3, a) + 1;
            }
            if (!(n % 2)){
                a[n] = !a[n]||(a[n] > what_is_fast(n/2, a) + 1) ? what_is_fast(n/2, a) + 1 : a[n];
            }
            a[n] = !a[n]||(a[n] > what_is_fast(n-1, a) + 1) ? what_is_fast(n-1, a) + 1 : a[n];
    }
    return a[n];
}
int main()
{
    int a[1000001] = {0};
    int n;
    cin >> n;
    
    cout << what_is_fast(n, a) << endl;
    
}
