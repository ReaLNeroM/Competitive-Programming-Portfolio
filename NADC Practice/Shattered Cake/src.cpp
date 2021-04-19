// https://open.kattis.com/contests/nadc21practice1/problems/shatteredcake

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int w;
    scanf("%d", &w);

    int n;
    scanf("%d", &n);

    int tot = 0;

    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        tot += a * b;
    }

    printf("%d\n", tot / w);
}
