#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6;
ll n, m;
ll val[maxn];

ll good(ll time){
	ll curr_box = -1;
	ll box_left = 0;

	for(ll i = 0; i < m; i++){
		ll time_left = time - (curr_box + 1);

		while(time_left > 0 and curr_box != n){
			if(box_left == 0){
				curr_box++;
				box_left = val[curr_box];
				time_left--;
			} else {
				ll taken = std::min(box_left, time_left);
				box_left -= taken;
				time_left -= taken;
			}
		}

		while(box_left == 0){
			curr_box++;
			box_left = val[curr_box];
		}

		if(curr_box == n){
			return true;
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> m;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}
	val[n] = 1e18;

	ll l = 0, r = 1e18;
	ll res = 1e18;

	while(l <= r){
		ll mid = (l + r) / 2;

		if(good(mid)){
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	std::cout << res << std::endl;
}