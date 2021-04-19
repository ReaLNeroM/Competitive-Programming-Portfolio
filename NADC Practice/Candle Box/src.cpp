// https://open.kattis.com/contests/nadc21practice1/problems/candlebox

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int d, r, t;
    cin >> d >> r >> t;

    for(int a = 4; a <= 1000; a++){
        int b = a - d;
        int rcandles = a * (a + 1) / 2 - 6;
        int tcandles = std::max(0, b * (b + 1) / 2 - 3);

        if(rcandles + tcandles == r + t){
            cout << r - rcandles << '\n';
            break;
        }
    }
}
