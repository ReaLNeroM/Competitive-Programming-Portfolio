#include <iostream>

using namespace std;
typedef long long ll;

const int maxw = 3500;
int main() {
	ios::sync_with_stdio(false);
	int items;
	cin >> items;

	int dp[maxw + 1];
	for(int i = 0; i <= maxw; i++){
		dp[i] = 0;
	}

	for(int i = 0; i < items; i++){
		int v, w;
		cin >> v >> w;

		for(int j = maxw; j >= w; j--){
			if(dp[j] < dp[j - w] + v){
				dp[j] = dp[j - w] + v;
			}
		}
	}

	int encumbrance;
	cin >> encumbrance;

	cout << dp[encumbrance];
	return 0;
}
