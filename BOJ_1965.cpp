#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> box(n);
    
    for(int i = 0; i<n; i++)
    {
        cin >> box[i];
    }
    vector<int> answer;
    answer.push_back(box[0]);
    int index = 0;
    
    for(int i = 0; i<n; i++)
    {
        if(answer[index] < box[i])
        {
            index++;
            answer.push_back(box[i]);
            continue;
        }
        auto it = lower_bound(answer.begin(), answer.end(), box[i]);
        *it = box[i];
    }
    cout << answer.size();
    return 0;
}
