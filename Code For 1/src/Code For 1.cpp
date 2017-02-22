#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll n, l, r;
ll res = 0;
map<ll, ll> sizee;

ll dfs(ll val, ll pos){
	ll size = sizee[val];

	if(r < pos or pos + size <= l){
		return pos + size;
	}
	if(val == 0){
		return pos + 1;
	} else if(val == 1){
		res++;
		return pos + 1;
	}

	pos = dfs(val / 2, pos);
	pos = dfs(val % 2, pos);
	pos = dfs(val / 2, pos);

	return pos;
}

ll calc_sizee(ll val){
	if(sizee.find(val) != sizee.end()){
		return sizee[val];
	}
	if(val == 0 or val == 1){
		sizee[val] = 1;
	} else {
		sizee[val] = 2 * calc_sizee(val / 2) + calc_sizee(val % 2);
	}

	return sizee[val];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;

	l--, r--;

	calc_sizee(n);
	dfs(n, 0);

	cout << res;
}

