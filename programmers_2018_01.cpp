#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<vector<string>> log(record.size(),vector<string>(3));
	map<string,string> user;
	
	for (int i = 0; i < record.size(); i++) {
		istringstream iss(record[i]);
		iss >> log[i][0];
		iss >> log[i][1];
		iss >> log[i][2];
		if (log[i][0]=="Enter" || log[i][0]=="Change"){
			user[log[i][1]]=log[i][2];
		}
	}
	for (int i = 0; i < log.size(); i++) {
		if (log[i][0] == "Enter") {
			answer.push_back(user[log[i][1]] + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
		}
		else if (log[i][0] == "Leave") {
			answer.push_back(user[log[i][1]] + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
	}
	return answer;
}
