#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int planets;
long double payload;
long double lift[maxn];
long double land[maxn];

bool good(long double fuel){
	for(int i = 0; i < planets; i++){
		fuel -= ((long double) (payload + fuel)) / lift[i];
		if(fuel <= 0.0){
			return false;
		}
		fuel -= ((long double) (payload + fuel)) / land[(i + 1) % planets];
		if(fuel <= 0.0){
			return false;
		}
	}

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> planets >> payload;
	for(int i = 0; i < planets; i++){
		std::cin >> lift[i];
	}
	for(int i = 0; i < planets; i++){
		std::cin >> land[i];
	}

	long double l = 0.0, r = 1e9 + 10.0;
	long double best = -1;

	for(ll iterations = 0; iterations < 200; iterations++){
		long double mid = (l + r) / 2.0;

		if(good(mid)){
			best = mid;
			r = mid;
		} else {
			l = mid;
		}
	}

	if(best < -0.5){
		std::cout << -1 << '\n';
		return 0;
	}
	std::cout.precision(9);
	std::cout << std::fixed << best << '\n';
}