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
        int x, y;
        std::cin >> x >> y;
        if(x > 0 and y > 0){
            val[0]++;
        } else if(x < 0 and y > 0){
            val[1]++;
        } else if(x > 0 and y < 0){
            val[2]++;
        } else if(x < 0 and y < 0){
            val[3]++;
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(val[i]){
            res++;
        }
    }
    
    std::cout << res;
}