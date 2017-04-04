#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll mod = 1e9 + 7;
static ll val[maxn];
static int fib[(int) (2e7 + 1e2)];
ll n;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;

	fib[0] = 0;
	fib[1] = 1;
	for(ll i = 2; i < 2e7 + 1e2; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= mod;
	}

	for(ll x = 0; x < t; x++){
		cin >> n;

		for(ll i = 0; i < n; i++){
			cin >> val[i];
			val[i]++;
		}

		ll q;
		cin >> q;

		for(ll i = 0; i < q; i++){
			ll t;
			cin >> t;

			if(t == 1){
				ll l, r;
				cin >> l >> r;
				l--, r--;

				ll sum = 0;
				for(ll i = l; i <= r; i++){
					sum += fib[val[i]];
				}
				sum %= mod;
				cout << sum << '\n';
			} else {
				ll l, r, change;
				cin >> l >> r >> change;
				l--, r--;

				for(ll i = l; i <= r; i++){
					val[i] += change;
				}
			}
			if(i % 1024 == 0){
				cerr << x << ' ' << i << endl;
			}
		}

	}
}

