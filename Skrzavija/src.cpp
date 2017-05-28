#include <bits/stdc++.h>

typedef long long ll;

const ll maxpeople = 55;
const ll maxquestions = 20005;
const ll maxgroups = 55;
const ll INF = 1e15;

ll people, questions, groups;
ll prize[maxquestions];
ll correct[maxpeople][maxquestions];
ll dp[maxquestions][maxgroups];
ll sum[5000][5000];

ll dfs(ll pos, ll left){
	if(dp[pos][left] == -1){
		if(pos == questions){
			if(left != 0){
				dp[pos][left] = INF;
			} else {
				dp[pos][left] = 0;
			}
		} else {
			if(left == 1){
				dp[pos][left] = sum[pos][questions - 1];
			} else {
				dp[pos][left] = INF;

				for(ll i = pos; i < questions; i++){
					dp[pos][left] = std::min(dp[pos][left], sum[pos][i] + dfs(i + 1, left - 1));
				}
			}
		}
	}

	return dp[pos][left];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> people >> questions >> groups;

	for(ll i = 0; i < questions; i++){
		std::cin >> prize[i];
	}

	for(ll i = 0; i < people; i++){
		std::string s;
		std::cin >> s;

		for(ll j = 0; j < questions; j++){
			if(s[j] == '1'){
				correct[i][j] = true;
			} else {
				correct[i][j] = false;
			}
		}
	}

	for(int i = 0; i < people; i++){
		for(int j = 0; j < questions; j++){
			ll runningsum = 0;
			for(int k = j; k < questions; k++){
				if(!correct[i][k]){
					break;
				}

				runningsum += prize[k];
				sum[j][k] += runningsum;
			}
		}
	}

	for(int i = 0; i < maxquestions; i++){
		for(int j = 0; j < maxgroups; j++){
			dp[i][j] = -1;
		}
	}

	for(ll i = 1; i <= groups; i++){
		std::cout << dfs(0, i) << '\n';
	}
}