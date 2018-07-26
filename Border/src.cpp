#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int gcd(int a, int b){
	if(b == 0){
		return a;
	}

	return gcd(b, a % b);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	int res = k;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		
		res = gcd(res, val[i] % k);
	}

	res = gcd(k, res);
	std::cout << k / res << '\n';
	for(int i = 0; i < k; i += res){
		std::cout << i << ' ';
		if(res == 0){
			break;
		}
	}
	std::cout << '\n';

}