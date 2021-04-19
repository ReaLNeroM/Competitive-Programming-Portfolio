// https://open.kattis.com/contests/nadc21practice1/problems/finalexam2

#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int val[maxn];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        char c;
        std::cin >> c;
        val[i] = (c - 'A');
    }

    int res = 0;
    for(int i = 0; i < n - 1; i++){
        int corr = val[i];
        int written = val[i + 1];
        if(corr == written){
            res++;
        }
    }

    std::cout << res << '\n';
}
