#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

long double getDist(long double w, long double g, long double h, long double r, long double a){
	long double a1 = std::sqrt(a * a + (r - g) * (r - g));
	long double a2 = std::sqrt((w - a) * (w - a) + (h - r) * (h - r));

	return a1 + a2;
}


int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		long double w, g, h, r;
		std::cin >> w >> g >> h >> r;

		long double minX = std::sqrt(w * w + (h - g) * (h - g));

		long double l = 0.0L;
		long double rr = w;
		long double maxX = 1e18;

		for(int i = 0; i < 500; i++){
			long double try1 = l + (rr - l) / 3.0L;
			long double try2 = l + 2.0L * (rr - l) / 3.0L;

			long double dist1 = getDist(w, g, h, r, try1);
			long double dist2 = getDist(w, g, h, r, try2);
			maxX = std::min(maxX, std::min(dist1, dist2));

			if(dist1 < dist2){
				rr = try2;
			} else {
				l = try1;
			}
		}

		std::cout.precision(12);
		std::cout << std::fixed << minX << ' ' << maxX << '\n';
	}
}