#include <iostream>
#include <string>

using namespace std;

string problem;

bool m = false;
int main()
{
	cin >> problem;
	int result = 0;

	string temp = "";

	for (int i = 0; i < problem.length() + 1; i++)
	{

		if (problem[i] == '+' || problem[i] == '-' || problem[i] == NULL)
		{
			if (m)
			{
				result -= stoi(temp);
			}
			else
			{
				result += stoi(temp);
			}
			temp = "";

			if (problem[i] == '-')
			{
				m = true;
			}
			continue;
		}
		temp += problem[i];
	}
	
	cout << result;
	return 0;
}
