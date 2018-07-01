#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int maxsqrn = 1e3 + 1e2;
int val[maxn];
int aux[maxsqrn][maxsqrn];
int res[maxn];
int frequency[maxn];
std::vector<std::vector<int>> poracka[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < q; i++){
		int l, r, x, y;
		std::cin >> l >> r >> x >> y;

		poracka[l].push_back({i, x, y, -1});
		poracka[r + 1].push_back({i, x, y, 1});
	}

	for(int i = 0; i <= n; i++){
		for(auto& v : poracka[i]){
			if(v[1] <= 200){
				res[v[0]] += v[3] * aux[v[1]][v[2]];
			} else {
				int offset = v[2];
				while(offset <= 40000){
					res[v[0]] += v[3] * frequency[offset];
					offset += v[1];
				}
			}
		}

		for(int j = 1; j <= 200; j++){
			aux[j][val[i] % j]++;
		}
		frequency[val[i]]++;
	}

	for(int i = 0; i < q; i++){
		std::cout << res[i] << '\n';
	}
}
