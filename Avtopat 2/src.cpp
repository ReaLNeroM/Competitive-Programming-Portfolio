#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 35;
ll n, t;
ll val[maxn];
ll best = 0;

void dfs(ll pos, ll ups, ll sum){
    if(sum > t){
        return;
    }

    best = std::max(best, sum);

    if(pos + ups >= n - 1){
        return;
    }

    if(pos + ups + 1 < n - 1){
        dfs(pos + 1, ups + 1, sum + val[pos + ups] - val[pos] + val[pos + ups + 1] - val[pos]);
    }
    if(pos + ups < n - 1){
		dfs(pos + 1, ups    , sum + val[pos + ups] - val[pos]);
    }
    if(ups != 0){
		dfs(pos + 1, ups - 1, sum);
    }
} 

int main(){
    std::ios::sync_with_stdio(false);

    std::cin >> n >> t;

    ll start = 0;
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }

    std::sort(val, val + n);
 
    for(int i = 0; i < n - 1; i++){
        val[i + 1] -= val[0];
        val[i + 1] *= 2;
    }

    val[0] = 0;

    start = val[n - 1];
    t -= start;

    dfs(1, 0, 0);

    std::cout << start + best << '\n';
}
