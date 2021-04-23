// https://nadc21.kattis.com/problems/nadc21.longestcommonsubstring

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 1e3 + 1e2;
int n;
string s[maxn];
ll a = 37;
ll b = 7;
ll m = 5000000000000023LL;

std::unordered_set<ll> hashes[maxn][maxn];

bool good(int s){
    for(ll goalhash : hashes[0][s]){
        bool win = true;
        for(int i = 1; i < n; i++){
            if(!hashes[i][s].count(goalhash)){
                win = false;
                break;
            }
        }
        if(win){
            return true;
        }
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> s[i];
        for(int j = 0; j < s[i].size(); j++){
            ll r = b;
            for(int k = j; k < s[i].size(); k++){
                r *= a;
                r += (int) (s[i][k] - 'a') + 2;
                r %= m;
                hashes[i][k - j + 1].insert(r);
            }
        }
    }

    int l = 1, r = s[0].size();
    int best = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(good(mid)){
            best = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << best << '\n';
}
