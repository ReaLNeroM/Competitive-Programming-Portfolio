#include <bits/stdc++.h>

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);

    int n, m, p, q;
    std::cin >> n >> m >> p >> q;

    for(int i = 0; i < p; i++){
        int f, s, c;
        std::cin >> f >> s >> c;
        f--, s--;

        edg.push_back({c, f, s});
        edg.push_back({c, s, f});

        if(m != 1){
            edg.push_back({c * (m - 1), n + f, n + s});
            edg.push_back({c * (m - 1), n + s, n + f});
        }
    }

    for(int i = 0; i < q; i++){
        int 
    }
}