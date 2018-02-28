#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int a, b, c;
	std::cin >> a >> b >> c;

	int res = 10000;
	for(int i = 1; i <= 100; i++){
		int attempt = std::abs(a - i) + std::abs(b - i) + std::abs(c - i);
		
		if(attempt < res){
			res = attempt;
		}
	}

	std::cout << res * 10;
}