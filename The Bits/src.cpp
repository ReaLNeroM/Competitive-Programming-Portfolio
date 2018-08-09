#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll below[2][2];
ll above[2][2];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::string a, b;
	std::cin >> a >> b;

	for(ll i = 0; i < n; i++){
		above[a[i] - '0'][b[i] - '0']++;
	}

	ll res = 0;
	for(ll i = 0; i < n; i++){
		above[a[i] - '0'][b[i] - '0']--;
		if(b[i] == '0'){
			res += above[!(a[i] - '0')][1];
			res += below[!(a[i] - '0')][0] + below[!(a[i] - '0')][1];
		}
		below[a[i] - '0'][b[i] - '0']++;
	}

	std::cout << res << '\n';
}