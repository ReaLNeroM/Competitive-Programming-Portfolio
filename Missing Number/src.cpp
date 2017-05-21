#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 10000;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    std::fill(val, val + 10000, false);
    
    for(int i = 0; i < n; i++){
        int vv;
        std::cin >> vv;
        val[vv] = true;
    }
    
    for(int i = 1; i < 10000; i++){
        if(!val[i]){
            res = i;
            break;
        }
    }
    
    std::cout << res << std::endl;
}