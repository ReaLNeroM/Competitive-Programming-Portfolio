#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e4;
const double eps = 1e-11;
int val[maxn];
double dp[maxn];
double achieved[maxn];
int orbs, q;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> orbs >> q;

	dp[0] = 1.0;

	for(int i = 1; i < maxn; i++){
		for(int j = orbs - 1; j >= 0; j--){
			double eempty = orbs - j;
			eempty /= (double) orbs;
			dp[j + 1] += eempty * dp[j];

			eempty = j;
			eempty /= (double) orbs;
			dp[j] = dp[j] * eempty;
		}
		achieved[i] = dp[orbs];
	}

	for(int i = 0; i < q; i++){
		double v;
		cin >> v;
		v -= eps;
		v /= (double) 2000.0;

		for(int j = 1; j < maxn; j++){
			if(achieved[j] > v){
				cout << j << endl;
				break;
			}
		}
	}

}

