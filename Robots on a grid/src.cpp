#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
const ll mod = 2147483647;
ll n;
static char c[maxn][maxn];
static ll ways[maxn][maxn];
const ll ay[] = {1, -1, 0, 0};
const ll ax[] = {0, 0, 1, -1};

bool path(){
	std::queue<ll> qy, qx;
	qy.push(0), qx.push(0);
	c[0][0] = '#';

	while(!qy.empty()){
		ll fry = qy.front();
		ll frx = qx.front();
		qy.pop(), qx.pop();

		if(fry == n - 1 and frx == n - 1){
			return true;
		}

		for(ll i = 0; i < 4; i++){
			ll ny = fry + ay[i];
			ll nx = frx + ax[i];

			if(0 <= ny and ny < n and 0 <= nx and nx < n and c[ny][nx] != '#'){
				c[ny][nx] = '#';
				qy.push(ny);
				qx.push(nx);
			}
		}
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			std::cin >> c[i][j];
		}
	}

	ways[n - 1][n - 1] = 1;

	for(ll i = n - 1; i >= 0; i--){
		for(ll j = n - 1; j >= 0; j--){
			if(c[i][j] != '#'){
				if(i != 0 and c[i - 1][j] != '#'){
					ways[i - 1][j] += ways[i][j];
					ways[i - 1][j] %= mod;
				}
				if(j != 0 and c[i][j - 1] != '#'){
					ways[i][j - 1] += ways[i][j];
					ways[i][j - 1] %= mod;
				}
			}
		}
	}

	if(ways[0][0]){
		std::cout << ways[0][0] << '\n';
	} else if(path()){
		std::cout << "THE GAME IS A LIE";
	} else {
		std::cout << "INCONCEIVABLE";
	}
}