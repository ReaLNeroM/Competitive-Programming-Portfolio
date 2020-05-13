#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
std::string s[maxn][maxn];

int main(){
    int y, x;
    std::cin >> y >> x;

    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            std::cin >> s[i][j];
        }
    }
}