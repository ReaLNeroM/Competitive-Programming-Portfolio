#include <bits/stdc++.h>
 
typedef long long ll;
 
const int maxn = 105;
int n, f;
std::vector<int> v[maxn];
std::vector<int> comp[maxn * maxn];

int score(){
	int x_accumulated = 0;
	int res = 0;
	for(int i = 0; i < n; i++){
		if(i * 2 == n){
			x_accumulated += f;
		}

		x_accumulated += v[i][0];
		res += x_accumulated * v[i][1];
	} 
	
	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> f;

	int curr = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		v[i] = {a, b};

		for(int j = 0; j < i; j++){
			comp[curr] = {i, j};
			curr++;
		}
	}

	std::srand(235325);

	int res = 0;

	for(int x = 0; x < 100; x++){
		for(int i = 0; i < n; i++){
			int aa = std::rand() % (i + 1);
			std::swap(v[i], v[aa]);
		}

		for(int i = 0; i < curr; i++){
			int aa = std::rand() % (i + 1);
			std::swap(comp[i], comp[aa]);
		}

		for(int i = 0; i < curr; i++){
			std::swap(v[comp[i][0]], v[comp[i][1]]);
			int now = score();
			if(res < now){
				res = now;
			} else {
				std::swap(v[comp[i][0]], v[comp[i][1]]);
			}
		}
	}


	std::cout << res << std::endl;
}