#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n, k, win;
    std::cin >> n >> k >> win;
    
    val[0] = k;
    
    for(int i = 1; i < (1 << n); i++){
        if(i >= k){
            val[i] = i + 1;
        } else {
            val[i] = i;
        }
    }
    
    int next_ind = 1;
    
    for(int i = 0; i <= win; i++){
        if(i == win and i != n){
            if(k + 1 > (1 << n)){
                std::cout << -1 << std::endl;
                return 0;
            }
            
            std::swap(val[(1 << n) - 1], val[next_ind]);
            //place k + 1 in val[next_ind]
            break;
        }
        
        if(val[0] < val[next_ind]){
            std::cout << -1 << std::endl;
            return 0;
            
        }
        next_ind = (next_ind + 1) * 2 - 1;
    }
    
    for(int i = 0; i < (1 << n); i++){
        std::cout << val[i] << ' ';
    }
    
    std::cout << std::endl;
}