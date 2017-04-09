#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		ll n, k;
		cin >> n >> k;

		cout << "Case #" << x + 1 << ": ";

		map<ll, ll> m;
		m[n] = 1;

		ll accumulated = 0;
		while(true){
			ll amount = (--m.end())->second;
			ll size = (--m.end())->first;
			m.erase(--m.end());

			ll a = (size - 1) / 2;
			ll b = size - 1 - a;

			m[a] += amount;
			m[b] += amount;

			if(accumulated + amount >= k){
				cout << b << ' ' << a << endl;
				break;
			}
			accumulated += amount;
		}
	}
}
