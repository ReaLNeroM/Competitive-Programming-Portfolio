#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;
const int max_sq = 320;
int res[maxn][max_sq];
int val[maxn];
int eend[maxn];
int l[maxn], r[maxn], k[maxn];
vector<pair<int, int> > blocks;

int main(){
	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		int n, q;
		cin >> n >> q;

		for(int i = 0; i < n; i++){
			cin >> val[i];
		}
		int sq = sqrt(n) + 1;
		int extent = 0;
		for(int i = 0; i < sq; i++){
			res[0][i] = 0;
		}

		blocks.clear();
		for(int i = 1; i <= n; i++){
			if(i == 1 or val[i - 1] != val[i - 2]){
				if(i != 1 and extent >= sq){
					blocks.push_back({i - extent, i - 1});
				}
				extent = 1;
			} else {
				extent++;
			}
			if(i == n){
				blocks.push_back({i - extent + 1, i});
			}

			for(int j = 0; j < sq; j++){
				res[i][j] = res[i - 1][j];
			}
			if(extent < sq){
				res[i][extent]++;
			}
		}

		for(int i = n; i >= 1; i--){
			if(i == n or val[i] != val[i - 1]){
				eend[i] = i;
			} else {
				eend[i] = eend[i + 1];
			}
		}

		for(int i = 0; i < q; i++){
			cin >> l[i] >> r[i] >> k[i];
			if(k[i] < sq){
				int nnext = eend[l[i]];

				cout << res[r[i]][k[i]] - res[nnext][k[i]] + (eend[l[i]] - l[i] + 1 >= k[i]) << '\n';
			} else {
				int ans = 0;
				for(int j = 0; j < blocks.size(); j++){
					if(min(blocks[j].second, r[i]) - max(blocks[j].first, l[i]) + 1 >= k[i]){
						ans++;
					}
				}

				cout << ans << '\n';
			}
		}
	}
}
