#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e3 + 1e2;
const ll maxt = 1e4 + 1e2;
const ll mod = 1e9 + 7;
int ways[maxn][maxt];
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int n, t;
	cin >> n >> t;

	for(int i = 0; i < n; i++){
		cin >> val[i];
	}
	sort(val, val + maxn, greater<ll>());

	ways[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= t; j++){
			ways[i][j] = ways[i - 1][j];
			if(j >= val[i - 1]){
				ways[i][j] += ways[i - 1][j - val[i - 1]];
				ways[i][j] %= mod;
			}
		}
	}

	int res = 0;
	val[n] = 0;
	int sum = 0;

	for(int i = 0; i <= n; i++){
		sum += val[n - i];

		if(i == n){
			for(int j = t - val[n - i]; 0 <= j - sum; j--){
				if(j - sum >= 0){
					res += ways[n - i][j - sum];
					res %= mod;
				}
			}
		} else {
			for(int j = t - val[n - i]; t - val[n - i - 1] < j and 0 <= j - sum; j--){
				if(j - sum >= 0){
					res += ways[n - i][j - sum];
					res %= mod;
				}
			}
		}
	}

	cout << res;
}
