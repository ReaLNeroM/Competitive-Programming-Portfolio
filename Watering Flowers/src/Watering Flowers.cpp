#include <iostream>

using namespace std;
typedef long long ll;

ll euclid(ll a[2], ll b[2]){
	return (b[1] - a[1]) * (b[1] - a[1]) + (b[0] - a[0]) * (b[0] - a[0]);
}

int main() {
	ios::sync_with_stdio(false);

	ll n;
	ll f[2][2];
	cin >> n;

	for(ll i = 0; i < 2; i++){
		cin >> f[i][0] >> f[i][1];
	}

	ll c[n][2];
	for(ll i = 0; i < n; i++){
		cin >> c[i][0] >> c[i][1];
	}

	ll res = 1000000000000000000;

	for(ll i = 0; i <= n; i++){
		ll dist;
		if(i == n){
			dist = 0;
		} else {
			dist = euclid(f[0], c[i]);
		}

		ll seconddist = 0;
		for(ll j = 0; j < n; j++){
			if(dist < euclid(f[0], c[j])){
				seconddist = max(seconddist, euclid(f[1], c[j]));
			}
		}

		res = min(res, dist + seconddist);
	}

	cout << res;
	return 0;
}
