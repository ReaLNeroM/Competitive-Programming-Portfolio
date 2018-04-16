#include <bits/stdc++.h>

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll y, x;
    std::cin >> y >> x;
    
    ll value[y][x];
    ll input[y][x];
    
    for(ll i = 0; i < y; i++){
        for(ll j = 0; j < x; j++){
            std::cin >> input[i][j];
            value[i][j] = 0;
        }
    }
    
    for(ll i = 0; i < y - 1; i++){
        for(ll j = 0; j < x - 1; j++){
            value[i][j]++;
            value[i + 1][j]++;
            value[i][j + 1]++;
            value[i + 1][j + 1]++;
        }
    }

    ll sum = 0;

    for(ll i = 0; i < y; i++){
        for(ll j = 0; j < x; j++){
            sum += value[i][j] * input[i][j];
        }
    }

    ll res = sum;
    
    for(int a = 0; a < 2; a++){
        for(ll i = 1; i < y; i++){
            ll change = 0;
            for(ll j = 0; j < x; j++){
                change += (value[i][j] - value[0][j]) * input[0][j];
                change += (value[0][j] - value[i][j]) * input[i][j];
            }

            res = std::max(res, sum + change);
        }
        
        for(ll j = 1; j < x; j++){
            ll change = 0;
            for(ll i = 0; i < y; i++){
                change += (value[i][j] - value[i][0]) * input[i][0];
                change += (value[i][0] - value[i][j]) * input[i][j];
            }

            res = std::max(res, sum + change);
        }
        
        for(int i = 0; i < y; i++){
            for(int j = 0; j < x - 1 - j; j++){
                std::swap(input[i][j], input[i][x - 1 - j]);
            }
        }

        for(int j = 0; j < x; j++){
            for(int i = 0; i < y - 1 - i; i++){
                std::swap(input[i][j], input[y - 1 - i][j]);
            }
        }
    }

    std::cout << res << '\n';
}