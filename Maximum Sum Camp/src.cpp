#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
std::pair<ll, ll> seg[4 * maxn];

std::pair<ll, ll> combine(std::pair<ll, ll> fir, std::pair<ll, ll> sec){
	ll biggest = fir.first, second_biggest = std::max(fir.second, sec.second);

	if(sec.first > biggest){
		second_biggest = std::max(second_biggest, biggest);
		biggest = sec.first;
	} else if(sec.first > second_biggest){
		second_biggest = sec.first;
	}

	return {biggest, second_biggest};
}

void build(ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cl == cr){
		seg[ind] = {val[cl], 0};
		return;
	}

	ll mid = (cl + cr) / 2;
	build(2 * ind + 1, cl, mid);
	build(2 * ind + 2, mid + 1, cr);

	auto fir = seg[2 * ind + 1];
	auto sec = seg[2 * ind + 2];

	seg[ind] = combine(fir, sec);
}

std::pair<ll, ll> query(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(qr < cl or cr < ql){
		return {0, 0};
	} else if(ql <= cl and cr <= qr){
		return seg[ind];
	}

	ll mid = (cl + cr) / 2;

	return combine(query(ql, qr, 2 * ind + 1, cl     , mid),
				   query(ql, qr, 2 * ind + 2, mid + 1, cr ));
}

void update(ll pos, ll change, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(cl == cr){
		seg[ind] = {val[cl], 0};
		return;
	}

	ll mid = (cl + cr) / 2;

	if(pos <= mid){
		update(pos, change, 2 * ind + 1, cl, mid);
	} else {
		update(pos, change, 2 * ind + 2, mid + 1, cr);
	}

	seg[ind] = combine(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::fill(val, val + maxn, 0);
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	build();

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		char c;
		ll a, b;

		std::cin >> c >> a >> b;

		if(c == 'Q'){
			a--, b--;
			auto return_value = query(a, b);
			std::cout << return_value.first + return_value.second << '\n';
		} else {
			a--;
			val[a] = b;

			update(a, b);
		}
	}
}
