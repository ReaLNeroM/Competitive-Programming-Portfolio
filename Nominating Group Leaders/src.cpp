#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int maxsqrn = 350;

struct query {
	int l, r, x;
	int block_l;
	int ind;

	bool operator<(const query& a){
		if(block_l == a.block_l){
			return r < a.r;
		} else {
			return block_l < a.block_l;
		}
	}
};

int sqrn;

int val[maxn];
int vote[maxn];
int votes[maxn];
int found[maxn][maxsqrn];
query queries[maxn];
int res[maxn];

void add(int pos){
	if(votes[vote[pos]] != 0){
		found[votes[vote[pos]]][vote[pos] / sqrn]--;
	}
	votes[vote[pos]]++;
	found[votes[vote[pos]]][vote[pos] / sqrn]++;
}

void remove(int pos){
	found[votes[vote[pos]]][vote[pos] / sqrn]--;
	votes[vote[pos]]--;
	if(votes[vote[pos]] != 0){
		found[votes[vote[pos]]][vote[pos] / sqrn]++;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test_case = 0; test_case < t; test_case++){
		int n;
		std::cin >> n;

		memset(votes, 0, sizeof(votes));
		memset(found, 0, sizeof(found));

		for(int i = 0; i < n; i++){
			std::cin >> vote[i];
		}

		sqrn = std::max(1, (int) std::sqrt(n));

		int q;
		std::cin >> q;

		for(int i = 0; i < q; i++){
			std::cin >> queries[i].l >> queries[i].r >> queries[i].x;
			queries[i].block_l = queries[i].l / sqrn;
			queries[i].ind = i;
		}

		std::sort(queries, queries + q);

		int l = 0, r = -1;
		for(int i = 0; i < q; i++){
			while(r < queries[i].r){
				r++;
				add(r);
			}
			while(l > queries[i].l){
				l--;
				add(l);
			}
			while(queries[i].r < r){
				remove(r);
				r--;
			}
			while(queries[i].l > l){
				remove(l);
				l++;
			}

			int needed = queries[i].x;

			res[queries[i].ind] = -1;

			for(int j = 0; j * sqrn < n; j++){
				if(found[needed][j]){
					for(int k = j * sqrn; k < (j + 1) * sqrn; k++){
						if(votes[k] == needed){
							res[queries[i].ind] = k;
							j = n, k = n;
							break;
						}
					}
				}
			}

		}

		for(int i = 0; i < q; i++){
			std::cout << res[i] << '\n';
		}
	}
}
