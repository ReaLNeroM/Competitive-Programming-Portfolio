#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 10;
const int INF = 1e9;

std::string val;
int dp[maxn][maxn];
int foll[maxn][maxn];

int main(){
    std::ios::sync_with_stdio(false);

    int testCases;
    std::cin >> testCases;

    for(int testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        std::cin >> val;

        int n = val.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 15; j++){
                dp[i][j] = INF;
            }
        }

        dp[n][0] = 0;
        foll[n][0] = -1;

        for(int j = 1; j < 15; j++){
            dp[n][j] = j;
            foll[n][j] = 2;
        }

        for(int i = n - 1; i >= 0; i--){
            int d = (val[i] - '0');

            if(dp[i][d] > dp[i + 1][d]){
                dp[i][d] = dp[i + 1][d];
                foll[i][d] = 0;
            }

            for(int j = d - 1; j >= 0; j--){
                if(dp[i][j] > dp[i][j + 1] + 1){
                    dp[i][j] = dp[i][j + 1] + 1;
                    foll[i][j] = 1;
                }
            }
            for(int j = d + 1; j < 14; j++){
                if(dp[i][j] > dp[i][j - 1]){
                    dp[i][j] = dp[i][j - 1];
                    foll[i][j] = 2;
                }
            }
        }

        int curri = 0;
        int currj = 0;

        std::string res;
        while(curri != n or currj != 0){
            switch (foll[curri][currj]){
                case 0:
                    res += val[curri];
                    curri += 1;
                    break;
                case 1:
                    res += '(';
                    currj += 1;
                    break;
                case 2:
                    res += ')';
                    currj -= 1;
                    break;
            }
        }
        std::cout << res;

        std::cout << '\n';
    }
}