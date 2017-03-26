#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int sq = 400;
int val[maxn];
int swipe[maxn];
int span[maxn][sq];
int curr_swipe = 1;
int res[maxn];
int l[maxn], r[maxn];
int used[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
//		std::cin >> val[i];
		val[i] = i + 1;
		val[i]--;
	}

	for(int i = 1; i < sq and i <= n; i++){
		int pos = 0;
		int groups = 0;
		int curr_taken = i;
		while(pos < n){
			if(curr_taken == i){
				curr_swipe++;
				curr_taken = 0;
				groups++;
			}
			span[i][val[pos]] = curr_swipe;
			curr_taken++;
			pos++;
			while(pos < n and span[i][val[pos]] == curr_swipe){
				pos++;
			}
		}
		res[i] = groups;
	}

	//160 MB array, must be repurposed
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < sq; j++){
			span[i][j] = 0;
		}
	}

	int left = 0;
	for(int i = 0; i < sq; i++){
		left = i + 1;
		l[i] = i;
		r[i] = i - 1;
	}

	for(int i = sq; i <= n; i++){
		for(int j = 0; j < left; j++){
			while(j != 0 and l[j] <= r[j - 1]){
				if(l[j] <= r[j]){
					span[val[l[j]]][j]--;
					if(span[val[l[j]]][j] == 0){
						used[j]--;
					}
				}

				l[j]++;
				r[j] = std::max(l[j] - 1, r[j]);
			}
			while(r[j] != n - 1 and used[j] < i){
				r[j]++;
				span[val[r[j]]][j]++;
				used[j]++;
				while(r[j] != n - 1 and span[val[r[j] + 1]][j]){
					span[val[r[j] + 1]][j]++;
					r[j]++;
				}
			}

			if(r[j] == n - 1){
				left = j + 1;
			}
		}

		res[i] = left;
	}

	for(int i = 1; i <= n; i++){
		std::cout << res[i] << ' ';
	}
}
