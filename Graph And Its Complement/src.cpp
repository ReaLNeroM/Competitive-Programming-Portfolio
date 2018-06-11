#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
std::string s[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n, a, b;
    std::cin >> n >> a >> b;

    if(n == 1){
        std::cout << "YES\n0\n";
        return 0;
    } else if(n == 2){
        if(a != b){
            if(a == 1){
                std::cout << "YES\n01\n10\n";
            } else if(a == 2){
                std::cout << "YES\n00\n00\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            std::cout << "NO\n";
        }
        return 0;
    }

    bool possible = true;

    for(int i = 0; i < n; i++){
        s[i] = std::string(n, '0');
    }

    int big_comp = n - (a - 1);

    if(n > 3 and a == 1 and b == 1){
        for(int i = 0; i < n - 1; i++){
            s[i][i + 1] = s[i + 1][i] = '1';
        }
    } else {
        for(int i = 1; i < big_comp; i++){
            s[0][i] = '1';
            s[i][0] = '1';
        }

        int curr_comps = 1;
        if(a == 1){
            curr_comps++;

            for(int i = 1; i < n and curr_comps < b; i++){
                for(int j = i + 1; j < n; j++){
                    s[i][j] = s[j][i] = '1';
                }
                curr_comps++;
            }
        }

        if(curr_comps != b){
            possible = false;
        }
    }

    if(possible){
        std::cout << "YES\n";

        for(int i = 0; i < n; i++){
            std::cout << s[i] << '\n';
        }
    } else {
        std::cout << "NO\n";
    }
}
