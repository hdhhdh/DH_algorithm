#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> map(n, vector<int>(n, 0));
    char zero = '0';
    char one = '1';
    string password;
    for(int i = 0; i<arr1.size(); i++)
    {
        stack<char> s;
        password = "";
        int number = arr1[i];
        for(int a = 0; a<n; a++)
        {
            if(number % 2 == 0)
            {
                s.push(zero);
            }
            else s.push(one);
            number /= 2;
        }
        
        int j = 0;
        while(!s.empty())
        {
            char t = s.top();
            map[i][j] += t - '0';
            s.pop();
            j++;
        }
    }
    for(int i = 0; i<arr2.size(); i++)
    {
        stack<char> s;
        password = "";
        int number = arr2[i];
        for(int a = 0; a<n; a++)
        {
            if(number % 2 == 0)
            {
                s.push(zero);
            }
            else s.push(one); 
            number /= 2;
        }
        int j = 0;
        while(!s.empty())
        {
            char t = s.top();
            map[i][j] += t - '0';
            s.pop();
            j++;
        }
    }
    
    for(int i = 0; i<n; i++)
    {
        string temp = "";
        for(int j = 0; j<map[0].size(); j++)
        {
            if(map[i][j] >0) temp += "#";
            else temp += " ";
        }
        answer.push_back(temp);
    }
    
    return answer;
}
