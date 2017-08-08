#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
const ll max_people = 1e2 + 1e2;

ll dist[maxn];
ll pos[maxn];
ll wait[maxn];
ll expect[maxn];
ll dp[maxn][max_people];
ll expectsum[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll hills, cats, people;
	std::cin >> hills >> cats >> people;

	for(ll i = 1; i < hills; i++){
		std::cin >> dist[i];
		dist[i] += dist[i - 1];
	}

	for(ll i = 0; i < cats; i++){
		std::cin >> pos[i] >> wait[i];
		pos[i]--;
		expect[i] = wait[i] - dist[pos[i]];
	}

	std::sort(expect, expect + cats);
	for(ll i = 1; i < cats; i++){
		expect[i] -= expect[0];
	}
	expect[0] = 0;

	for(ll i = 0; i < cats; i++){
		dp[i][0] = 1e18;
	}

	for(ll i = 1; i < cats; i++){
		expectsum[i] = expectsum[i - 1] + i * (expect[i] - expect[i - 1]);
	}

	for(ll j = 1; j <= people; j++){
		ll curr_pos = 0;
		std::vector<std::vector<ll>> v;
		v.push_back({0, 0});

		for(ll i = 0; i < cats; i++){
			curr_pos = std::min(curr_pos, (ll) v.size() - 1);
			while(curr_pos + 1 < v.size() and v[curr_pos][0] + v[curr_pos][1] * expect[i] >= v[curr_pos + 1][0] + v[curr_pos + 1][1] * expect[i]){
				curr_pos++;
			}

			dp[i][j] = v[curr_pos][1] * expect[i] + v[curr_pos][0] + expectsum[i];

			v.push_back({dp[i][j - 1] - expectsum[i] + (i + 1) * expect[i], -(i + 1)});

			ll t = v.size() - 3;

			while(v.size() >= 3 and (v[t + 1][0] - v[t][0]) * (v[t][1] - v[t + 2][1]) >= (v[t + 2][0] - v[t][0]) * (v[t][1] - v[t + 1][1])){
				v[v.size() - 2] = v[v.size() - 1];
				v.pop_back();
				t = v.size() - 3;
			}
		}
	}

	std::cout << dp[cats - 1][people] << '\n';
}
