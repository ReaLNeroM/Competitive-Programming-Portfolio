#include <iostream>

using namespace std;
typedef long long ll;

int dp[501][501];
int n, k;
int val[500];

int find(int left, int books){
	if(dp[left][books] == -1){
		if(left == n){
			dp[left][books] = 0;
		} else if(books == 0){
			dp[left][books] = 100000000;
		} else {
			dp[left][books] = 10000000;
			int sum = 0;
			for(int i = left; i < n; i++){
				sum += val[i];
				if(books > 0){
					dp[left][books] = min(dp[left][books], max(sum, find(i + 1, books - 1)));
				}
			}
		}
	}

	return dp[left][books];
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			dp[i][j] = -1;
		}
	}

	cout << find(0, k);
	return 0;
}
