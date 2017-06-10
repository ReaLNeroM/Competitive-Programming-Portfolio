#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 100005;
const ll maxseg = 2000000;
ll val[maxn];
ll pocetok[maxseg];
ll kraj[maxseg];
ll maksimum[maxseg];
ll suma[maxseg];

void calc(ll ind, ll l, ll r, ll x, ll y){
	if(l == r){
		maksimum[ind] = kraj[ind] = pocetok[ind] = suma[ind] = val[l];	
	} else {
		maksimum[ind] = kraj[x] + pocetok[y];
		pocetok[ind] = std::max(pocetok[x], suma[x] + pocetok[y]);
		kraj[ind] = std::max(kraj[y], kraj[x] + suma[y]);
		maksimum[ind] = std::max(std::max(maksimum[ind], maksimum[x]), maksimum[y]);
		suma[ind] = suma[x] + suma[y];
	}
}


void build(ll ind, ll l, ll r){
	if(l == r){
		pocetok[ind] = kraj[ind] = maksimum[ind] = suma[ind] = val[l];
		return;
	} else if(l > r){
		suma[ind] = 0;
		pocetok[ind] = kraj[ind] = maksimum[ind] = -1000000000000000000LL;
		return;
	}


	ll mid = (l + r) / 2;
	build(2 * ind + 1, l      , mid);
	build(2 * ind + 2, mid + 1, r);

	calc(ind, l, r, 2 * ind + 1, 2 * ind + 2);
}

void update(ll ind, ll l, ll r, ll a, ll b){
	if(l == r){
		val[l] = b;
		calc(ind, l, r, -1, -1);
	} else if(l > r){
		return;
	} else {
		ll mid = (l + r) / 2;

		if(a <= mid){
			update(2 * ind + 1, l, mid, a, b);
		} else {
			update(2 * ind + 2, mid + 1, r, a, b);
		}

		calc(ind, l, r, 2 * ind + 1, 2 * ind + 2);
	}
}

std::vector<ll> v_a;

void query(ll ind, ll l, ll r, ll a, ll b){
	if(r < a or b < l){
	} else if(a <= l and r <= b){
		std::vector<ll> b = {pocetok[ind], kraj[ind], maksimum[ind], suma[ind]};

		v_a[0] = std::max(v_a[0], v_a[3] + b[0]);
		v_a[1] = std::max(b[1], b[3] + v_a[1]);
		v_a[2] = std::max(std::max(v_a[2], b[2]), v_a[1] + b[0]);
		v_a[3] = v_a[3] + b[3];
	} else {
		ll mid = (l + r) / 2;

		query(2 * ind + 1, l      , mid, a, b);
		query(2 * ind + 2, mid + 1,   r, a, b);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::fill(val, val + maxn, 0);
	std::fill(pocetok, pocetok + maxn, -1000000000000000000LL);
	std::fill(kraj, kraj + maxn, -1000000000000000000LL);
	std::fill(maksimum, maksimum + maxn, -1000000000000000000LL);
	std::fill(suma, suma + maxn, 0);

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	build(0, 0, n - 1);

	ll q;
	std::cin >> q;

	std::stringstream str;
	for(ll i = 0; i < q; i++){
		int t, a, b;
		std::cin >> t >> a >> b;

		a--;

		// for(int i = 0; i <= 6; i++){
		// 	std::cout << pocetok[i] << ' ' << kraj[i] << ' ' << maksimum[i] << ' ' << suma[i] << std::endl;
		// }

		if(t == 0){
			update(0, 0, n - 1, a, b);
		} else if(t == 1){
			b--;

			v_a = {-1000000000000000000LL, -1000000000000000000LL, -1000000000000000000LL, 0};
			query(0, 0, n - 1, a, b);
			str << v_a[2] << '\n';
		}
	}

	std::cout << str.str();
}