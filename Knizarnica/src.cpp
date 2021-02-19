#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 300 + 5;
const int mod = 1000003;

int z[maxn];
int l[maxn];
int r[maxn];
std::vector<std::pair<int, int>> condition_by_end[maxn];
std::vector<int> condition_by_end_a[maxn];
std::vector<int> condition_by_end_b[maxn];

int dp[maxn][maxn][maxn];

int n, t;

int dpfunc(int l[3]){
	// reduces state space from 301^3 ~ 27 million to (301 choose 3) ~ 4.5 million.
	std::sort(l, l + 3);

	if(dp[l[0]][l[1]][l[2]] != -1){
		return dp[l[0]][l[1]][l[2]];
	}
	int& ans = dp[l[0]][l[1]][l[2]];
	ans = 0;

	int last = std::max(l[0], std::max(l[1], l[2]));
	if(last == n){
		ans = 1;
		return ans;
	}

	for(int i = 0; i < 3; i++){
		int newl[3];
		newl[0] = l[0];
		newl[1] = l[1];
		newl[2] = l[2];
		newl[i] = last + 1;

		bool satisfied = true;
		for(auto condition : condition_by_end[last + 1]){
			int uniques = condition.first;
			int start = condition.second;

			int found_uniques = 0;
			for(int j = 0; j < 3; j++){
				if(start <= newl[j]){
					found_uniques++;
				}
			}

			if(uniques != found_uniques){
				satisfied = false;
			}
		}

		if(satisfied){
			ans += dpfunc(newl);
			ans %= mod;
		}
	}

	return ans;
}

int main(){
	std::cin >> n >> t;

	for(int i = 0; i < t; i++){
		std::cin >> z[i] >> l[i] >> r[i];
		condition_by_end[r[i]].push_back({z[i], l[i]});
	}

	memset(dp, -1, sizeof(dp));

	int l[3];
	l[0] = 0, l[1] = 0, l[2] = 0;
	std::cout << dpfunc(l) << std::endl;
}
