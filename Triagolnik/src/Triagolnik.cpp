#include <iostream>

using namespace std;
typedef long long ll;

int n;
int val[101][101];
int dp[101][101];
int lasty[101][101];
int lastx[101][101];

int find(int i, int j){
	if(dp[i][j] == -1){
		if(val[i][j] == -1){
		} else {

			int res = 100000000;
			if(val[i + 1][j] != -1 and res > find(i + 1, j)){
				res = dp[i + 1][j];
				lasty[i][j] = lasty[i + 1][j];
				lastx[i][j] = lastx[i + 1][j];
			}
			if(val[i][j + 1] != -1 and res > find(i, j + 1)){
				res = dp[i][j + 1];
				lasty[i][j] = lasty[i][j + 1];
				lastx[i][j] = lastx[i][j + 1];
			}
			if(val[i + 1][j + 1] != -1 and res > find(i + 1, j + 1)){
				res = dp[i + 1][j + 1];
				lasty[i][j] = lasty[i + 1][j + 1];
				lastx[i][j] = lastx[i + 1][j + 1];
			}

			dp[i][j] = val[i][j];;
			if(res == 100000000){
				lasty[i][j] = i;
				lastx[i][j] = j;
			} else {
				dp[i][j] += res;
			}
		}
	}

	return dp[i][j];
}
int main() {
	ios::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			val[i][j] = -1;
			dp[i][j] = -1;
			lasty[i][j] = -1;
			lastx[i][j] = -1;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			cin >> val[i][j - i];
		}
	}

	cout << find(0, 0) << endl;

	cout << lasty[0][0] + 1 << ' ' << lastx[0][0] + 1;
	return 0;
}
