// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7

#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll INF = 1000000000000000010;

int val[maxn];
int swapat[maxn];

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int n, c;
        std::cin >> n >> c;

        c -= n - 1;

        if(c < 0){
            std::cout << "IMPOSSIBLE\n";
            continue;
        }

        memset(swapat, 0, sizeof(swapat));
        for(int i = 0; i < n; i++){
            val[i] = i;
        }

        for(int i = 0; i < n and c > 0; i++){
            int besticando = (n - 1) - i;
            if(c >= besticando){
                c -= besticando;
                swapat[i] = true;
            }
        }

        if(c > 0){
            std::cout << "IMPOSSIBLE\n";
            continue;
        }

        for(int i = n - 1; i >= 0; i--){
            if(swapat[i]){
                std::reverse(val + i, val + n);
            }
        }

        for(int i = 0; i < n; i++){
            std::cout << val[i] + 1 << ' ';
        }
        std::cout << '\n';
    }
}