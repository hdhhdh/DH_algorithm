#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int countBits(int n)
{
    int ret = 0;
    while(n)
    {
        if(n & 1) ret++;
        n = n >> 1;
    }
    return ret;
}

bool compare(int a, int b)
{
    int x = countBits(a), y = countBits(b);         //원소개수가 1이 많은것 순으로 정렬
    return x > y;
}
bool check(vector<vector<string>> relation, int rowsize, int colsize, int subset)
{
    for(int a = 0; a < rowsize - 1; a++)
    {
        for(int b = a + 1; b < rowsize; b++)                //튜플을 2개씩 짝을 짓는다
        {
            bool isSame = true;
            for(int k = 0; k < colsize; k++)
            {
                if((subset & 1 << k) == 0) continue;        //부분집합과 bit연산하여 0이라면(하나도 같지 않으면) continue
                if(relation[a][k] != relation[b][k])        //다르면(유일성 만족) 다음으로
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame) return false;                        //유일성 만족x
        }
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowsize = relation.size();
    int colsize = relation[0].size();
    vector<int> candidates;
    
    for(int i=1; i< 1 << colsize; i++)              //i가 0일때는 공집합이기때문에 1부터 시작
    {
        if(check(relation, rowsize, colsize, i)) candidates.push_back(i);
    }
    sort(candidates.begin(), candidates.end(), compare);
    
    while(!candidates.empty())
    {
        int n = candidates.back();
        candidates.pop_back();                      //가장 작은 속성을 꺼내고 이것으로 비교
        answer++;
        for(int i = 0; i<candidates.size(); i++)
        {
            if((n & candidates[i]) == n)            //하나라도 같은것이 있으면 최소성 만족 x
            {
                candidates.erase(candidates.begin() + i);
                i = i-1;
            }
        }
        
    }
    
    return answer;
}
