#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;

    for(int i = 0 ; i<clothes.size(); i++)
    {
        m[clothes[i][clothes[i].size()-1]] += clothes[i].size() - 1;    //clothes�� ������index�� �ǻ��� �����̹Ƿ� �ǻ��� ������ key�� ������ �� value�� �ǻ��� �̸� ������ ����
    }
    map<string, int> :: iterator it;    //map�� ��ȸ�ϱ� ���� �ݺ��� ����
    for(it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1);     //���� ����� ���� ���� �ǻ��� ���� + 1�Ѱ��� answer�� ���ϱ�
    }
    
    return answer - 1;  //�ƹ��͵� ���þ��Ѱ��(1) ����
}
