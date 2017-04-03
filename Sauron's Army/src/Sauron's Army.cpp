#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 505;
const ll mod = 1e9 + 7;
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	val[0] = 1;
	val[1] = 0;
	for(ll i = 2; i < maxn; i++){
		val[i] = (i - 1) * (val[i - 1] + val[i - 2]);
		val[i] %= mod;
	}

	int n;
	cin >> n;

	cout << (val[n] + val[n - 1]) % mod;
}
