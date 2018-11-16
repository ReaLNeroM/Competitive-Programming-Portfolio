#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 110;
int dp[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::string p;
	std::cin >> p;

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::string s;
		std::cin >> s;

		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < p.size(); j++){
				if(dp[i][j]){
					if(p[j] == '*'){
						dp[i][j + 1] = 1;
						dp[i + 1][j + 1] = 1;
						dp[i + 1][j] = true;
					} else if(s[i] == p[j]){
						dp[i + 1][j + 1] = true;
					}
				}
			}
		}

		if(dp[s.size()][p.size()]){
			std::cout << s << '\n';
		}
	}
}