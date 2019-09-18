#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "";
	cin >> s;
	int len = s.size();
	int char_cnt = 0, num_cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			char_cnt++;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') continue;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i] == '0' && s[i - 1] == '1') continue;
			num_cnt++;
		}
	}
	if (char_cnt != num_cnt)
	{
		cout << "error";
		return 0;
	}
	string copy_s = "";
	//num_cnt 는 즉 숫자가 시작되는 index
	for (int i = 0; i < num_cnt; i++)
	{
		copy_s += s[i];
		if (s[i + char_cnt] == '1')
		{
			if (s[i + char_cnt + 1] == '0')
			{
				copy_s += s[i + char_cnt];
				copy_s += s[i + char_cnt + 1];
				char_cnt++;
			}
			continue;
		}
		copy_s += s[i + char_cnt];	
	}
	cout << copy_s;

	return 0;
}
