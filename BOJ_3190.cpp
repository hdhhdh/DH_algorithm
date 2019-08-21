#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, apple_num, turn_cnt, second;
int pre_direction = 3;
queue<pair<int, char> > q;  //������ȯ ���� queue 
queue < pair<int, int > > snake;

int turn_right(int cur_d)
{
	q.pop();
	if (cur_d == 0) return 3; 		//�������� ������ ��ȸ�� -> ���� 
	else if (cur_d == 1) return 2;  //�������� ������ ��ȸ�� -> ����
	else if (cur_d == 2) return 0;  //�������� ������ ��ȸ�� -> ����
	else if (cur_d == 3) return 1;  //�������� ������ ��ȸ�� -> ����
}
int turn_left(int cur_d)
{
	q.pop();
	if (cur_d == 0) return 2; 		//�������� ������ ��ȸ�� -> ����
	else if (cur_d == 1) return 3;  //�������� ������ ��ȸ�� -> ����
	else if (cur_d == 2) return 1;  //�������� ������ ��ȸ�� -> ����
	else if (cur_d == 3) return 0;  //�������� ������ ��ȸ�� -> ����
}

void solve(int x, int y)
{
	//�� = 0, �� = 1, �� = 2, �� = 3 

	second = 0; //������ 1�ʺ��� ���� 
	int direction = 3; // ù ������ �������� ���� 
	int nx = 0, ny = 0;
	map[x][y] = 1;
	snake.push(make_pair(x, y)); // �� ���� snake queue�� push 
	while (1)
	{
		pre_direction = direction;

		if (!q.empty())	//queue�� ����־� front�� ���������� ���ǹ� ����
		{
			if (second == q.front().first)	//���� �����ð��� ���� �ð��� ���ٸ� 
			{
				if (q.front().second == 'D')
				{
					direction = turn_right(direction);
				}
				else if (q.front().second == 'L')
				{
					direction = turn_left(direction);
				}
			}
		}

		nx = x + dx[direction];
		ny = y + dy[direction];

		if (map[nx][ny] == 0) //���������ϰ��� ����� ���ٸ� 
		{
			map[snake.front().first][snake.front().second] = 0; //������ �ٿ��� ���� ��ġ��ĭ ���� 
			snake.pop(); //���� pop  
		}

		if (map[nx][ny] == 1 || nx <= 0 || ny <= 0 || nx > n || ny > n)
		{// ���� �����ϰ��� �� �����̰ų� ������ ����ٸ� ���� second ��� �� ���� 
			second++;
			cout << second;
			return;
		}

		map[nx][ny] = 1;
		snake.push(make_pair(nx, ny));
		
		x = nx;
		y = ny;
		second++;
	}
}

int main()
{
	cin >> n >> apple_num;
	for (int i = 0; i < apple_num; i++)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;
		map[x][y] = 2;
	}
	cin >> turn_cnt;

	for (int i = 0; i < turn_cnt; i++)
	{
		int t = 0;
		char d = 0;
		cin >> t >> d;
		q.push(make_pair(t, d));
	}
	solve(1, 1);
	return 0;
}
