#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e5 + 1e2;
ll n, w, b, r;
ll v[3];
ll val[maxn][3];
 
int main(){
	std::ios::sync_with_stdio(false);
 
	std::cin >> v[0] >> v[1] >> v[2] >> n;
 
	int res = 0;
	for(ll i = 0; i < n; i++){
		std::cin >> val[i][0] >> val[i][1] >> val[i][2];
		res += *std::min_element(&val[i][0], &val[i][0] + 3);
	}

	for(int i = v[0]; i <= n; i++){
		for(int j = v[1]; j <= n; j++){
			for(int k = v[2]; k <= n; k++){
				res = std::max(res, f(i, j, k) + offset);
			}
		}
	}
	std::cout << res << '\n';
}
