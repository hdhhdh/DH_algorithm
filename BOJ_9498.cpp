#include <iostream>

using namespace std;

int main()
{
    int grade = 0;
    cin >> grade;
    
    if(90 <= grade)
    {
        cout << 'A';
        return 0;
    }
    else if(80<=grade)
    {
        cout << 'B';
        return 0;
    }
    else if(70 <= grade)
    {
        cout << 'C';
        return 0;
    }
    else if(60 <= grade)
    {
        cout << 'D';
        return 0;
    }
    
    cout << 'F';
    return 0;
    
    
}
