#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstring>

typedef long long ll;

const int maxn = 1e7 + 1e2;
static bool composite[maxn];

class PrimeFactors {
    bool russian_peasant(ll a, ll b, ll exceed){
        ll sum = 0;
        while(b){
            if(a > exceed){
                return true;
            }
            
            if(b % 2 == 1){
                sum += a;

                if(sum > exceed){
                    return true;
                }
            }

            a *= 2;
            b /= 2;
        }

        return false;
    }
    
public:
    std::string count(std::string A, std::string B){
        ll a = 0;
        ll b = 0;

        for(int i = 0; i < A.size(); i++){
            a *= 10;
            a += A[i] - '0';
        }
        for(int i = 0; i < B.size(); i++){
            b *= 10;
            b += B[i] - '0';
        }

        ll res = 0;
        memset(composite, false, sizeof(composite));
        for(ll i = 2; i < maxn; i++){
            if(!composite[i]){
                for(ll j = i * i; j < maxn; j += i){
                    composite[j] = true;
                }

                ll cop = i * i;
                while(cop <= b){
                    if(a <= cop){
                        res++;
                    }

                    if(russian_peasant(cop, i, b)){
                        break;
                    }
                    cop *= i;
                }
            }
        }

        std::string s = "";
        do {
            s += res % 10 + '0';
            res /= 10;
        } while(res);

        std::reverse(s.begin(), s.end());
        return s;
    }
};