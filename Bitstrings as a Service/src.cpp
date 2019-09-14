#include <bits/stdc++.h>

typedef long long ll;

struct dsu {
	dsu* parent = this;
	ll rank = 0;
	ll size = 1;
	int tag = -1;

	dsu* head(){
		if(parent != parent->parent){
			parent = parent->head();
		}

		return parent;
	}

	void merge(dsu* sec){
		dsu* fir = head();
		sec = sec->head();

		if(fir != sec){
			fir->size = sec->size = fir->size + sec->size;

			if(fir->rank < sec->rank){
				std::swap(fir, sec);
			}

			if(fir->rank == sec->rank){
				fir->rank++;
			}

			sec->parent = fir;
		}
	}
};

const ll maxn = 10100;
const ll INF = 1000000000000000010;

dsu dsu_array[maxn];
static int dp[maxn][maxn];
static int par[maxn][maxn][2];

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){

		int n, k;
		std::cin >> n >> k;

		for(int i = 0; i < n; i++){
			dsu_array[i].parent = &dsu_array[i];
			dsu_array[i].rank = 0;
			dsu_array[i].size = 1;
			dsu_array[i].tag = -1;
		}

		for(int i = 0; i < k; i++){
			int l, r;
			std::cin >> l >> r;
			l--, r--;
			while(l < r){
				dsu_array[l].merge(&dsu_array[r]);
				l++, r--;
			}
		}

		std::vector<std::pair<int, int>> sizes;
		for(int i = 0; i < n; i++){
			if(dsu_array[i].head()->size != -1){
				sizes.push_back({dsu_array[i].head()->size, i});
				dsu_array[i].head()->size = -1;
				dsu_array[i].head()->tag = 0;
			}
		}

		for(int i = 0; i <= sizes.size(); i++){
			for(int j = 0; j <= n / 2; j++){
				dp[i][j] = 0;
				par[i][j][0] = par[i][j][1] = 0;
			}
		}

		dp[0][0] = 1;
		for(int i = 0; i < sizes.size(); i++){
			for(int j = 0; j <= n / 2; j++){
				if(!dp[i + 1][j]){
					dp[i + 1][j] |= dp[i][j];
					par[i + 1][j][0] = i;
					par[i + 1][j][1] = j;
				}
				if(j + sizes[i].first <= n / 2 and !dp[i + 1][j + sizes[i].first]){
					dp[i + 1][j + sizes[i].first] |= dp[i][j];
					par[i + 1][j + sizes[i].first][0] = i;
					par[i + 1][j + sizes[i].first][1] = j;
				}
			}
		}

		for(int i = n / 2; i >= 0; i--){
			if(dp[sizes.size()][i]){
				int curri = sizes.size();
				int currj = i;

				while(curri != 0 or currj != 0){
					int previ = par[curri][currj][0];
					int prevj = par[curri][currj][1];

					if(currj != prevj){
						dsu_array[sizes[previ].second].head()->tag = 1;
					}
					curri = previ;
					currj = prevj;
				}

				break;
			}
		}

		std::cout << "Case #" << testcase << ": ";

		for(int i = 0; i < n; i++){
			if(dsu_array[i].head()->tag == -1){
				return -1;
			}
			std::cout << dsu_array[i].head()->tag;
		}

		std::cout << '\n';
	}
}