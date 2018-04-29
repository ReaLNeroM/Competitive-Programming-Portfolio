#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e5 + 1e2;
ll n, w, b, r;
ll val[maxn][3];
ll copy[maxn][3];
ll ind[maxn][3];
ll size[3];
bool used[maxn][3];
std::multiset<std::vector<ll> > taken[3];
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
		ll smallest = copy[i][0];
		res += smallest;

		ll biggest = copy[i][2] - copy[i][0];

		taken[ind[i][2]].insert({copy[i][2] - copy[i][1], 2, i});
		size[ind[i][2]]++;

		res += biggest;
	}

	bool problem = true;
	do {
		problem = false;
		for(ll j = 0; j < 3; j++){
			while(size[j] > v[j]){
				problem = true;

				if(taken[j].empty()){
					//ne treba da se dese be
					std::cerr << "WTF\n";
					return 0;
				}

				std::vector<ll> vv = (*taken[j].begin());
				taken[j].erase(taken[j].begin());
				size[j]--;

				res -= vv[0];

				if(vv[1] == 2){
					vv[1]--;
					vv[0] = copy[vv[2]][vv[1]] - copy[vv[2]][vv[1] - 1];
					taken[ind[vv[2]][vv[1]]].insert(vv);
					size[ind[vv[2]][1]]++;
				} else {
					size[ind[vv[2]][0]]++;
				}
			}
		}
	} while(problem);
 
	std::cout << res;
}
