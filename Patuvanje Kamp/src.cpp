#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll INFDIST = 1e16;
const ll MAXEDGE = 500000001;

ll v, e;
ll val[maxn];
std::vector<std::pair<ll, ll>> adj[maxn];
ll dist[maxn];
ll x_used[maxn];
ll start[maxn];
ll end[maxn];
bool used[maxn];

std::pair<ll, ll> attempt(ll posa, ll posb, ll x){
	std::fill(dist, dist + v, INFDIST);
	std::fill(used, used + v, 0);
	std::fill(x_used, x_used + v, 0);

	std::priority_queue<std::pair<ll, ll>> pq;
	dist[posa] = 0;
	pq.push({-dist[posa], posa});

	while(!pq.empty()){
		ll frcost = -pq.top().first, fr = pq.top().second;
		pq.pop();

		if(used[fr]){
			continue;
		}
		used[fr] = true;

		for(auto next : adj[fr]){
			ll nextind = next.first;
			ll nextcost = frcost;
			ll next_x_used = x_used[fr];

			if(next.second == -1){
				nextcost += x;
				next_x_used++;
			} else {
				nextcost += next.second;
			}

			if(dist[nextind] > nextcost or (dist[nextind] == nextcost and x_used[nextind] > next_x_used)){
				dist[nextind] = nextcost;
				x_used[nextind] = next_x_used;
				pq.push({-nextcost, nextind});
			}
		}
	}

	return {dist[posb], x_used[posb]};
}

void multi_binary(ll domain_l, ll domain_r, ll value_l, ll value_r, ll f, ll s){
	if(domain_l > domain_r or value_l > value_r){
		return;
	}

	ll mid = (domain_l + domain_r) / 2;

	std::pair<ll, ll> query = attempt(f, s, mid);

	start[query.second] = std::min(start[query.second], mid);
	end[query.second] = std::max(end[query.second], mid);

	if(value_l != value_r or start[query.second] > domain_l){
		multi_binary(domain_l, mid - 1, query.second, value_r, f, s);
	}
	if(value_l != value_r or end[query.second] < domain_r){
		multi_binary(mid + 1, domain_r, value_l, query.second, f, s);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e;

	for(ll i = 0; i < e; i++){
		ll f, s;
		std::string cost;
		std::cin >> f >> s >> cost;
		f--, s--;

		if(cost == "x"){
			adj[f].push_back({s, -1});
		} else {
			std::stringstream ostr;
			ostr << cost;

			ll dist;
			ostr >> dist;

			adj[f].push_back({s, dist});
		}
	}

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;

		ll res = 0, ressum = 0;

		std::fill(start, start + v, MAXEDGE);
		std::fill(end, end + v, 0);

		auto initial = attempt(f, s, 1);

		if(initial.first == INFDIST){ //no path
			std::cout << 0 << ' ' << 0 << '\n';
			continue;
		}

		multi_binary(1, MAXEDGE, 0, initial.second, f, s); // returns start and end intervals 
														   // for each value in a nonincreasing function

		for(ll j = 1; j < v; j++){
			if(start[j] <= end[j]){
				res += end[j] - start[j] + 1;
				ressum += attempt(f, s, start[j]).first * (end[j] - start[j] + 1LL);
				ressum += (end[j] - start[j]) * (end[j] - start[j] + 1) / 2LL * j;
			}
		}

		res += 1;
		ressum += attempt(f, s, MAXEDGE).first;

		if(start[0] > end[0]){
			std::cout << "inf\n";
		} else {
			std::cout << res << ' ' << ressum << '\n';	
		}
	}
}
