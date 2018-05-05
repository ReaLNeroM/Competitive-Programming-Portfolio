#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e5 + 1e2;
ll n, w, b, r;
ll val[maxn][3];
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

	while(taken[0] > v[0] or taken[1] > v[1] or taken[2] > v[2]){
		int above = 0;
		int below = 0;
		int aboveind = -1;
		int belowind = -1;

		for(int i = 0; i < 3; i++){
			if(taken[i] > v[i]){
				above++;
				aboveind = i;
			} else if(taken[i] < v[i]){
				below++;
				belowind = i;
			}
		}

		if(above == 1){
			//yo change it
		} else if(below == 1){

		}
	}
}