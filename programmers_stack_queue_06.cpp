#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> copy_prices = prices;
    for(int i = 0; i<prices.size(); i++)
    {
        int time = 0;
        for(int j = i + 1; j<copy_prices.size(); j++)
        {
            if(prices[i] > copy_prices[j])
            {
                time = j - i;
                answer.push_back(time);
                break;
            }
        }
        if(time == 0) answer.push_back(prices.size() - (i + 1));
    }
    return answer;
}
