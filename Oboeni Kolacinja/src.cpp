#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e5 + 1e2;
ll n, w, b, r;
ll val[maxn][3];
ll copy[maxn][3];
ll ind[maxn][3];
bool used[maxn][3];
ll taken[3];
ll v[3];
ll res = 0;
 
int main(){
	std::ios::sync_with_stdio(false);
 
	std::cin >> v[0] >> v[1] >> v[2] >> n;
 
	for(ll i = 0; i < n; i++){
		std::cin >> val[i][0] >> val[i][1] >> val[i][2];
		for(ll j = 0; j < 3; j++){
			copy[i][j] = val[i][j];
		}
		std::sort(&copy[i][0], &copy[i][0] + 3);
 
		for(ll j = 0; j < 3; j++){
			for(ll k = 0; k < 3; k++){
				if(val[i][k] == copy[i][j] and !used[i][k]){
					used[i][k] = true;
					ind[i][j] = k;
					break;
				}
			}
		}
	}

	for(ll i = 0; i < n; i++){
		ll biggest = copy[i][2];

		taken[ind[i][2]]++;

		res += biggest;
	}

	if(taken[0] > v[0] or taken[1] > v[1] or taken[2] > v[2]){
		ll changes = std::max(0LL, taken[0] - v[0])
										+ std::max(0LL, taken[1] - v[1])
										+ std::max(0LL, taken[2] - v[2]);
		ll above = 0;
		ll below = 0;
		ll aboveind = -1;
		ll belowind = -1;

		for(ll i = 0; i < 3; i++){
			if(taken[i] > v[i]){
				above++;
				aboveind = i;
			} else if(taken[i] < v[i]){
				below++;
				belowind = i;
			}
		}

		if(above == 1 and below == 1){
			int otherind = -1;
			for(int i = 0; i < 3; i++){
				if(i != belowind and i != aboveind){
					otherind = i;
				}
			}

			std::vector<ll> diffs;
			std::vector<ll> conv[2];
			for(ll i = 0; i < n; i++){
				if(ind[i][2] == aboveind){
					diffs.push_back(val[i][aboveind] - val[i][belowind]);
				}
			}
			for(ll i = 0; i < n; i++){
				if(ind[i][2] == aboveind){
					conv[0].push_back(val[i][aboveind] - val[i][otherind]);
				} else if(ind[i][2] == otherind){
					conv[1].push_back(val[i][otherind] - val[i][belowind]);
				}
			}

			std::sort(diffs.begin(), diffs.end());
			std::sort(conv[0].begin(), conv[0].end());
			std::sort(conv[1].begin(), conv[1].end());

			int a_pos = 0;
			int b_pos = 0;

			for(ll i = 0; i < changes; i++){
				if(a_pos != diffs.size() and )
			}
		} else {
			return -1;
			if(above == 1){
				//yo change it
			} else if(below == 1){

			}
		}
	}

	std::cout << res << '\n';
}
