#include <bits/stdc++.h>
#include "aliens.h"
typedef long long ll;

const ll maxn = 1e6 + 1e2;
bool independent[maxn];
ll extent[maxn];
ll size[maxn];
std::vector<std::pair<ll, ll>> q;

ll score(ll a, ll option){
	ll b;
	if(option == 0){
		b = a + size[a] - 1;
	} else {
		b = a + size[a] + size[a + size[a]] - 1;
	}

	ll c = q[b].second + 1;
	if(b + 1 != q.size()){
		c = std::min(c, q[b + 1].first);
	}

	return (q[b].second - q[a].first + 1LL) * (q[b].second - q[a].first + 1LL) - (q[b].second - c + 1LL) * (q[b].second - c + 1LL);
}

ll take_photos(int n, int m, int k, std::vector<int> r, std::vector<int> c) {
	for(int i = 0; i < maxn; i++){
		extent[i] = -1;
	}

	for(ll i = 0; i < r.size(); i++){
		if(r[i] <= c[i]){
			extent[r[i]] = std::max(extent[r[i]], (ll) c[i]);
		} else {
			extent[c[i]] = std::max(extent[c[i]], (ll) r[i]);
		}
	}

	ll curr = -1;
	for(ll i = 0; i < maxn; i++){
		if(extent[i] > curr){
			curr = extent[i];
			size[q.size()] = 1;
			q.push_back({i, extent[i]});
		}
		independent[i] = true;
	}

	std::priority_queue<std::pair<ll, std::pair<ll, ll>>> pq;

	for(ll i = 0; i < q.size() - 1; i++){
		pq.push({-score(i, 1), {i, i + size[i]}});
	}

	for(ll curr_p = q.size(); curr_p > k; curr_p--){
		ll frind1 = pq.top().second.first, frind2 = pq.top().second.second;
		ll gotten = score(frind1, 1);
		while(!independent[pq.top().second.first] or !independent[pq.top().second.second] or gotten != -pq.top().first){
			if(gotten != -pq.top().first){
				pq.pop();
				pq.push({-gotten, {frind1, frind2}});
			} else {
				pq.pop();
			}
			frind1 = pq.top().second.first, frind2 = pq.top().second.second;
			ll gotten = score(frind1, 1);
		}

		size[frind1] = size[frind1] + size[frind2];
		independent[frind2] = false;
		if(frind1 + size[frind1] < q.size()){
			pq.push({-score(frind1, 1), {frind1, frind1 + size[frind1]}});
		}
		pq.pop();
	}

	ll res = 0;
	ll pos = 0;
	while(pos < q.size()){
		res += score(pos, 0);
		pos = pos + size[pos];
	}

    return res;
}
