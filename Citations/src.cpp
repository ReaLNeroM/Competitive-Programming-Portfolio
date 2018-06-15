#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll length[maxn];
std::vector<ll> adj[maxn];

bool cmp(std::vector<ll> first, std::vector<ll> second){
	return first[0] * second[1] < first[1] * second[0];
}

std::vector<ll> dfs(ll index){
	if(adj[index].empty()){
		return {1 + length[index], 1, 1 + length[index]};
	}

	std::vector<std::vector<ll>> v(adj[index].size());

	for(ll i = 0; i < adj[index].size(); i++){
		v[i] = dfs(adj[index][i]);
	}

	std::sort(v.begin(), v.end(), cmp);

	ll requisite_sum = 0;
	ll curr_finish_time = 1;
	ll sum_v_second = 0;
	ll sum_v_third = 0;

	for(ll i = 0; i < v.size(); i++){
		requisite_sum += curr_finish_time * v[i][1];

		curr_finish_time += v[i][0];
		sum_v_second += v[i][1];
		sum_v_third += v[i][2];
	}

	curr_finish_time += length[index];
	return {curr_finish_time, (ll) sum_v_second + 1, requisite_sum + curr_finish_time + sum_v_third};
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> length[i];

		ll requisites;
		std::cin >> requisites;
		adj[i].resize(requisites);

		for(ll j = 0; j < requisites; j++){
			std::cin >> adj[i][j];
			adj[i][j]--;
		}
	}

	std::cout << dfs(0)[2] << std::endl;
}
