#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    int xxor = 0;
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
        xxor ^= val[i];
    }
    
    if(xxor != 0){
        res = n;
    }
    
    for(int i = 0; i < n; i++){
        if((xxor ^ val[i]) != 0){
            res = std::max(res, std::max(n - i - 1, i));
        }
    }
    
    std::cout << res;
}