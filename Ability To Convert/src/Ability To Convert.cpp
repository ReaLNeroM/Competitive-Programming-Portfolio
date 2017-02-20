#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int max_digs = 105;
const int maxn = 65;
ll dp[max_digs][maxn];
ll n;
ll biggest = 1000000000000000000;
string s_biggest = "1000000000000000000";
string k;

ll smaller(string s, ll num){
	if(s.size() > s_biggest.size() or (s.size() == s_biggest.size() and s > s_biggest)){
		return -1;
	}

	ll gen = 0;
	for(int i = 0; i < s.size(); i++){
		gen *= 10;
		gen += s[i] - '0';
	}

	if(gen < num){
		return gen;
	} else {
		return -1;
	}
}

ll fucking_peasant_multiplication(ll a, ll b){
	ll orig = a;
	a = 0;

	while(b != 0){
		if(b % 2 == 1){
			a += orig;
		}
		if(a > biggest){
			return -2;
		}
		b /= 2;
		orig *= 2;
		if(b != 0 and orig > biggest){
			return -2;
		}
	}

	return a;
}

ll dfs(int digs_left, int pos){
	if(dp[digs_left][pos] == -1){
		ll &ans = dp[digs_left][pos];
		if(pos == k.size()){
			ans = 0;
		} else if(digs_left == 0){
			ans = biggest + 1;
		} else {
			ans = biggest + 1;
			if(k[pos] == '0'){
				ans = dfs(digs_left - 1, pos + 1);
			} else {
				for(int i = k.size() - 1; i >= pos; i--){
					string gen = "";
					for(int j = pos; j <= i; j++){
						gen += k[j];
					}

					if(smaller(gen, n) != -1){
						ll tryy = smaller(gen, n);
						for(int j = 0; j < digs_left - 1; j++){
							tryy = fucking_peasant_multiplication(tryy, n);
							if(tryy == -2LL){
								tryy = ans;
								break;
							}
						}
						tryy += dfs(digs_left - 1, i + 1);

						if(tryy <= biggest and tryy < ans){
							ans = tryy;
						}
					}
				}
			}
		}
	}

	return dp[digs_left][pos];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> k;

	for(int i = 0; i < max_digs; i++){
		for(int j = 0; j < maxn; j++){
			dp[i][j] = -1;
		}
	}

	for(ll digs = 1; digs <= 100; digs++){
		if(dfs(digs, 0) <= biggest){
			cout << dfs(digs, 0) << endl;
			break;
		}
	}
}
