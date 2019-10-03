#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int index = 0; index < commands.size(); index++)
	{
		int i = commands[index][0] - 1;     //인덱스 계산 편하게 하기위해 -1해줌
		int j = commands[index][1] - 1;     //인덱스 계산 편하게 하기위해 -1해줌
		int k = commands[index][2] - 1;     //인덱스 계산 편하게 하기위해 -1해줌
		vector<int> v(j - i + 1);   //i부터 j까지 자르고 복사하기위해 필요한 크기만큼 동적할당
		copy(array.begin() + i, array.begin() + j + 1, v.begin());  //복사
		sort(v.begin(), v.end());
		answer.push_back(v[k]);
	}
	return answer;
}
