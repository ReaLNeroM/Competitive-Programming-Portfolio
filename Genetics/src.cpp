#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 4105;
const ll base = 62;
static ll dist[maxn][maxn];
bool blocked[maxn];
ll indx[maxn];
std::string val[maxn];
std::vector<ll> v[maxn];

ll calc_diff(ll a, ll b){
	ll sum = 0;

	for(ll i = 0; i < v[a].size(); i++){
		sum += __builtin_popcountll(v[a][i] ^ v[b][i]);
	}

	return sum;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n, m, k;
	std::cin >> n >> m >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		v[i].resize((m + base - 1) / base);
		for(ll j = 0; j < m; j += base){
			for(ll k = j; k < j + base and k < m; k++){
				v[i][j / base] += (1LL << (k - j)) * ((ll) (val[i][k] == 'C'));
			}
		}

		indx[i] = i;
	}

	memset(dist, -1, sizeof(dist));
	std::random_shuffle(indx, indx + n);

	for(ll i = 0; i < n; i++){
		for(ll j = i + 1; j < n; j++){
			ll differences = calc_diff(indx[i], indx[j]);

			dist[indx[i]][indx[j]] = dist[indx[j]][indx[i]] = differences;
			if(dist[indx[i]][indx[j]] != k){
				blocked[indx[i]] = blocked[indx[j]] = true;
			}
		}
	}

	for(ll i = 0; i < n; i++){
		if(!blocked[i]){
			std::cout << i + 1 << '\n';
			break;
		}
	}
}