#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int m[maxn][2];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        int sz;
        char side;
        std::cin >> sz >> side;
        
        m[sz][(side == 'L')]++;
        
    }
    
    for(int i = 0; i < 1000; i++){
        res += std::min(m[i][0], m[i][1]);
    }
    
    std::cout << res;
}