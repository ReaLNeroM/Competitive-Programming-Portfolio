#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 600005;
const ll mod = 1e9 + 7;
int val[maxn];
int board[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	board[0] = 1;
	for(int i = 1; i < maxn; i++){
		board[i] = board[i - 1] * 2;
		board[i] %= mod;
	}

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}
	
	std::sort(val, val + n);

	ll res = 0;

	for(int i = 0; i < n - 1; i++){
		ll a = board[i + 1] - 1;
		if(a < 0){
			a += mod;
		}
		ll b = board[n - (i + 1)] - 1;
		if(b < 0){
			b += mod;
		}

		ll c = val[i + 1] - val[i];

		ll tmp = a * b;
		tmp %= mod;
		tmp *= c;
		tmp %= mod;

		res += tmp;
		res %= mod;
	}

	std::cout << res;
}
