// https://open.kattis.com/contests/nadc21practice1/problems/completingthesquare

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll x[3];
ll y[3];

ll dist(ll i, ll j){
    return ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    for(ll i = 0; i < 3; i++){
        cin >> x[i] >> y[i];
    }

    ll maxdist = max(dist(0, 1), max(dist(0, 2), dist(1, 2)));

    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 3; j++){
            for(ll k = 0; k < 3; k++){
                if(i != j and i != k and j != k){
                    if(dist(i, j) == maxdist){
                        ll cenX = (x[i] + x[j]);
                        ll cenY = (y[i] + y[j]);
                        ll distXtoK = cenX - x[k] * 2;
                        ll distYtoK = cenY - y[k] * 2;
                        ll resX = x[k] + distXtoK;
                        ll resY = y[k] + distYtoK;
                        cout << resX << ' ' << resY << '\n';
                        return 0;
                    }
                }
            }
        }
    }
}
