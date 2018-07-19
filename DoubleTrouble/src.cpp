#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 1e5 + 1e2;
ll val[maxn];
ll fen[maxn];
ll found[maxn];

void update(int pos, int change){
	pos++;

	while(pos < maxn){
		fen[pos] += change;
		pos += pos & -pos;
	}
}

int query(int pos){
	pos++;

	int res = 0;
	while(pos){
		res += fen[pos];
		pos -= pos & -pos;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("doubletrouble.in", "r", stdin);
		freopen("doubletrouble.out", "w", stdout);
	#endif

	ll n, e;
	std::cin >> n >> e;

	ll inversions = 0;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];

		inversions += i - query(val[i]);
		update(val[i], 1);
	}

	found[1] = inversions;

	std::cout << res << '\n';
}
