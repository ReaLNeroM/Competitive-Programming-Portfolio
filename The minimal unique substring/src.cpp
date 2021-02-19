#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
char v[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    if(n == k){
        for(int i = 0; i < n; i++){
            std::cout << '0';
        }
        std::cout << '\n';
        return 0;
    }

    int l = (n - k) / 2;

    for(int i = 0; i < n; i++){
        v[i] = ((i % (l + 1)) == l) ? '1' : '0';
        std::cout << v[i];
    }
    std::cout << '\n';
}
