#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<double, int> &a, const pair<double, int> &b)
{
    if(a.first == b.first)  return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> fa(N);
    vector<pair<double,int> > fail;
    
    sort(stages.begin(), stages.end());
    int cnt = 0;
    int person = stages.size();
    for(int i = 1; i<=N; i++)
    {
        for(int j = 0; j<stages.size(); j++)
        {
            if(i == stages[j])
            {
                fa[i-1]++;
            }
        }
        if(fa[i-1] == 0)
        {
            fail.push_back(make_pair(0, i));
            continue;
        }
        fail.push_back(make_pair((double)fa[i-1]/(double)person, i));
        person -= fa[i-1];
    }
    sort(fail.begin(), fail.end(), compare);
    for(int i = 0; i<N; i++)
    {
        answer.push_back(fail[i].second);
    }
    
    return answer;
}
