// https://codeforces.com/contest/1500/problem/B

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 5e5 + 1e2;
ll a[maxn];
ll b[maxn];
std::map<ll, ll> mb;
ll first[maxn];
ll n, m, k;

ll gcd(ll a, ll b){
    while(b != 0){
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

ll phi(ll n){
    ll c = 0;
    for(ll i = 1; i < n; i++){
        if(gcd(n, i) == 1){
            c++;
        }
    }
    return c;
}

ll exp(ll a, ll b, ll m){
    ll built = 1;
    ll ppow = a;
    while(b){
        if(b & 1){
            built *= ppow;
            built %= m;
        }
        ppow *= ppow;
        ppow %= m;
        b /= 2;
    }
    return built;
}

ll get_inverse(ll a, ll n){
    ll pn = phi(n);

    pn--;
    return exp(a, pn, n);
}

ll calm(ll guess){
    ll cycle = n * (m / gcd(n, m));

    ll ret = 0;
    for(ll i = 0; i < n; i++){
        if(first[i] == -1 or guess < first[i]){
            continue;
        }

        ret += (guess - first[i]) / cycle + 1;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }

    for(ll i = 0; i < m; i++){
        cin >> b[i];
    }

    if(n > m){
        for(ll i = 0; i < maxn; i++){
            std::swap(a[i], b[i]);
        }
        std::swap(n, m);
    }

    for(ll i = 0; i < m; i++){
        mb[b[i]] = i;
    }

    ll gnm = gcd(n, m);
    ll n_copy = n / gnm;
    ll m_copy = m / gnm;
    ll n_inverse = get_inverse(n_copy, m_copy);

    for(ll i = 0; i < n; i++){
        first[i] = -1;

        if(mb.find(a[i]) == mb.end()){
            continue;
        }
        ll p = i;
        ll q = mb.find(a[i])->second;

        // solve x * n_copy === q - p mod m_copy
        ll modresult = (q - p + m) % m;

        if(modresult % gnm != 0){
            continue;
        }
        modresult /= gnm;

        ll x = (modresult * n_inverse) % m_copy;

        first[i] = i + x * n + 1;
    }

    ll orig_r = 1;
    while(orig_r - calm(orig_r) < k){
        orig_r *= 10;
    }

    ll l = 1, r = orig_r;
    orig_r *= 10;
    ll best = -1;
    while(l <= r){
        ll mid = l + (r - l) / 2;

        if(mid - calm(mid) < k){
            l = mid + 1;
        } else {
            best = mid;
            r = mid - 1;
        }
    }

    cout << best << '\n';
    return 0;
}
