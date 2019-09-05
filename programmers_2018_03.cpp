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
    int x = countBits(a), y = countBits(b);         //���Ұ����� 1�� ������ ������ ����
    return x > y;
}
bool check(vector<vector<string>> relation, int rowsize, int colsize, int subset)
{
    for(int a = 0; a < rowsize - 1; a++)
    {
        for(int b = a + 1; b < rowsize; b++)                //Ʃ���� 2���� ¦�� ���´�
        {
            bool isSame = true;
            for(int k = 0; k < colsize; k++)
            {
                if((subset & 1 << k) == 0) continue;        //�κ����հ� bit�����Ͽ� 0�̶��(�ϳ��� ���� ������) continue
                if(relation[a][k] != relation[b][k])        //�ٸ���(���ϼ� ����) ��������
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame) return false;                        //���ϼ� ����x
        }
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowsize = relation.size();
    int colsize = relation[0].size();
    vector<int> candidates;
    
    for(int i=1; i< 1 << colsize; i++)              //i�� 0�϶��� �������̱⶧���� 1���� ����
    {
        if(check(relation, rowsize, colsize, i)) candidates.push_back(i);
    }
    sort(candidates.begin(), candidates.end(), compare);
    
    while(!candidates.empty())
    {
        int n = candidates.back();
        candidates.pop_back();                      //���� ���� �Ӽ��� ������ �̰����� ��
        answer++;
        for(int i = 0; i<candidates.size(); i++)
        {
            if((n & candidates[i]) == n)            //�ϳ��� �������� ������ �ּҼ� ���� x
            {
                candidates.erase(candidates.begin() + i);
                i = i-1;
            }
        }
        
    }
    
    return answer;
}
