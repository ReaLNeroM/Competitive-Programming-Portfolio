#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

const int maxn = 1e6 + 1e2;
ll n, p;

ld init = 0;

ld eval2(ld k){
	ld res = 0;
	for(int i = p - 2; i >= 0; i--){
		res += logl((ld)n-i) - logl((ld) n + k - i);
	}
	return res + log(p) + logl(k) - logl((ld) n + k - (p - 1));
}


int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> n >> p;
	
	ll l = 1, r = 2000000.0;
	ld best = -1e300;
	std::cout << std::setprecision(15) << std::fixed;
	while(l <= r){
		ll mid1 = (r - l) / 3 + l;
		ll mid2 = (2 * (r - l)) / 3 + l;
		
		ld r1 = eval2(mid1);
		ld r2 = eval2(mid2);
		
		best = std::max(best, std::max(r1, r2));
		if(r1 <= r2){
			l = mid1 + 1;
			std::cout << mid1 << ' ' << expl(r1) << '\n';
		} else {
			r = mid2 - 1;
			std::cout << mid2 << ' ' << expl(r2) << '\n';
		}
	}

	std::cout << l << ' ' << r << '\n';
	
	std::cout << expl(best) << "\n";
}		
