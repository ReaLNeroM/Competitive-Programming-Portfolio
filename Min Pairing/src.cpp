#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    std::sort(val, val + n);
    
    
    for(int i = 0; i < n; i += 2){
        res += (ll) std::abs(val[i] - val[i + 1]);    
    }
    
    std::cout << res << std::endl;
}