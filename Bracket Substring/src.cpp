#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e2 + 1e2;
const ll mod = 1e9 + 7;
static ll dp[maxn][maxn];
static ll dp2[maxn][maxn][maxn];
ll jump[maxn][2];
bool valid[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;
	n *= 2;

	std::string s;
	std::cin >> s;

	ll lowest_prefix_sum = 0;
	ll final_sum = 0;

	for(char i : s){
		if(i == '('){
			final_sum++;
		} else {
			final_sum--;
		}

		lowest_prefix_sum = std::min(lowest_prefix_sum, final_sum);
	}

	memset(jump, -1, sizeof(jump));
	for(int i = 0; i < s.size(); i++){
		std::string cop;

		if(s[i] == '('){
			jump[i][0] = i + 1;

			cop = s.substr(0, i) + ')';
			while(!cop.empty() and s.substr(0, cop.size()) != cop){
				cop.erase(cop.begin());
			}
			jump[i][1] = cop.size();
		} else {
			cop = s.substr(0, i) + '(';
			while(!cop.empty() and s.substr(0, cop.size()) != cop){
				cop.erase(cop.begin());
			}
			jump[i][0] = cop.size();
			
			jump[i][1] = i + 1;
		}
	}

	valid[0] = true;
	for(int i = 1; i < s.size(); i++){
		std::string cop = s.substr(0, i) + s;

		if(cop.substr(0, s.size()) == s){
			valid[i] = false;
		} else {
			valid[i] = true;
		}
	}

	dp[0][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= n; j++){
			dp[i][j] = 0;
			if(j != n)
				dp[i][j] += dp[i - 1][j + 1];
			if(j != 0)
				dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}

	dp2[0][0][0] = 1;
	for(ll i = 0; i <= n; i++){
		for(ll j = 0; j <= n; j++){
			for(ll k = 0; k < s.size(); k++){
				if(j != n){
					dp2[i + 1][j + 1][jump[k][0]] += dp2[i][j][k];
					dp2[i + 1][j + 1][jump[k][0]] %= mod;
				}
				if(j != 0){
					dp2[i + 1][j - 1][jump[k][1]] += dp2[i][j][k];
					dp2[i + 1][j - 1][jump[k][1]] %= mod;
				}
			}
		}
	}

	ll res = 0;
	for(ll i = 0; i + s.size() <= n; i++){
		for(ll j = -lowest_prefix_sum; j <= i; j++){
			for(int k = 0; k < s.size(); k++){
				if(valid[k]){
					res += dp2[i][j][k] * dp[n - ((int) s.size()) - i][j + final_sum];
					res %= mod;
				}
			}
		}
	}

	std::cout << res << '\n';
}
