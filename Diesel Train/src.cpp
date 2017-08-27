#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int d, l, n;
    std::cin >> d >> l >> n;
    
    for(int i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    val[n] = 0;
    val[n + 1] = d;
    std::sort(val, val + n + 2);
    
    long double res = 0.0;
    for(int i = 0; i < n + 1; i++){
        if(val[i] + l < val[i + 1]){
            long double extent = (val[i + 1] - l) - val[i];
            res += extent * extent / 4.0;
        }
    }
    
    std::cout.precision(10);
    std::cout << std::fixed << res / (long double) d << '\n';
}