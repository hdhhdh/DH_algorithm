#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, apple_num, turn_cnt, second;
int pre_direction = 3;
queue<pair<int, char> > q;  //방향전환 정보 queue 
queue < pair<int, int > > snake;

int turn_right(int cur_d)
{
	q.pop();
	if (cur_d == 0) return 3; 		//북쪽으로 진행중 우회전 -> 동쪽 
	else if (cur_d == 1) return 2;  //남쪽으로 진행중 우회전 -> 서쪽
	else if (cur_d == 2) return 0;  //서쪽으로 진행중 우회전 -> 북쪽
	else if (cur_d == 3) return 1;  //동쪽으로 진행중 우회전 -> 남쪽
}
int turn_left(int cur_d)
{
	q.pop();
	if (cur_d == 0) return 2; 		//북쪽으로 진행중 좌회전 -> 서쪽
	else if (cur_d == 1) return 3;  //남쪽으로 진행중 좌회전 -> 동쪽
	else if (cur_d == 2) return 1;  //서쪽으로 진행중 좌회전 -> 남쪽
	else if (cur_d == 3) return 0;  //동쪽으로 진행중 좌회전 -> 북쪽
}

void solve(int x, int y)
{
	//북 = 0, 남 = 1, 서 = 2, 동 = 3 

	second = 0; //시작은 1초부터 시작 
	int direction = 3; // 첫 방향은 동쪽으로 진행 
	int nx = 0, ny = 0;
	map[x][y] = 1;
	snake.push(make_pair(x, y)); // 내 꼬리 snake queue에 push 
	while (1)
	{
		pre_direction = direction;

		if (!q.empty())	//queue가 비어있어 front값 못받음으로 조건문 생성
		{
			if (second == q.front().first)	//방향 정보시간과 현재 시간이 같다면 
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

		if (map[nx][ny] == 0) //다음움직일곳에 사과가 없다면 
		{
			map[snake.front().first][snake.front().second] = 0; //몸길이 줄여서 꼬리 위치한칸 비우기 
			snake.pop(); //꼬리 pop  
		}

		if (map[nx][ny] == 1 || nx <= 0 || ny <= 0 || nx > n || ny > n)
		{// 다음 움직일곳이 내 몸통이거나 범위를 벗어난다면 현재 second 출력 후 종료 
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
