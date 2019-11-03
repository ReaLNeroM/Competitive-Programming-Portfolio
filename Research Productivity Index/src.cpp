#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 10;
int n;
int val[maxn];
long double dp[maxn][maxn][maxn];

long double f(int a, int s){
	if(a == 0 or s == 0){
		return 0.0;
	}

	return std::pow(a, (long double) a / s);
}

long double dpfunc(int currP, int submitted, int accepted){
	if(dp[currP][submitted][accepted] > -0.9){
		return dp[currP][submitted][accepted];
	}

	long double& ans = dp[currP][submitted][accepted];
	ans = 0.0;
	if(currP == submitted){
		if(accepted == 0){
			ans = 1.0;
		} else {
			ans = 0.0;
		}
		return ans;
	}

	long double acceptProbabilityForCurrentPaper = val[currP] / 100.0L;
	long double declineProbabilityForCurrentPaper = 1.0L - acceptProbabilityForCurrentPaper;
	ans += declineProbabilityForCurrentPaper * dpfunc(currP + 1, submitted, accepted);

	if(accepted != 0){
		ans += acceptProbabilityForCurrentPaper * dpfunc(currP + 1, submitted, accepted - 1);
	}

	return ans;
}


int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}
	std::sort(val, val + n, std::greater<int>());

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			for(int k = 0; k < maxn; k++){
				dp[i][j][k] = -1.0;
			}
		}
	}

	long double res = 0.0;
	for(int submit = 1; submit <= n; submit++){
		long double index = 0.0;
		for(int acc = 0; acc <= submit; acc++){
			long double probability = dpfunc(0, submit, acc);
			index += probability * f(acc, submit);
		}

		res = std::max(res, index);
	}

	std::cout.precision(12);
	std::cout << std::fixed << res << '\n';
}