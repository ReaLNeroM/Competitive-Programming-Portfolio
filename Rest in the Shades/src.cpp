#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int lX1[maxn], lX2[maxn];
int pY[maxn], pX[maxn];
long double res[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int pathY, pathX1, pathX2;
	std::cin >> pathY >> pathX1 >> pathX2;
	pathY *= -1;

	int n;
	std::cin >> n;

	long double badSum = 0.0;
	long double goodSum = 0.0;

	for(int i = 0; i < n; i++){
		std::cin >> lX1[i] >> lX2[i];
		badSum += lX1[i];
		goodSum += lX2[i];
	}

	long double res = 0.0;

	int q;
	std::cin >> q;

	for(int i = 0; i < q; i++){
		std::cin >> pX[i] >> pY[i];
	}

	for(int i = 0; i < q; i++){
		long double pYDouble = pY[i];
		long double pXDouble = pX[i];
		long double pathYDouble = pathY;
		long double nDouble = n;

		res = 0.0;

		res += nDouble * (pYDouble + pathYDouble) / pYDouble * (goodSum / nDouble - pXDouble);
		res -= nDouble * (pYDouble + pathYDouble) / pYDouble * (badSum / nDouble - pXDouble);

		std::cout.precision(9);

		std::cout << std::fixed << res << '\n';
	}
}
