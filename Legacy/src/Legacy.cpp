#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll seg[4 * maxn];
vector<pair<pair<ll, ll>, ll>> upd_seg[4 * maxn];
ll v, e, start;
ll type[maxn];
ll found[maxn];
pair<ll, ll> f[maxn];
pair<ll, ll> s[maxn];

pair<ll, ll> query(int ind, int cl, int cr){
	if(cl == cr){
		return seg[ind];
	} else if(cr < cl){
		return {1e18, 1e18};
	}

	int mid = (cl + cr) / 2;

	pair<ll, ll> a = query(2 * ind + 1, cl     , mid);
	pair<ll, ll> b = query(2 * ind + 2, mid + 1, cr );

	if(a.second <= b.second){
		return a;
	} else {
		return b;
	}
}

void update(int ind, int cl, int cr, int ql, int qr, int w){
	if(ql <= cl and cr <= qr){
		seg[ind] = min(seg[ind], w);
		return;
	} else if(cr < ql or qr < cl){
		return;
	}

	int mid = (cl + cr) / 2;

	update(2 * ind + 1, cl     , mid, ql, qr, w);
	update(2 * ind + 2, mid + 1, cr , ql, qr, w);
}

void clear(ll pos, ll w){
	for(ll i = 0; i < upd_seg[pos].size(); i++){
		update(0, 0, maxn - 1, upd_seg[pos][i].first.first, upd_seg[pos][i].first.second, w + upd_seg[pos][i].second);
	}
	upd_seg[pos].clear();
}
void upd_query(ll ind = 0, ll cl = 0, ll cr = maxn - 1, ll q, ll w){
	clear(ind);
	while(cl < cr){
		ll mid = (cl + cr) / 2;

		if(q <= mid){
			cr = mid;
			ind = 2 * ind + 1;
		} else {
			cl = mid + 1;
			ind = 2 * ind + 2;
		}
		clear(ind);
	}
}
void upd_update(int ind, int cl, int cr, pair<ll, ll> f, pair<ll, ll> s, ll w){
	if(f.first <= cl and cr <= f.second){
		upd_seg[ind].push_back({s, w});
		return;
	} else if(cr < f.first or cl < f.second){
		return;
	}

	int mid = (cl + cr) / 2;

	upd_update(2 * ind + 1, cl     , mid, f, s, w);
	upd_update(2 * ind + 2, mid + 1, cr , f, s, w);
}

int main(){
	std::cin >> v >> e >> start;

	fill(found, found + v, -1);
	for(int i = 0; i < 4 * v; i++){
		seg[i] = 1e18;
	}

	for(ll i = 0; i < e; i++){
		std::cin >> type[i];
		if(type[i] == 1){
			std::cin >> f[i].first >> s[i].first >> w[i];
			f[i].second = f[i].first;
			s[i].second = s[i].first;
		} else if(type[i] == 2){
			std::cin >> f[i].first >> f[i].second >> s[i].first >> w[i];
			s[i].second = s[i].first;
		} else {
			std::cin >> f[i].first >> s[i].first >> s[i].second >> w[i];
			f[i].second = f[i].first;
		}

		upd_update(0, 0, maxn - 1, f[i], s[i], w[i]);
	}

	update(0, 0, maxn - 1, start, start, 0);

	for(int i = 0; i < v; i++){
		pair<ll, ll> pos = query(0, 0, maxn - 1);
		if(pos.second == 1e18 or done[pos.first]){
			update(0, 0, maxn - 1, pos.first, pos.first, 1e18);
			continue;
		}
		done[pos.first] = true;
		found[pos.first] = pos.second;

		upd_query(0, 0, maxn - 1, pos.first, pos.second);
	}

	for(int i = 0; i < v; i++){
		std::cout << found[i] << ' ';
	}
}
