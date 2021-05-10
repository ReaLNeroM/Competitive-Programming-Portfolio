// https://codefu.mk/codefu2021-round2.html?subpage=problem&problemid=3275

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;
const ll mod = 1000000007;

class ShipArrangement {
public:
    int getNumberOfArrangements(string sN, int M){
        ll n = 0;
        for(ll i = 0; i < sN.size(); i++){
            n *= 10;
            n += sN[i] - '0';
        }
        ll mat[][2] = {{M * (M - 1), M}, {M, 0}};
        // make n - 2
        ll c[][2] = {{M-1, M-1}, {1, 0}};
        ll curr = n - 1;
        while(curr){
            if(curr & 1){
                ll temp[][2] = {{0, 0}, {0, 0}};
                for(ll j = 0; j < 2; j++){
                    for(ll k = 0; k < 2; k++){
                        for(ll l = 0; l < 2; l++){
                            temp[j][k] += c[j][l] * mat[l][k];
                            temp[j][k] %= mod;
                        }
                    }
                }
                for(ll j = 0; j < 2; j++){
                    for(ll k = 0; k < 2; k++){
                        mat[j][k] = temp[j][k];
                    }
                }
            }
            ll temp[][2] = {{0, 0}, {0, 0}};
            for(ll j = 0; j < 2; j++){
                for(ll k = 0; k < 2; k++){
                    for(ll l = 0; l < 2; l++){
                        temp[j][k] += c[j][l] * c[l][k];
                        temp[j][k] %= mod;
                    }
                }
            }
            for(ll j = 0; j < 2; j++){
                for(ll k = 0; k < 2; k++){
                    c[j][k] = temp[j][k];
                }
            }
            curr /= 2;
        }
        ll res = 1;
        res = mat[1][1] + mat[1][0];
        res %= mod;
        return res;
    }
};