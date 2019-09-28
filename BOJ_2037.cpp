#include <iostream>
#include <string>

using namespace std;

int alpha[26] = {
	2, 2, 2,
	3, 3, 3,
	4, 4, 4,
	5, 5, 5,
	6, 6, 6,
	7, 7, 7, 7,
	8, 8, 8,
	9, 9, 9, 9
};

int loop[26] = {
	1, 2, 3,
	1, 2, 3,
	1, 2, 3,
	1, 2, 3,
	1, 2, 3,
	1, 2, 3, 4,
	1, 2, 3,
	1, 2, 3, 4,
};

int main()
{
	int p, w;
	cin >> p >> w;
	cin.ignore();
	string temp = "";
	getline(cin, temp);

	int time;
	int pre;
	if (temp[0] == ' ')
	{
		pre = -1;
		time = p;
	}
	else
	{
		pre = alpha[temp[0] - 'A'];
		time = p * loop[temp[0] - 'A'];
	}
	for (int i = 1; i < temp.size(); i++)
	{
		if (temp[i] != ' ' && alpha[temp[i] - 'A'] == pre)
		{
			time += w;
			time += p * loop[temp[i] - 'A'];
		}
		else if (temp[i] == ' ')
		{
			time += p;
			pre = -1;
			continue;
		}
		else
		{
			time += p * loop[temp[i] - 'A'];
		}
		pre = alpha[temp[i] - 'A'];
	}
	cout << time;
	return 0;
}
