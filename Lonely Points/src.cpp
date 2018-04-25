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
    
    ll biggest_dist = 0;
    
    for(int i = 0; i < n - 1; i++){
        biggest_dist = std::max(val[i + 1] - val[i]);    
    }
    
    for(int i)
}