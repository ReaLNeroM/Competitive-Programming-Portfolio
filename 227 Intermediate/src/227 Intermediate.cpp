#include <iostream>
#include <queue>

typedef long long ll;

int main() {
	std::ios_base::sync_with_stdio(false); //speeds up cin
	ll y, x;
	std::cin >> y >> x;

	bool mat[y][x];
	for(ll i = -1; i < y; i++){ // -1 because the first getline fails
		std::string str;
		std::getline(std::cin, str);

		for(ll j = 0; j < str.length(); j++){
			mat[i][j] = (str[j] == 'x');
		}
	}

	ll res = 0;
	std::queue<ll> qy, qx;
	for(ll i = 0; i < y; i++){
		for(ll j = 0; j < x; j++){
			if(mat[i][j]){
				res++;
				qy.push(i), qx.push(j);

				while(!qy.empty()){
					ll qyfront = qy.front(), qxfront = qx.front();
					qy.pop(), qx.pop();

					if(qyfront > 0 and mat[qyfront - 1][qxfront]){
						mat[qyfront - 1][qxfront] = false;

						qy.push(qyfront - 1);
						qx.push(qxfront);
					}
					if(qxfront > 0 and mat[qyfront][qxfront - 1]){
						mat[qyfront][qxfront - 1] = false;

						qy.push(qyfront);
						qx.push(qxfront - 1);
					}
					if(qyfront < y - 1 and mat[qyfront + 1][qxfront]){
						mat[qyfront + 1][qxfront] = false;

						qy.push(qyfront + 1);
						qx.push(qxfront);
					}
					if(qxfront < x - 1 and mat[qyfront][qxfront + 1]){
						mat[qyfront][qxfront + 1] = false;

						qy.push(qyfront);
						qx.push(qxfront + 1);
					}
				}
			}
		}
	}

	std::cout << res;
	return 0;
}
