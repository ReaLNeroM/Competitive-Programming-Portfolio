#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll INF = 1000000000000000010;

int val[maxn];
int dp[1001][1001];
int div[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    memset(div, -1, sizeof(maxn));
    for(int i = 2; i < maxn; i++){
        if(div[i] == -1){
            div[i] = i;
            if(i > 2000){
                continue;
            }
            for(int j = i * i; j < maxn; j += i){
                div[j] = i;
            }
        }
    }

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n;
        std::cin >> n;

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 or j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                for(int k = )
                if(i != 0 and j != 0){
                    dp[i][j] = dp[i - j][j]
                }
            }
        }
        //TODO

        std::cout << '\n';
    }
}