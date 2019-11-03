#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
long double val[maxn];
int n;

bool good(long double mid){
	long double sum = 0.0;

	long double worstSum = 0.0;
	long double currSum = 0.0;
	for(int i = 0; i < n; i++){
		long double currElem = val[i] - mid;

		sum += currElem;
		currSum = std::min(currSum + currElem, currElem);
		worstSum = std::min(worstSum, currSum);
	}

	return sum - worstSum > 0.0L;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	long double best = 0.0;
	long double l = 0.0;
	long double r = 1000000100.0L;
	for(int i = 0; i < 200; i++){
		long double mid = (l + r) / (long double) 2.0;

		if(good(mid)){
			best = mid;
			l = mid;
		} else {
			r = mid;
		}
	}

	std::cout.precision(9);
	std::cout << std::fixed << best << '\n';
}
