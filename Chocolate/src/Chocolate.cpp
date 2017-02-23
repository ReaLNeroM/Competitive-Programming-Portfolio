#include <iostream>

typedef long long ll;

int main(){
	ll cases;
	std::cin >> cases;

	ll res[cases];
	for(ll test = 0; test < cases; test++){
		ll x, y, pieces, people;
		std::cin >> x >> y >> pieces >> people;

		ll mat[x + 1][y + 1][people + 1];

		for(ll i = 0; i <= x; i++){
			for(ll j = 0; j <= y; j++){
				if(i * j >= pieces){
					mat[i][j][people - 1] = 1;
				} else {
					mat[i][j][people - 1] = 0;
				}
				mat[i][j][people] = 0;

				for(ll k = 0; k < people - 1; k++){
					mat[i][j][k] = 0;
					for(ll l = 0; l <= i; l++){
						if(l * j >= pieces){
							mat[i][j][k] += 2 * mat[i - l][j][k + 1];
						}
					}

					for(ll l = 0; l <= j; l++){
						if(l * i >= pieces){
							mat[i][j][k] += 2 * mat[i][j - l][k + 1];
						}
					}

					mat[i][j][k] %= 1000000007;
				}
			}

			mat[0][0][people] = 1;
		}

		res[test] = mat[x][y][0];
	}

	for(ll test = 0; test < cases; test++){
		std::cout << res[test] << std::endl;
	}
}
