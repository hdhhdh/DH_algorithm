#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, bool> m;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int size = cities.size();
    for(int i = 0; i<size; i++) 
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    if(cacheSize == 0) return 5*size;
    
    vector<string> v;
    
    for(int i = 0; i<size; i++)
    {
        if(m[cities[i]] != true)
        {
            if(v.size() == cacheSize)
            {
                m[v[0]] = false;
                v.erase(v.begin());
            }
            v.push_back(cities[i]);
            m[cities[i]] = true;
            answer += 5;
        }
        else
        {
            v.erase(find(v.begin(), v.end(), cities[i]));
            v.push_back(cities[i]);
            answer += 1;
        }
    }
    
    return answer;
}
