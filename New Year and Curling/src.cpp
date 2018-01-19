#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int x[maxn];
double y[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::cout.precision(10);

	int n, r;
	std::cin >> n >> r;

	for(int i = 0; i < n; i++){
		std::cin >> x[i];
	}

	for(int i = 0; i < n; i++){
		double& highest = y[i];
		highest = r;

		for(int j = 0; j < i; j++){
			if(std::abs(x[j] - x[i]) <= 2 * r){
				highest = std::max(highest, sqrt(4 * r * r - (x[j] - x[i]) * (x[j] - x[i])) + y[j]);
			}
		}

		std::cout << std::fixed << y[i] << ' ';
	}

	std::cout << '\n';
}