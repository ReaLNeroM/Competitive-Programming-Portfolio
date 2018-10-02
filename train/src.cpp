#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 1e5 + 1e2;

struct passenger {
	ll start, end, cost, ind;

	bool operator<(passenger const &x){
		if(this->start == x.start){
			return this->end < x.end;
		}

		return this->start < x.start;
	}
};

passenger p[MAXN];
ll dp[MAXN];
ll dp_next_position[MAXN];

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("train.in", "r", stdin);
		freopen("train.out", "w", stdout);
	#endif

	ll passengers, stations;
	std::cin >> passengers >> stations;

	for(ll i = 0; i < passengers; i++){
		std::cin >> p[i].start >> p[i].end >> p[i].cost;
		p[i].ind = i + 1;
	}

	std::sort(p, p + passengers);

	ll best_res_ind = passengers;

	std::set<std::vector<ll>> s;

	for(ll i = passengers - 1; i >= 0; i--){
		dp[i] = p[i].cost;
		dp_next_position[i] = passengers;

		auto next_passenger_ite = s.lower_bound({p[i].end, 0, 0});

		if(next_passenger_ite != s.end()){
			dp[i] = (*next_passenger_ite)[1] + p[i].cost;
			dp_next_position[i] = (*next_passenger_ite)[2];
		}

		if(dp[i] > dp[best_res_ind]){
			best_res_ind = i;
		}

		s.insert({p[i].end, dp[i], i});

		auto current_element = s.find({p[i].end, dp[i], i});
		auto forward_element = current_element;
		forward_element++;

		if(forward_element != s.end() and (*ite)[1] <= (*forward_element)[1]){
			s.erase(ite);
			continue;
		}

		auto backwards_element = current_element;
		while(backwards_element != s.begin() and (*--backwards_element)[1] <= (*ite)[1]){
			s.erase(backwards_element);
			backwards_element = current_element;
		}
	}

	std::vector<ll> best_passengers;

	ll curr_pos = best_res_ind;

	while(curr_pos < passengers){
		best_passengers.push_back(p[curr_pos].ind);
		curr_pos = dp_next_position[curr_pos];
	}

	std::sort(best_passengers.begin(), best_passengers.end());

	std::cout << dp[best_res_ind] << '\n';
	std::cout << best_passengers.size() << '\n';
	for(ll i : best_passengers){
		std::cout << i << ' ';
	}
	std::cout << '\n';

}
