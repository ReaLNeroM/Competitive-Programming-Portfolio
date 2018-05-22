#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 1005;
const int mod = 1000000007;
static int dp[maxn][maxn];
std::vector<int> deliteli[maxn];
int n, k;
 
int dpf(int pos, int prev){
    if(dp[pos][prev] == -1){
        int& ans = dp[pos][prev];
        ans = 0;
 
        if(pos == n){
            ans = 1;
        } else {
            for(int i = 0; i < deliteli[prev].size(); i++){
                ans = (ans + dpf(pos + 1, deliteli[prev][i])) % mod;
            }
        }
    }
 
    return dp[pos][prev];
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> n >> k;
 
    for(int i = 1; i <= k; i++){
        for(int j = i + i; j <= k; j += i){
            deliteli[j].push_back(i);
            deliteli[i].push_back(j);
        }
    }
 
    memset(dp, -1, sizeof(dp));
 
    int sum = 0;
    for(int i = 1; i <= k; i++){
        sum = (sum + dpf(1, i)) % mod;
    }
 
    std::cout << sum << '\n';
}