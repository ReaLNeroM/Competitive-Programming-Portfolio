#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int val[maxn];
std::map<int, int> mapp;

int main(){
	std::ios::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i] %= m;
	}

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += val[i];
		sum %= m;
		mapp[sum]++;
	}

	sum = 0;
	ll res = 0;
	for(int i = 0; i < n; i++){
		res += mapp[sum % m];
		sum += val[i];
		sum %= m;
		mapp[sum]--;
	}

	std::cout << res << '\n';
}
