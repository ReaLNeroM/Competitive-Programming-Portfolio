#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 5005;

ll py[maxn], px[maxn];
bool must[maxn];
ll worst[maxn];
std::vector<std::vector<ll>> v;

ll sq(ll a){
	return a * a;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n, k;
	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> py[i] >> px[i];
	}

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < i; j++){
			long long dist = sq(py[j] - py[i]) + sq(px[j] - px[i]);

			if(v.size() < k or (v.front()[0] > dist)){
				if(i == 27 or j == 27){
					int x = 5;
				}
				v.push_back({dist, i, j});
				push_heap(v.begin(), v.end());

				while(v.size() > k){
					pop_heap(v.begin(), v.end());
					v.pop_back();
				}
			}
		}
	}
	std::sort(v.rbegin(), v.rend());

	ll of_worst = v.size();

	for(ll i = 1; i < v.size(); i++){
		if(v[i][0] != v[i - 1][0]){
			of_worst = i;
			for(ll j = i; j < v.size(); j++){
				must[v[j][1]] = true;
				must[v[j][2]] = true;
			}
			break;
		}
	}

	ll found = 0;

	for(ll i = 0; i < n; i++){
		worst[i] = 0;
		for(ll j = 0; j < i; j++){
			long long dist = sq(py[j] - py[i]) + sq(px[j] - px[i]);

			if(dist == v[0][0]){
				worst[i]++;
				worst[j]++;
				found++;
			}
		}
	}

	long double sum = 0.0;
	for(ll i = 0; i < v.size(); i++){
		sum += std::sqrt((long double) v[i][0]);
	}

	std::cout.precision(5);
	std::cout << std::fixed << sum << std::endl;

	for(ll i = 0; i < n; i++){
		if(found - worst[i] < of_worst){
			must[i] = true;
		}
	}

	for(ll i = 0; i < n; i++){
		if(must[i]){
			std::cout << i << '\n';
		}
	}
}
