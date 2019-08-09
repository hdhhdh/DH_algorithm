#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long myeon[81] = {0};
    long long tail[81] = {0};
    tail[1] = 1;
    tail[2] = 1;
    for(int i = 3; i<=N; i++)
    {
        tail[i] = tail[i-1] + tail[i-2];
    }
    myeon[1] = 4;
    myeon[2] = 6;
    myeon[3] = 10;
    for(int i = 4; i<=N; i++)
    {
        myeon[i] = 2*(tail[i] + tail[i-2] + tail[i-3] + tail[i]); 
    }
    answer = myeon[N];
    return answer;
}
