#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int index = 0; index < commands.size(); index++)
	{
		int i = commands[index][0] - 1;     //�ε��� ��� ���ϰ� �ϱ����� -1����
		int j = commands[index][1] - 1;     //�ε��� ��� ���ϰ� �ϱ����� -1����
		int k = commands[index][2] - 1;     //�ε��� ��� ���ϰ� �ϱ����� -1����
		vector<int> v(j - i + 1);   //i���� j���� �ڸ��� �����ϱ����� �ʿ��� ũ�⸸ŭ �����Ҵ�
		copy(array.begin() + i, array.begin() + j + 1, v.begin());  //����
		sort(v.begin(), v.end());
		answer.push_back(v[k]);
	}
	return answer;
}
