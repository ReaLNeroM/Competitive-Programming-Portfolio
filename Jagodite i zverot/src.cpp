#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 1e6 + 1e2;
static int val[maxn];
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    int n, m;
    std::cin >> n >> m;
 
    int res = 0;
 
    while(m >= n){
        m -= n;
        m += 3;
        res += 1;
    }
 
    std::cout << res << '\n';
}