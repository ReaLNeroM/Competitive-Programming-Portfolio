#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;
const int INF = 1e9;
int n;
std::string s;
int dp[maxn][maxn];

int dpfunc(int pos, int lastm){
	if(dp[pos][lastm] != -1){
		return dp[pos][lastm];
	}

	int& ans = dp[pos][lastm];
	ans = INF;

	if(pos == n){
		ans = 0;
		return ans;
	}
	ans = dpfunc(pos + 1, lastm) + 1;
	if(lastm != pos){
		ans = std::min(ans, dpfunc(pos, pos) + 1);
	}

	std::string total = "";

	if(pos + pos - lastm < n){
		bool repeat = true;
		for(int j = lastm + 1; j <= pos; j++){
			if(s[j] != s[pos + (j - lastm)]){
				repeat = false;
				break;
			}
		}

		if(repeat){
			ans = std::min(ans, dpfunc(pos + pos - lastm, lastm) + 1);
		}
	}

	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> s;
	s = 'M' + s;

	n = s.size();

	memset(dp, -1, sizeof(dp));

	std::cout << dpfunc(1, 0) << '\n';
}