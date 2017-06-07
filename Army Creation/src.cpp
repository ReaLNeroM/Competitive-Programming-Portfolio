#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll maxsq = 320;
ll 
ll sq;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	sq = std::min(n, (int) std::ceil(std::sqrt(n)));

	for(int i = 0; i < sq; i++){
		int start = i * sq;
		for(int j = start; j < n; j++){
			if(j / sq != (j + 1) / sq){

			}
		}
	}
}