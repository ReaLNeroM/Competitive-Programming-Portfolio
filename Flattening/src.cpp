#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int n;
int val[maxn];
int dp[21][maxn];
bool done[21][maxn];

int dpfunc(int bit, int bitset){
	if(done[bit][bitset]){
		return dp[bit][bitset];
	}

	done[bit][bitset] = true;
	int& ans = dp[bit][bitset];

	if(bit == 20){
		return ans;
	}

	ans += dpfunc(bit + 1, bitset);
	if(bitset & (1 << bit)){
		ans += dpfunc(bit + 1, bitset ^ (1 << bit));
	}

	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);

	int test_cases;
	std::cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++){
		std::cin >> n;

		for(int i = 0; i < n; i++){
			std::cin >> val[i];
		}

		std::sort(val, val + maxn);

		for(int i = 0; i < 21; i++){
			for(int j = 0; j <= val[n - 1]; j++){
				dp[i][j] = 0;
				done[i][j] = false;
			}
		}

		for(int i = 0; i < n; i++){
			dp[20][val[i]]++;
		}

		int res = 0;
		for(int i = 0; i < n; i++){
			res += dpfunc(0, val[i]);
		}

		std::cout << res << '\n';
	}
}
