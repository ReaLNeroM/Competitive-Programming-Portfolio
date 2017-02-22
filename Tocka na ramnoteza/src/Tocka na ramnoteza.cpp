#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e6;
ll val[maxn];
ll pref[maxn];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	for(ll i = 1; i <= n; i++){
		cin >> val[i];
	}

	pref[0] = 0;
	for(ll i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + val[i];
	}

	for(ll i = 1; i <= n; i++){
		if(pref[i - 1] == pref[n] - pref[i]){
			cout << i << endl;
			return 0;
		}
	}

	cout << -1;
}

