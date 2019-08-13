#include <string>
#include <vector>
using namespace std;

int solution(string name) {
    int answer_right = min(name[0] - 'A', 'Z' - name[0] + 1);
    int answer_left = answer_right;
    int size = name.size();
    
    bool A_test = true;
    
    for(int i = 1; i<size; i++)
    {
        bool A_test = true;
        
        for(int j = i; j<size; j++)
        {
            if(name[j] != 'A')
            {
                A_test = false;
                break;
            }
        }
        if(A_test) break;
        
        answer_right++;
        answer_right += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    for(int i = size-1; i>=1; i--)
    {
        bool A_test = true;
        
        for(int j = i; j>= 1; j--)
        {
            if(name[j] != 'A')
            {
                A_test = false;
                break;
            }
        }
        if(A_test) break;
        
        answer_left++;
        answer_left += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    return min(answer_right, answer_left);
}
