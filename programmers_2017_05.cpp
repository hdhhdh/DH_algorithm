#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> subset1;
    vector<string> subset2;
    vector<string> out1;
    vector<string> out2;
    map<string, int> m1;
    map<string, int> m2;
    int hap = 0;
    int kyo = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    for(int i = 0; i < str1.size() - 1; i++)
    {
        string a = "";
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i+1] >= 'a' && str1[i+1] <= 'z' )
        {
            a += str1[i];
            a += str1[i+1];
            m1[a]++;
            subset1.push_back(a);
        }
    }
    
    for(int i = 0; i < str2.size() - 1; i++)
    {
        string a = "";
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i+1] >= 'a' && str2[i+1] <= 'z' )
        {
            a += str2[i];
            a += str2[i+1];
            m2[a]++;
            subset2.push_back(a);
        }
    }
    for(int i = 0; i<subset1.size(); i++)
    {
        for(int j = 0; j<subset2.size(); j++)
        {
            if(subset1[i] == subset2[j]) out1.push_back(subset1[i]);
        }
    }
    sort(out1.begin(), out1.end());
    for(int i = 0; i<out1.size(); i++)
    {
        string s = out1[i];
        kyo += min(m1[s], m2[s]);
        while(s == out1[i]) i++;
        i -=1;
    }
    
    for(int i = 0; i<subset1.size(); i++)
    {
        out2.push_back(subset1[i]);
    }
    for(int i = 0; i<subset2.size(); i++)
    {
        out2.push_back(subset2[i]);
    }
    
    sort(out2.begin(), out2.end());
    
    for(int i = 0; i<out2.size(); i++)
    {
        string s = out2[i];
        hap += max(m1[s], m2[s]);
        while(s == out2[i]) i++;
        i -= 1;
    }
    if(kyo == 0 & hap == 0) return 65536;
    double ans = (double)kyo/(double)hap;
    answer = ans * 65536;
    return answer;
}
