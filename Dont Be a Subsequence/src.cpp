#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int val[maxn];
int next[maxn][26];
int dp[maxn];
int dpnext[maxn];
char dpnextc[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;

	std::string s;
	std::cin >> s;

	n = s.size();

	for(int i = 0; i < 26; i++){
		next[n][i] = n;
	}

	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			next[i][j] = next[i + 1][j];
		}
		next[i][s[i] - 'a'] = i;
	}

	dp[n] = 0;
	dp[n - 1] = 0;

	for(int i = n - 2; i >= 0; i--){
		dp[i] = maxn;

		for(int j = 0; j < 26; j++){
			int get = next[i][j];

			int attempt = 1 + dp[get + 1];

			if(dp[i] > attempt){
				dp[i] = attempt;
				dpnext[i] = get + 1;
				dpnextc[i] = 'a' + j;
			}
		}
	}

	std::string res = "";
	int pos = 0;
	while(pos < n - 1){
		res += dpnextc[pos];
		pos = dpnext[pos];
	}

	std::cout << res << '\n';
}