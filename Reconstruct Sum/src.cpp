#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);

    ll n;
    std::cin >> n;

    ll x = 1;
    ll ite = 0;
    while(x * 10 <= n){
        x *= 10;
        ite++;
    }

    for(int i = 0; i < ite; i++){
        std::cin >> val[i];
    }

    ll res = 1;

    for(int i = 0; i <= ite; i++){
        int carry = (i != 0 and val[i - 1]);
        int goal = n % 10;

        ll now = 0;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(val[i] and j + k + carry >= 10 and j + k + carry - 10 == goal){
                    now++;
                } else if(!val[i] and j + k + carry == goal){
                    now++;
                }
            }
        }

        res *= now;

        n /= 10;
    }

    std::cout << res << '\n';
}
