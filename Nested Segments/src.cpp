#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int l[maxn], r[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> l[i] >> r[i];
    }
    
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(l[j] < l[i] and r[i] < r[j]){
                res++;
                break;
            }    
        }
    }
    
    std::cout << res << '\n';
}