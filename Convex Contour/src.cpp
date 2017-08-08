#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6;
int py[maxn], px[maxn];

double dist(double a, double b){
	return std::sqrt(a * a + b * b);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> py[i] >> px[i];
	}

	double best = 0.0;
	for(int i = 0; i < n; i++){
		for(int sidex = 0; sidex <= 1; sidex++){
			int l = (i + n - 1) % n, r = (i + 1) % n;
			int pos = i;
			int side = sidex;

			double curr = 0.0;
			for(int j = 0; j < n - 1; j++){
				if(side == 0){
					curr += dist(py[r] - py[pos], px[r] - px[pos]);
					pos = r;
					r = (r + 1) % n;
				} else {
					curr += dist(py[l] - py[pos], px[l] - px[pos]);
					pos = l;
					l = (l + n - 1) % n;
				}

				side = !side;
			}

			best = std::max(best, curr);
		}
	}

	std::cout.precision(10);

	std::cout << best << std::endl;
}