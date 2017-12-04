#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int g1, g2, p1, p2;
    std::cin >> g1 >> p1 >> g2 >> p2;
    
    int a = g2 * (p2 + 1) / 100;
    int b = g1 * p1 / 100.0;
    
    if(b * 100 != g1 * p1){
        b++;
    }
    if(a * 100 / g2 != p2){
        a--;
    }
    
    std::cout << a - b;
}