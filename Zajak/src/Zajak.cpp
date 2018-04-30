#include <iostream>
 
typedef long long ll;
 
const long long INF = 1e9;

int main() {
    long long y, x;
    std::cin >> y >> x;
 
    long long val[y + 1][x], dp[y + 1][x];
 
    for(long long i = 0; i < y; i++){
        for(long long j = 0; j < x; j++){
            std::cin >> val[i][j];
            dp[i][j] = 0;
        }
    }
 
    for(long long i = 0; i < x; i++){
        dp[0][i] = dp[0][0] + val[0][i];
    }

    for(long long i = 1; i <= y - 1; i++){
        long long biggest[2], biggestpos[2];
        biggest[0] = biggest[1] = 0;
        biggestpos[0] = biggestpos[1] = 0;

        for(long long j = 0; j < x; j++){
            if(dp[i - 1][j] + val[i][j] >= biggest[0]){
                biggest[1] = biggest[0];
                biggestpos[1] = biggestpos[0];

                biggest[0] = dp[i - 1][j] + val[i][j];
                biggestpos[0] = j;
            } else if(dp[i - 1][j] + val[i][j] >= biggest[1]){
                biggest[1] = dp[i - 1][j] + val[i][j];
                biggestpos[1] = j;
            }
        }

        for(long long j = 0; j < x; j++){
            if(biggestpos[0] != j){
                dp[i][j] = biggest[0] + val[i][j];
            } else if(biggestpos[1] != j){
                dp[i][j] = biggest[1] + val[i][j];
            } else {
                dp[i][j] = -INF;
            }
        }
    }

    std::cout << dp[y - 1][x - 1];
    return 0;
}