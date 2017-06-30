#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int res[maxn];
int length[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    int l = 0, r = 0;
    int must_l = 0;
    while(must_l < n){
        if(r < must_l){
            r = l = must_l;
        }
        while(r < n - 1 and val[r] > val[r + 1]){
            r++;
        }
        
        std::cout << r - l + 1 << ' ';
        must_l++;
    }
}