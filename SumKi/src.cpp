#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll res[maxn];
std::map<ll, ll> fresh;
 
void dfs(int pos, int left, ll filled){
    if(left == 0){
        fresh[filled]++;
        return;
    } else if(pos == 0){
        fresh[filled + left * res[pos]]++;
        return;
    }
 
    for(int i = 0; i <= left; i++){
        dfs(pos - 1, left - i, filled + i * res[pos]);
    }
}
 
int main(){
    std::ios::sync_with_stdio(false);
 
    ll n, k;
    std::cin >> n >> k;
 
    ll value, size = 0;
    while(std::cin >> value){
        val[size] = value;
        size++;
    }
    std::sort(val, val + size);
 
    ll res_pos = 1;
    res[0] = val[0] / k;
 
    for(int i = 1; i < size; i++){
        if(fresh[val[i]] == 0){
            fresh[val[i]]--;
            res[res_pos] = val[i] - res[0] * (k - 1);
            res_pos++;
 
            for(int j = 1; j <= k; j++){
                dfs(res_pos - 2, k - j, res[res_pos - 1] * j);
            }
        } else {
            fresh[val[i]]--;
        }
    }
 
    for(int i = 0; i < n; i++){
        std::cout << res[i] << ' ';
    }
}