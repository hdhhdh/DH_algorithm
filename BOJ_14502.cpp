//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int map[8][8];
//int cp[8][8];
//int n,m;
//
//int dx[4] = {-1, 1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//
//vector<int> answer;
//queue<pair<int, int> > q;
//vector<pair<int, int> > v;
//
//int wall_cnt;
//
//int count_safe()
//{
//	int safety_cnt = 0;
//
//	for(int i = 0; i<n; i++)
//	{
//		for(int j = 0; j<m; j++)
//		{
//			if(cp[i][j] == 0)
//			{
//				safety_cnt++;
//			}
//		}
//	}
//	return safety_cnt;
//}
//
//void dfs(int i, int j)
//{
//	for(int z = 0; z<4; z++)
//	{
//		int nx = i + dx[z];
//		int ny = j + dy[z];
//		
//		if(nx >= 0 && ny >= 0 && nx <= n-1 && ny <= m-1 && cp[nx][ny] == 0)
//		{
//			cp[nx][ny] = 2;
//			dfs(nx, ny);
//		}
//	}
//	return;
//}
//
//void infection()
//{	
////	while(!q.empty())
////	{
////		int id_x = q.front().first;
////		int id_y = q.front().second;
////		q.pop();
////		dfs(id_x, id_y);
////	}
//	for(int i = 0; i<v.size(); i++)
//	{
//		int id_x = v[i].first;
//		int id_y = v[i].second;
//		dfs(id_x, id_y);
//	}
//	
//	
//}
//
//void copy_map()
//{
//	for(int i = 0; i<n; i++)
//	{
//		for(int j = 0; j<m; j++)
//		{
//			cp[i][j] = map[i][j];
//		}
//	}
//}
//
//void make_wall(int cnt)
//{
//	if(cnt == 3)
//	{
//		copy_map();
//		infection();
//		int ans = count_safe();
//		answer.push_back(ans);
//		return;
//	}
//	
//	for(int i = 0; i<n; i++)
//	{
//		for(int j = 0; j<m; j++)
//		{
//			if(cp[i][j] ==0)
//			{
//				cp[i][j] = 1;
//				make_wall(cnt+1);
//				cp[i][j] = 0;
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	for(int i = 0; i<n; i++)
//	{
//		for(int j = 0; j<m; j++)
//		{
//			cin >> map[i][j];
//			if((map[i][j]) == 2)
//			{
//				q.push(make_pair(i, j));
//				v.push_back(make_pair(i, j));
//			}
//		}
//	}
//	
//	for(int i = 0; i<n; i++)
//	{
//		for(int j = 0; j<m; j++)
//		{
//			if(cp[i][j] == 0)
//			{
//				//copy_map();
//				cp[i][j] = 1;
//				make_wall(1);
//				cp[i][j] = 0;
//			}
//		}
//	}
//	
//	sort(answer.begin(), answer.end());
//	for(int i = 0; i<answer.size(); i++)
//	{
//		cout << answer[i] << '\n';
//	}
//	
//	int a = answer.back();
//	cout << a;
//	return 0;
//}




#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[8][8];
int cp[8][8];
int n,m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<int> answer;
vector<pair<int, int> > v;

int wall_cnt;

int count_safe()
{
	int safety_cnt = 0;

	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(cp[i][j] == 0)
			{
				safety_cnt++; //안전구역 count 
			}
		}
	}
	return safety_cnt;
}

void dfs(int i, int j) //바이러스 확산 과정 
{
	for(int z = 0; z<4; z++)
	{
		int nx = i + dx[z];
		int ny = j + dy[z];
		
		if(nx >= 0 && ny >= 0 && nx <= n-1 && ny <= m-1 && cp[nx][ny] == 0)
		{ //상 하 좌 우 index가 기존 size범위를 벗어나지 않고 0이면 확산시킨 후 확산된 위치에서 다시 확산
			cp[nx][ny] = 2;
			dfs(nx, ny);
		}
	}
	return;
}

void infection() //main에서 처음 바이러스 위치값들을 vector에 저장한것들을 확산 
{	
	for(int i = 0; i<v.size(); i++)
	{
		int id_x = v[i].first;
		int id_y = v[i].second;
		dfs(id_x, id_y);
	}
	return;
}

void copy_map()
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cp[i][j] = map[i][j];
		}
	}
}

void make_wall(int cnt)
{
	if(cnt == 3)
	{
		copy_map(); // 원본배열에서 작업 후 복사map에 copy 
		infection(); // 복사된 map을 이용하여 바이러스 확산검사 
		int ans = count_safe();
		answer.push_back(ans);
		return;
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(map[i][j] ==0)
			{
				map[i][j] = 1;
				make_wall(cnt+1);
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			cin >> map[i][j];
			if((map[i][j]) == 2)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}
	
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(cp[i][j] == 0)
			{
				map[i][j] = 1;
				make_wall(1);
				map[i][j] = 0;
			}
		}
	}
	
	sort(answer.begin(), answer.end()); //오름차순 정렬 
 
	int a = answer.back(); //맨 마지막(가장큰 원소 =  안전영역 최대값) 출력
	cout << a;
	return 0;
}
