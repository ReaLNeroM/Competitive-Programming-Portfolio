#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 4e3 + 1e2;
const ll maxsum = 1e5 + 1e2;
ll n, m;
ll val[maxn];
std::vector<int> v[maxn];
ll dp[maxsum];

int main(){
    std::ios::sync_with_stdio(false);
    
    std::cin >> n;
    
    for(ll i = 0; i < n; i++){
        v[i].resize(3);
        std::cin >> v[i][1] >> v[i][0] >> v[i][2];
        v[i][2] *= -1;
    }
    
    std::cin >> m;
    
    for(ll i = 0; i < m; i++){
        v[n + i].resize(3);
        std::cin >> v[n + i][1] >> v[n + i][0] >> v[n + i][2];
        v[n + i][1] *= -1;
    }

    std::stable_sort(v, v + n + m, std::greater<std::vector<int>>());
    
    for(int i = n + m - 1; i >= 0; i--){
        if(v[i][2] < 0){
            for(int j = 0; j <= 100000; j++){               
                if(j + v[i][1] >= 0 and j + v[i][1] <= 100000){
                    dp[j] = std::max(dp[j], dp[j + v[i][1]] + v[i][2]);
                }
            }
        } else {
            for(int j = 100000; j >= 0; j--){
                if(j + v[i][1] >= 0 and j + v[i][1] <= 100000){
                    dp[j] = std::max(dp[j], dp[j + v[i][1]] + v[i][2]);
                }
            }
        }
    }    

    std::cout << dp[0] << '\n';
}
