#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 1e2;

int main(){
	ll t;
	cin >> t;

	for(ll x = 0; x < t; x++){
		string s;
		cin >> s;

		ll n = s.size();
		ll soldiers = 0;
		ll res = 0;
		for(ll i = n - 1; i >= 0; i--){
			if(s[i] == '1'){
				soldiers++;
				res += (n - soldiers) - i;
			}
		}

		ll carry = 0;
		soldiers = 0;
		for(ll i = 0; i < n; i++){
			if(s[i] == '1'){
				soldiers++;
				if(i + 1 != n and s[i + 1] == '0'){
					res += soldiers;
				}
			}
		}

		cout << res << '\n';
	}
}