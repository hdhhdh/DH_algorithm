#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)        //a�� b�� 2���� ������� ���ļ� ū ���ڸ� ���� �� �ֵ��� return
{                                   //ex) a = 3, b = 34  a + b = 334, b + a = 343 -> 343�� �� ŭ
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i = 0; i<numbers.size(); i++)
    {
        v.push_back(to_string(numbers[i]));     //int�� string���� ��ȯ�ؼ� �ٽ� vector�� push
    }
    sort(v.begin(), v.end(), cmp);              //����
    for(int i = 0; i<v.size(); i++)
    {
        answer += v[i];
    }
    if(answer[0] == '0') return "0";    //ex) 0, 0 -> �׳� 0�� return
    return answer;
}
