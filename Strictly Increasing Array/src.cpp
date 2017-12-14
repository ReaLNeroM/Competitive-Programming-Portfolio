#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int max_value = 1e9;
int n;
int val[maxn];
int dp[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::multimap<int, std::vector<int>> m;

	for(int i = 0; i < n; i++){
		m.insert({val[i] - i, {i, 0}});
	}
	m.insert({max_value - n, {n, 0}});

	int curr_ind = 0;
	for(auto ite = m.begin(); ite != m.end(); ++ite){
		ite->second[1] = curr_ind;
		curr_ind++;

		while(true){
			auto sec = ite;
			sec++;

			if(sec == m.end()){
				break;
			}

			if(ite->second[0] < sec->second[0]){
				m.erase(sec);
			} else if (ite->first == sec->first and ite->second[0] > sec->second[0]){
				m.erase(ite);
				ite = sec;
				--ite;
			} else {
				break;
			}
		}
	}

	for(int i = n - 1; i >= 0; i--){
		int map_call = val[i] - i;
		int j = m.lower_bound(map_call + 1)->second[0];

		auto fir = m.lower_bound(map_call + 1);
		auto sec = m.lower_bound(fir->first + 1);

		int cost = (j - i) + (sec->second[1] - fir->second[1]);

		dp[i] = std::min(dp[i + 1] + 1, dp[j] + cost);
	}

	std::cout << dp[0] << '\n';
}
