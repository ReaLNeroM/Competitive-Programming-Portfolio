// https://nena20.kattis.com/problems/march6.rainbownumbers

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll mod = 998244353LL;

ll pow9[maxn];
ll dp[maxn][10];
std::string l, r;
std::string& s = l;

ll dpfunc(ll pos, ll last){
    if(dp[pos][last] != -1){
        return dp[pos][last];
    }

    ll& ans = dp[pos][last];
    ans = 0;
    if(pos == s.size()){
        ans = 1;
        return ans;
    }
    for(ll i = 0; i < 10; i++){
        if(pos == 0 and i == 0){
            continue;
        } else if(i == last){
            continue;
        }
        ll sc = s[pos] - '0';
        if(i < sc){
            ans += pow9[s.size() - pos - 1];
        } else if(i == sc){
            ans += dpfunc(pos + 1, i);
        }
        ans %= mod;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    cin >> l >> r;

    ll ln = l.size();
    ll rn = r.size();

    pow9[0] = 1;
    for(ll i = 1; i < maxn; i++){
        pow9[i] = pow9[i - 1] * 9LL;
        pow9[i] %= mod;
    }

    ll res = 0;

    // handle l
    s = l;
    bool easy_case = (l[0] == '1');
    for(ll i = 1; i < ln; i++){
        if(l[i] != '0'){
            easy_case = false;
        }
    }

    if(easy_case){
        if(ln != rn){
            res += pow9[ln];
            res %= mod;
        } else {

        }
    } else {
        ll carry = 1;
        for(ll i = ln - 1; i >= 0 and carry; i--){
            l[i] -= carry;
            if(l[i] < '0'){
                l[i] += 10;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }
        if(carry == 1){
            return -1;
        }
        // decrement l
        s = l;
        for(ll i = 0; i < maxn; i++){
            for(ll j = 0; j < 10; j++){
                dp[i][j] = -1;
            }
        }

        if(ln != rn){
            res += pow9[ln];
            res %= mod;
            res += (mod - dpfunc(0, 0));
            res %= mod;
        } else {
            res += (mod - dpfunc(0, 0));
            res %= mod;
        }
    }

    for(ll digits = ln + 1; digits < rn; digits++){
        res += pow9[digits];
        res %= mod;
    }

    s = r;
    for(ll i = 0; i < maxn; i++){
        for(ll j = 0; j < 10; j++){
            dp[i][j] = -1;
        }
    }
    res += dpfunc(0, 0);
    res %= mod;

    std::cout << res << '\n';
}
