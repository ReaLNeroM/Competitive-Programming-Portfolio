#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 100;
const int max_value = 1e9;
int val[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n, sum;
    std::cin >> n >> sum;
    
    for(int i = 0; i < n; i++){
        val[i] = max_value - i;
    }

    sum -= n / 2;

    if(sum > 0 and n >= 2){
        val[0] = (sum + 1);
        val[1] = (sum + 1) * 2;
        sum = 0;
    }

    if(sum != 0){
        std::cout << -1;
    } else {
        for(int i = 0; i < n; i++){
            std::cout << val[i] << ' ';
        }
    }
    std::cout << std::endl;
}