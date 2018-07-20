#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 1e6 + 1e2;
ll length, n;
ll l[MAXN], r[MAXN];

int good2(ll min_dist, ll start_pos){
	ll curr_leftmost = start_pos;

	for(ll i = 1; i < n; i++){
		curr_leftmost = std::max(l[i], curr_leftmost + min_dist);

		if(curr_leftmost > r[i]){
			return 0;
		}
	}

	if(curr_leftmost + min_dist <= length + start_pos){
		return 2;
	}

	return 1;
}

bool good(ll min_dist){
	ll range_l = l[0], range_r = r[0];
	ll furthest_best = l[0];

	while(range_l <= range_r){
		ll mid = (range_l + range_r) / 2;

		int response = good2(min_dist, mid);
		if(response == 2){
			return true;
		} else if(response == 0){
			range_r = mid - 1;
		} else {
			range_l = mid + 1;
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> length >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> l[i] >> r[i];
	}

	ll range_l = 0, range_r = length;
	ll best = 0;

	while(range_l <= range_r){
		ll mid = (range_l + range_r) / 2;

		if(good(mid)){
			best = mid;
			range_l = mid + 1;
		} else {
			range_r = mid - 1;
		}
	}

	std::cout << best << '\n';
}
