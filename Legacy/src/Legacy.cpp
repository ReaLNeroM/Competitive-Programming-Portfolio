#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 5e5 + 1e2;
ll seg[4 * maxn];
ll laz[4 * maxn];
ll on_seg[4 * maxn];
std::vector<std::pair<std::pair<ll, ll>, ll>> upd_seg[4 * maxn];
ll v, e, start;
ll type[maxn];
ll found[maxn];
std::pair<ll, ll> f[maxn];
std::pair<ll, ll> s[maxn];
ll w[maxn];

void expand(ll ind){
	seg[2 * ind + 1] = std::min(seg[2 * ind + 1], laz[ind]);
	seg[2 * ind + 2] = std::min(seg[2 * ind + 2], laz[ind]);
	laz[2 * ind + 1] = std::min(laz[2 * ind + 1], laz[ind]);
	laz[2 * ind + 2] = std::min(laz[2 * ind + 2], laz[ind]);
	laz[ind] = 1e18;
}

std::pair<ll, ll> query(ll ind, ll cl, ll cr){
	if(cl == cr){
		return {cl, seg[ind]};
	}

	expand(ind);

	ll mid = (cl + cr) / 2;

	if(on_seg[2 * ind + 1] and on_seg[2 * ind + 2]){
		if(seg[2 * ind + 1] <= seg[2 * ind + 2]){
			return query(2 * ind + 1, cl     , mid);
		} else {
			return query(2 * ind + 2, mid + 1, cr );
		}
	} else if(on_seg[2 * ind + 1]){
		return query(2 * ind + 1, cl     , mid);
	} else if(on_seg[2 * ind + 2]){
		return query(2 * ind + 2, mid + 1, cr );
	} else {
		return {1e18, 1e18};
	}
}

void update(ll ind, ll cl, ll cr, ll ql, ll qr, ll w){

	if(ql <= cl and cr <= qr){
		expand(ind);
		if(on_seg[ind] != 0){
			seg[ind] = std::min(seg[ind], w);
			laz[ind] = std::min(laz[ind], w);
		}
		return;
	} else if(cr < ql or qr < cl){
		return;
	}

	expand(ind);

	ll mid = (cl + cr) / 2;

	update(2 * ind + 1, cl     , mid, ql, qr, w);
	update(2 * ind + 2, mid + 1, cr , ql, qr, w);

	if(on_seg[2 * ind + 1] and on_seg[2 * ind + 2]){
		seg[ind] = std::min(seg[2 * ind + 1], seg[2 * ind + 2]);
	} else if(on_seg[2 * ind + 1]){
		seg[ind] = seg[2 * ind + 1];
	} else if(on_seg[2 * ind + 2]){
		seg[ind] = seg[2 * ind + 2];
	} else {
		seg[ind] = 1e18;
	}
}

void reduce(ll ind, ll cl, ll cr, ll q){
	on_seg[ind]--;
	if(cl == cr){
		seg[ind] = laz[ind] = 1e18;
		return;
	}

	ll mid = (cl + cr) / 2;
	expand(ind);

	if(q <= mid){
		reduce(2 * ind + 1, cl     , mid, q);
	} else {
		reduce(2 * ind + 2, mid + 1, cr , q);
	}

	if(on_seg[2 * ind + 1] and on_seg[2 * ind + 2]){
		seg[ind] = std::min(seg[2 * ind + 1], seg[2 * ind + 2]);
	} else if(on_seg[2 * ind + 1]){
		seg[ind] = seg[2 * ind + 1];
	} else if(on_seg[2 * ind + 2]){
		seg[ind] = seg[2 * ind + 2];
	} else {
		seg[ind] = laz[ind] = 1e18;
	}
}

void build(ll ind, ll cl, ll cr){
	if(cl == cr){
		on_seg[ind] = 1;
		return;
	}

	ll mid = (cl + cr) / 2;

	build(2 * ind + 1, cl     , mid);
	build(2 * ind + 2, mid + 1, cr );
	on_seg[ind] = on_seg[2 * ind + 1] + on_seg[2 * ind + 2];
}

void clear(ll pos, ll w){
	for(ll i = 0; i < upd_seg[pos].size(); i++){
		update(0, 0, v - 1, upd_seg[pos][i].first.first, upd_seg[pos][i].first.second, w + upd_seg[pos][i].second);
	}
	upd_seg[pos].clear();
}

void upd_query(ll ind, ll cl, ll cr, ll q, ll w){
	clear(ind, w);
	while(cl < cr){
		ll mid = (cl + cr) / 2;

		if(q <= mid){
			cr = mid;
			ind = 2 * ind + 1;
		} else {
			cl = mid + 1;
			ind = 2 * ind + 2;
		}
		clear(ind, w);
	}
}

void upd_update(ll ind, ll cl, ll cr, std::pair<ll, ll> f, std::pair<ll, ll> s, ll w){
	if(f.first <= cl and cr <= f.second){
		upd_seg[ind].push_back({s, w});
		return;
	} else if(cr < f.first or f.second < cl){
		return;
	}

	ll mid = (cl + cr) / 2;

	upd_update(2 * ind + 1, cl     , mid, f, s, w);
	upd_update(2 * ind + 2, mid + 1, cr , f, s, w);
}

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	std::cin >> v >> e >> start;
	start--;

	std::fill(found, found + v, -1);
	std::fill(seg, seg + 4 * v, 1e18);
	std::fill(laz, laz + 4 * v, 1e18);

	for(ll i = 0; i < e; i++){
		std::cin >> type[i];
		if(type[i] == 1){
			std::cin >> f[i].first >> s[i].first >> w[i];
			f[i].second = f[i].first;
			s[i].second = s[i].first;
		} else if(type[i] == 2){
			std::cin >> f[i].first >> s[i].first >> s[i].second >> w[i];
			f[i].second = f[i].first;
		} else {
			std::cin >> s[i].first >> f[i].first >> f[i].second >> w[i];
			s[i].second = s[i].first;
		}
		f[i].first--, f[i].second--;
		s[i].first--, s[i].second--;

		upd_update(0, 0, v - 1, f[i], s[i], w[i]);
	}

	build(0, 0, v - 1);
	update(0, 0, v - 1, start, start, 0);

	for(ll i = 0; i < v; i++){
		std::pair<ll, ll> pos = query(0, 0, v - 1);
		if(pos.second == 1e18){
			break;
		}

		reduce(0, 0, v - 1, pos.first);
		found[pos.first] = pos.second;

		upd_query(0, 0, v - 1, pos.first, pos.second);
	}

	for(ll i = 0; i < v; i++){
		std::cout << found[i] << ' ';
	}
}
