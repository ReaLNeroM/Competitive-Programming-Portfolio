#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5;
ll val[maxn];

int main(){
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
		if(i != 0){
			val[i - 1] = abs(val[i] - val[i - 1]);
		}
	}
	n--;
	for(int i = 1; i < n; i += 2){
		val[i] *= -1;
	}

	ll best = -1e18;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum = max(sum, 0LL) + val[i];
		best = max(best, sum);
	}

	for(int i = 0; i < n; i++){
		val[i] *= -1;
	}

	sum = 0;
	for(int i = 0; i < n; i++){
		sum = max(sum, 0LL) + val[i];
		best = max(best, sum);
	}

	cout << best;
}