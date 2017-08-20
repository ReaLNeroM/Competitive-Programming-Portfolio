#include <bits/stdc++.h>

typedef long long ll;

const ll mod = 1e9 + 7;
const ll maxn = 25;
const long double INF = 1e100;

ll mat[maxn][maxn];
long double matd[maxn][maxn];
ll old[maxn][maxn];
long double oldd[maxn][maxn];
ll nnew[maxn][maxn];
long double nnewd[maxn][maxn];
ll res[maxn][maxn];
long double resd[maxn][maxn];
ll oldres[maxn][maxn];
long double oldresd[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, money, start, end, operations;
	std::cin >> n >> money >> start >> end >> operations;

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			std::cin >> mat[i][j];
			matd[i][j] = std::log(mat[i][j]);

			resd[i][j] = -INF;
			oldd[i][j] = -INF;
            nnewd[i][j] = -INF;
            oldresd[i][j] = -INF;
		}

		res[i][i] = 1;
		resd[i][i] = 0.0;
		old[i][i] = 1;
		oldd[i][i] = 0.0;
	}

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			for(ll k = 0; k < n; k++){
				nnewd[i][j] = std::max(nnewd[i][j], oldd[i][k] + matd[k][j]);
				nnew[i][j] = std::max(nnew[i][j], (old[i][k] * mat[k][j]) % mod);
			}
		}
	}

	for(ll x = 1; x <= operations; x *= 2){
		if(x & operations){
			for(ll i = 0; i < n; i++){
				for(ll j = 0; j < n; j++){
					oldres[i][j] = res[i][j];
					res[i][j] = 0;

					oldresd[i][j] = resd[i][j];
					resd[i][j] = -INF;
				}
			}

			for(ll i = 0; i < n; i++){
				for(ll j = 0; j < n; j++){
					for(ll k = 0; k < n; k++){
						if(resd[i][j] < oldresd[i][k] + nnewd[k][j]){
							resd[i][j] = oldresd[i][k] + nnewd[k][j];
							res[i][j] = (oldres[i][k] * nnew[k][j]) % mod;
						}
					}
				}
			}
		}

		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				old[i][j] = nnew[i][j];
				nnew[i][j] = 0;

				oldd[i][j] = nnewd[i][j];
				nnewd[i][j] = -INF;
			}
		}

		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				for(ll k = 0; k < n; k++){
					if(nnewd[i][j] < oldd[i][k] + oldd[k][j]){
						nnewd[i][j] = oldd[i][k] + oldd[k][j];
						nnew[i][j] = (old[i][k] * old[k][j]) % mod;
					}
				}
			}
		}
	}

	std::cout << (money * res[start][end]) % mod << '\n';
}
