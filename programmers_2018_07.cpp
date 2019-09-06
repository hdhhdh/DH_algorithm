#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> Board;
bool Canfill(int row, int col)
{
    for(int i = 0; i<row; i++)
    {
        if(Board[i][col] != 0) return false;
    }
    return true;
}

bool find(int row, int col, int h, int w)
{
    int empty_cnt = 0;
    int lastvalue = -1;
    
    for(int r = row; r<row + h; r++)
    {
        for(int c = col; c<col + w; c++)
        {
            if(Board[r][c] == 0)
            {
                if(!Canfill(r, c))  return false;
                empty_cnt++;
                if(empty_cnt > 2) return false;
            }
            else
            {
                if(lastvalue != -1 && lastvalue != Board[r][c]) return false;
                lastvalue = Board[r][c];
            }
        }
    }
    for(int r = row; r<row + h; r++)
    {
        for(int c = col; c<col + w; c++)
        {
            Board[r][c] = 0;
        }
    }
    
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    Board = board;
    N = board.size();
    int cnt;
    do
    {
        cnt = 0;
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<N; j++)
            {
                if(i <= N-2 && j<= N-3 && find(i, j, 2, 3) == true)
                {
                    cnt++;
                }
                else if(i <= N-3 && j<= N-2 && find(i, j, 3, 2) == true)
                {
                    cnt++;
                }
            }
        }
        answer += cnt;
        
    }while(cnt);
    return answer;
}
