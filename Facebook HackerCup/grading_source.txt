#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 305 + 10;

int s, h;
int mat[maxn][maxn];
int dp[maxn][maxn];
int tempmintotake[2 * maxn];
int mintotake[2 * maxn];
int currs = 0;

// for the given stack (currs), and for the given height and maximum number of
// context switches, this tells you how many books you need to remove from a
// given stack to ensure you don't exceed allowed number of context switches.
int dpfunc(int pos, int clusters){
	if(dp[pos][clusters] != -1){
		return dp[pos][clusters];
	}
	int& ans = dp[pos][clusters];
	if(pos == 0){
		ans = 0;
		return ans;
	}
	ans = pos;
	if(clusters == 0){
		return ans;
	}

	int currcost = 0;
	for(int i = pos; i > 0; i--){
		if(mat[currs][i - 1] != mat[currs][pos - 1]){
			currcost++;
		}
		if(currcost >= ans){
			break;
		}
		ans = std::min(ans, currcost + dpfunc(i - 1, clusters - 1));
	}

	return ans;
}

// essentially creates a reverse look-up table for the result i.e. we
// calculate FOR ALL N, if you want N context switches in total (with A as
// your first letter), you need to remove at least K books.
void solve(){
	tempmintotake[0] = s * h;
	for(int i = 1; i <= 2 * h; i++){
		tempmintotake[i] = 0;
	}

	for(int i = 0; i < s; i++){
		currs = i;
		for(int j = 0; j <= h + 1; j++){
			for(int k = 0; k <= 2 * h; k++){
				dp[j][k] = -1;
			}
		}

		for(int j = 1; j <= 2 * h; j++){
			int cost = 0;

			mat[i][h] = 0;
			cost = dpfunc(h + 1, j);
			
			tempmintotake[j] += cost;
		}
	}

	for(int i = 0; i <= 2 * h; i++){
		mintotake[i] = std::min(mintotake[i], tempmintotake[i]);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		std::cout << "Case #" << testcase << ": ";

		
				std::cerr << testcase << std::endl;

		int q;
		std::cin >> h >> s >> q;

		for(int i = 0; i < h; i++){
			for(int j = 0; j < s; j++){
				char c;
				std::cin >> c;

				mat[j][i] = (c == 'B');
			}
		}

		for(int i = 0; i < 2 * maxn; i++){
			mintotake[i] = s * h;
			tempmintotake[i] = s * h;
		}

		// assume we start with A first
		solve();
		for(int i = 0; i < s; i++){
			for(int j = 0; j < h; j++){
				mat[i][j] = !mat[i][j];
			}
		}

		//assume we start with B first
		solve();

		int most = 2 * h;
		for(int i = 0; i <= 2 * h; i++){
			if(mintotake[i] == 0){
				most = i;
				break;
			}
		}

		for(int i = 0; i < q; i++){
			int k;
			std::cin >> k;

			int best = most;
			int l = 0, r = most;
			while(l <= r){
				int mid = (l + r) / 2;

				if(mintotake[mid] <= k){
					best = mid;
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}

			std::cout << best << ' ';
		}
		std::cout << '\n';
	}
}
