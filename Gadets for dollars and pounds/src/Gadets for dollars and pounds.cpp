#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll d, gadg, n, m;
	cin >> d >> gadg >> n >> m;

	ll minm[2][d], minmi[2][d];
	for(ll c = 0; c < 2; c++){
		for(ll i = 0; i < d; i++){
			cin >> minm[c][i];
			minmi[c][i] = i;

			if(i > 0 and minm[c][i - 1] < minm[c][i]){
				minmi[c][i] = minmi[c][i - 1];
				minm[c][i] = minm[c][i - 1];
			}
		}
	}

	vector<pair<ll, ll> > g[2];
	for(ll i = 0; i < gadg; i++){
		ll type, cost;
		cin >> type >> cost;

		g[type - 1].push_back(make_pair(cost, i + 1));
	}

	sort(g[0].begin(), g[0].end());
	sort(g[1].begin(), g[1].end());

	ll l = 0, r = d - 1;
	while(l <= r){
		ll mid = (l + r) / 2;

		ll pos[] = {0, 0}, sum = 0;
		while(pos[0] + pos[1] < n){
			ll min = 1000000000000000000, index = 0;
			for(ll c = 0; c < 2; c++){
				if(pos[c] < g[c].size() and g[c][pos[c]].first * minm[c][mid] < min){
					min = g[c][pos[c]].first * minm[c][mid];
					index = c;
				}
			}

			pos[index]++;
			sum += min;
		}

		if(sum > m){
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	if(l >= d){
		cout << -1;
	} else {
		cout << l + 1 << endl;
		ll pos[] = {0, 0};
		while(pos[0] + pos[1] < n){
			ll min = 1000000000000000000, index = 0;
			for(ll c = 0; c < 2; c++){
				if(pos[c] < g[c].size() and g[c][pos[c]].first * minm[c][l] < min){
					min = g[c][pos[c]].first * minm[c][l];
					index = c;
				}
			}

			cout << g[index][pos[index]].second << ' ' << minmi[index][l] + 1 << endl;
			pos[index]++;
		}
	}
	return 0;
}
