#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    ll a, s, k, x, y;
    std::cin >> a >> s >> k >> x >> y;
    
    ll one = a - s + k * x;
    ll two = y + x;
    
    if(one % two == 0){
        std::cout << k - one / two;
    } else {
        std::cout << -1;
    }   
}