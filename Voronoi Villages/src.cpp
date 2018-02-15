#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int res = 2000000000;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::sort(val, val + n);

	for(int i = 1; i < n - 1; i++){
		res = std::min(res, val[i + 1] - val[i - 1]);
	}

	std::cout.precision(1);
	std::cout << std::fixed << res / 2.0 << '\n';
}