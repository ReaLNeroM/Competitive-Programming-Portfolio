#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 10000;
int n;
ll dp[maxn][26];
ll nextval[maxn][26];
const ll mod = 1e9 + 7;
string s;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	cin >> s;

	for(int j = 0; j < 26; j++){
		nextval[n][j] = n;
	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++){
			if(j == s[i] - 'a'){
				nextval[i][j] = i;
			} else {
				nextval[i][j] = nextval[i + 1][j];
			}
		}
	}

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < 26; j++){
			dp[i][j] = 0;
		}
	}

	for(int j = 0; j < 26; j++){
		dp[n][j] = 1;
	}

	for(int i = n - 1; i >= 1; i--){
		for(int j = 0; j < 26; j++){
			dp[i][j] += dp[i + 1][j];
			for(int k = 0; k < 26; k++){
				if(k == j){
				} else if(k == s[i] - 'a'){
					dp[i][j] += dp[i + 1][k];
				} else {
					dp[i][j] += dp[nextval[i][k] + 1][k];
				}
				dp[i][j] %= mod;

			}
		}
	}

	ll sum = 0;
	for(int k = 0; k < 26; k++){
		if(k == s[0] - 'a'){
			sum += dp[1][k];
		} else {
			sum += dp[nextval[0][k] + 1][k];
		}
	}
	sum %= mod;

	cout << sum;
}

