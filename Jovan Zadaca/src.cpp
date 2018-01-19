#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const ll mod = (ll)1e9 + 7;

ll t;
ll res;

ll calc(ll r, ll c, ll b, ll n)
{
    ll res = 0;
    if (r * c < b) { // Not enough pieces?
        return 0;      // Return (not a valid way)
    }
    if (n == 1 and r * c >= b) { // Enough pieces for the last
        return 1;
    }
    // The person who is in turn :
    for (ll i = 1; i < r; i++) { // Breaks it horizontally
        if (i * c >= b) {
            res += 2 * calc(r - i, c, b, n - 1); // Takes the upper half
            res %= mod;
        }
    }
    for (ll i = 1; i < c; i++) { // Breaks it vertically
        if (i * r >= b) {
            res += 2 * calc(r, c - i, b, n - 1); // Takes the left half
            res %= mod;
        }
    }

    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        ll r, c, b, n;
        cin >> r >> c >> b >> n;
        
        cout << calc(r, c, b, n) << endl;
        res = 0;
    }
    return 0;
}