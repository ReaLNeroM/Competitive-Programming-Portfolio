#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
ll seg[maxn];
ll ffind[maxn];
std::map<ll, ll> m;

void build(ll cl, ll cr, ll ind = 0){
	if(cl == cr){
		seg[ind] = val[cl];
		ffind[ind] = cl;
		return;
	}

	ll mid = (cl + cr) / 2;

	build(cl, mid, 2 * ind + 1);
	build(mid + 1, cr, 2 * ind + 2);

	seg[ind] = std::min(seg[2 * ind + 1], seg[2 * ind + 2]);
	if(seg[2 * ind + 1] == seg[ind]){
		ffind[ind] = ffind[2 * ind + 1];
	} else {
		ffind[ind] = ffind[2 * ind + 2];
	}
}

void update(ll qpos, ll cl, ll cr, ll ind = 0){
	if(qpos < cl or cr < qpos){
		return;
	} else if(qpos == cl and qpos == cr){
		seg[ind] = 1e9;
		ffind[ind] = cl;
		return;
	}

	ll mid = (cl + cr) / 2;

	update(qpos, cl, mid, 2 * ind + 1);
	update(qpos, mid + 1, cr, 2 * ind + 2);

	seg[ind] = std::min(seg[2 * ind + 1], seg[2 * ind + 2]);
	if(seg[2 * ind + 1] == seg[ind]){
		ffind[ind] = ffind[2 * ind + 1];
	} else {
		ffind[ind] = ffind[2 * ind + 2];
	}
}

std::pair<ll, ll> query(ll ql, ll qr, ll cl, ll cr, ll ind = 0){
	if(cr < ql or qr < cl){
		return {1e9, -1};
	} else if(ql <= cl and cr <= qr){
		return {seg[ind], ffind[ind]};
	}

	ll mid = (cl + cr) / 2;

	auto get = query(ql, qr, cl, mid, 2 * ind + 1);
	auto sec = query(ql, qr, mid + 1, cr, 2 * ind + 2);

	ll min = std::min(get.first, sec.first);

	if(get.first == min){
		return {min, get.second};
	} else {
		return {min, sec.second};
	}
}

ll fen[maxn];

void updatef(ll ind, ll change){
	ind += 2;
	while(ind < maxn){
		fen[ind] += change;
		ind += ind & -ind;
	}
}

ll queryf(ll ind){
	ll res = 0;
	ind += 2;
	while(ind > 0){
		res += fen[ind];
		ind -= ind & -ind;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		m[val[i]] = 1;
	}

	ll curr = 1;
	for(auto ite = m.begin(); ite != m.end(); ite++){
		ite->second = curr;
		curr++;
	}

	std::vector<ll> v;
	for(ll i = 0; i < n; i++){
		val[i] = m[val[i]];
		v.push_back(val[i]);
	}

	std::sort(v.begin(), v.end());
	build(0, n - 1, 0);

	ll sum = 1;

	ll pos = 0;

	for(ll i = 0; i < n; i++){
		//find v[i]
		auto get = query(pos, n - 1, 0, n - 1, 0);
		if(get.first == v[i]){
			sum += get.second - pos;
			sum -= (queryf(get.second) - queryf(pos));
		} else {
			get = query(0, pos - 1, 0, n - 1, 0);
			sum += n - pos;
			sum += get.second;
			sum -= (queryf(n) - queryf(pos));
			sum -= (queryf(get.second));
		}

		update(get.second, 0, n - 1, 0);
		pos = get.second;
		updatef(get.second, 1);
	}

	std::cout << sum << std::endl;
}