#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    double a, b, k;
    std::cin >> a >> b >> k;
    
    for(double i = 0; i < k; i += 1.0){
        if(a <= b){
            a += 1.0;
        } else {
            b += 1.0;
        }
    }
    
    std::cout.precision(9);
    std::cout << std::fixed << a * b / 2.0;
}