#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll val[maxn][2];
ll points[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll tests;
	std::cin >> tests;

	for(ll test = 1; test <= tests; test++){
		ll signs;
		std::cin >> signs;

		memset(val, 0, sizeof(val));
		memset(points, 0, sizeof(points));

		for(ll i = 0; i < signs; i++){
			ll a, b, c;
			std::cin >> a >> b >> c;

			val[i][0] = a + b;
			val[i][1] = a - c;

			points[2 * i + 0] = val[i][0];
			points[2 * i + 1] = val[i][1];
		}

		ll res = 0;
		ll ways = 0;

		for(ll i = 0; i < signs; i++){
			for(ll j = i; j < signs; j++){
				bool possible = false;

				for(ll l = 2 * i; l < 2 * (j + 1) and !possible; l++){
					for(ll m = 2 * i; m < 2 * (j + 1) and !possible; m++){
						ll p1 = points[l];
						ll p2 = points[m];

						bool blocked = false;

						for(ll k = i; k <= j and !blocked; k++){
							if(val[k][0] != p1 and val[k][1] != p1 and val[k][0] != p2 and val[k][1] != p2){
								blocked = true;
							}
						}

						if(!blocked){
							possible = true;
						}
					}
				}

				if(possible){
					if(j - i + 1 == res){
						ways++;
					} else if(j - i + 1 > res){
						res = j - i + 1;
						ways = 1;
					}
				}
			}
		}

		std::cout << "Case #" << test << ": " << res << ' ' << ways << '\n';
	}
}
