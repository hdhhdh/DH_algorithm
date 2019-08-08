#include <iostream>
using namespace std;
long long  dp[31][31];
int T;

long long combination(int a , int b)
{
	if( a == b || b == 0) return 1;
	if(dp[a][b]) return dp[a][b];
	return dp[a][b] = combination(a-1, b-1) + combination(a-1,b );

}

int main()
{
	cin >> T;
	for(int i = 0; i<T;i++)
	{
		int N= 0, M=0;
		cin >> N >> M;
		cout << combination(M, N) << '\n';
	}
	return 0;
}
