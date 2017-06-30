#include "mountains.h"
#include <vector>
#include <bits/stdc++.h>

typedef long long ll;
const ll maxn = 2e3 + 1e2;

ll n;
bool gleda[maxn][maxn];
int will_block[maxn];
bool blocked[maxn];
std::multiset<std::vector<int> > m;

int maximum_deevs(std::vector<int> y) {
	n = y.size();
	for(ll i = 0; i + 1 < y.size(); i++){
		ll a = y[i + 1] - y[i];
		ll b = 1;
		for(ll j = i + 1; j < y.size(); j++){
			ll c = y[j] - y[i];
			ll d = j - i;
			if(a * d <= c * b){
				std::cout << i << ' ' << j << std::endl;
				gleda[i][j] = true;
				gleda[j][i] = true;
				will_block[i]++;
				will_block[j]++;
				a = c;
				b = d;
			}
		}
	}

	for(int i = 0; i < n; i++){
		m.insert({will_block[i], i});
	}

	ll res = 0;

	while(!m.empty()){
		auto v = *m.begin();
		int ind = v[1];
		m.erase(m.begin());
		if(blocked[ind]){
			continue;
		}
		blocked[ind] = true;
		res++;

		for(int i = 0; i < n; i++){
			if(gleda[ind][i] and !blocked[i]){
				blocked[i] = true;
				for(int j = 0; j < n; j++){
					if(gleda[i][j] and !blocked[j]){
						m.erase(m.find({will_block[j], j}));
						will_block[j]--;
						m.insert({will_block[j], j});
					}
				}
			}
		}
	}

	return res;
}
