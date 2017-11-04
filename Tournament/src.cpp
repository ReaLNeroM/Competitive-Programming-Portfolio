#include <bits/stdc++.h>

const int maxn = 1e5 + 1e2;
const int maxsports = 11;
int val[maxn][maxsports];
int sum[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, sports;
	std::cin >> n >> sports;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < sports; j++){
			std::cin >> val[i][j];
		}
	}

	std::map<int, int> m[maxsports];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < sports; j++){
			m[j][val[i][j]] = i;
		}
	}

	for(int i = 0; i < n; i++){
		int biggest = 0;
		for(int j = 0; j < sports; j++){
			auto ite = m[j].upper_bound(val[i][j]);
			if(ite == m[j].end()){
				biggest = n;
			} else {
				biggest = std::max(biggest, ite->second);
			}
		}

		if(biggest >= i){
			sum[i]++;
			sum[biggest]--;
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		res += sum[i];

		std::cout << res << '\n';
	}

	std::cout << '\n';
}