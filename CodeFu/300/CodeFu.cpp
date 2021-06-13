#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 1e2;
const ll mod = 1000000007;
ll val[maxn];
ll pow2[maxn];
class WeirdSum {
public:
    int findRangeSum(int L, int R){
        ll l = L;
        ll r = R;
        pow2[0] = 1;
        for(ll i = 1; i < maxn; i++){
            pow2[i] = (pow2[i - 1] * 2LL) % mod;
        }
        val[0] = 0;
        val[1] = 0;
        for(ll i = 1; i < maxn; i++){
            val[i] = (pow2[i] - val[i] + mod) % mod;
            for(ll j = i + i; j < maxn; j += i){
                val[j] += val[i];
                val[j] %= mod;
            }
        }
        ll res = 0;
        for(int i = l; i <= r; i++){
            res += val[i];
            res %= mod;
        }
        return res;
    }
};
    