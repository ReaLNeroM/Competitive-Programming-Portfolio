#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 16;
const ll INF = 1e17;
const ll maxbit = (1 << maxn);
ll weight[maxn];
ll speed[maxn];
ll belief[maxn][maxn];
ll dist[maxbit][2];
ll found_person[maxn];

ll good_weight[maxbit];
ll max_speed[maxbit];
ll works_belief[maxbit];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, b;
	std::cin >> n >> b;

	for(ll i = 0; i < n; i++){
		std::cin >> weight[i];
	}

	for(ll i = 0; i < n; i++){
		std::cin >> speed[i];
	}

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			char c;
			std::cin >> c;

			belief[i][j] = (c == 'Y');
		}
	}

	for(ll big_bitset = 1; big_bitset < (1 << n); big_bitset++){
		ll sum_weight = 0;
		max_speed[big_bitset] = 0;
		std::fill(found_person, found_person + maxn, 0);
		works_belief[big_bitset] = true;

		ll people_in = 0;

		for(ll i = 0, bit = 1; i < n; i++, bit *= 2){
			if(bit & big_bitset){
				sum_weight += weight[i];
				max_speed[big_bitset] = std::max(max_speed[big_bitset], speed[i]);
				people_in++;

				for(ll j = 0, bit2 = 1; j < n; j++, bit2 *= 2){
					if(bit2 & big_bitset){
						if(belief[i][j]){
							found_person[i]++;
						}
					}
				}

				if(found_person[i] < 2){
					works_belief[big_bitset] = false;
				}
			}
		}

		good_weight[big_bitset] = (sum_weight <= b);

		if(people_in == 1){
			works_belief[big_bitset] = true;
		}
	}

	for(ll i = 0; i < maxbit; i++){
		dist[i][0] = dist[i][1] = INF;
	}

	std::priority_queue<std::vector<ll>> pq;
	dist[0][0] = 0;
	pq.push({-dist[0][0], 0, 0});

	while(!pq.empty()){
		ll frcost = -pq.top()[0];
		ll fr = pq.top()[1];
		ll frside = pq.top()[2];
		pq.pop();

		for(ll i = 1; i < (1 << n); i++){
			if(good_weight[i] and works_belief[i]){
				if((frside == 0 and (fr & i) == 0) or (frside == 1 and (fr & i) == i)){
					if(dist[fr ^ i][!frside] > frcost + max_speed[i]){
						dist[fr ^ i][!frside] = frcost + max_speed[i];
						pq.push({-dist[fr ^ i][!frside], fr ^ i, !frside});
					}
				}
			}
		}
	}

	if(dist[(1 << n) - 1][1] == INF){
		std::cout << -1 << '\n';
	} else {
		std::cout << dist[(1 << n) - 1][1] << '\n';
	}
}
