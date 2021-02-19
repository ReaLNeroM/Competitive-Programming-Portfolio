#include <string>
#include <vector>
using namespace std;

class RoboAdvisor
{
  public:
    int calculateReturn(vector<int> appl, vector<int> tsla, vector<int> zm, vector<int> dividends){

    int p[20][4];
    for(int i = 0; i < 20; i++){
        p[i][1] = appl[i];
        p[i][2] = tsla[i];
        p[i][3] = zm[i];
    }
    int dp[21][4];
    for(int i = 20; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            dp[i][j] = 0;

            if(i == 20){
                continue;
            }

            if(j != 0 and i % 5 == 0 and i != 20){
                dp[i][j] = std::max(dp[i][j],
                    dp[i + 5][0] +
                    p[i][j] +
                    p[i + 1][j] +
                    p[i + 2][j] +
                    p[i + 3][j] +
                    p[i + 4][j] +
                    dividends[j - 1]);
            } else if(j == 0 and i % 5 == 0 and i != 2){
                for(int k = 1; k < 4; k++){
                    dp[i][j] = std::max(dp[i][j],
                        dp[i + 5][0] +
                        p[i][k] +
                        p[i + 1][k] +
                        p[i + 2][k] +
                        p[i + 3][k] +
                        p[i + 4][k] +
                        dividends[k - 1]);
                }
            }

            if(j == 0){
                dp[i][j] = std::max(dp[i][j], dp[i + 1][j]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][1] + p[i][1]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][2] + p[i][2]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][3] + p[i][3]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][0] + p[i][1]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][0] + p[i][2]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][0] + p[i][3]);
            } else {
                dp[i][j] = std::max(dp[i][j], dp[i + 1][j] + p[i][j]);
                dp[i][j] = std::max(dp[i][j], dp[i + 1][0] + p[i][j]);
            }
        }
    }
    return dp[0][0];
  }
};