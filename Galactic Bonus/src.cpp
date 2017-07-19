#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	
	int t;
	std::cin >> t;
	
	for(int test = 0; test < t; test++){
		unsigned long long lln;
		std::cin >> lln;
		__int128_t n = lln;
		double dn = lln;
		
		unsigned long long res = n - 1;

		for(__int128_t a = 2; a <= 100; a++){
			__int128_t n_copy = n;
			
			int found = 0;
			while(n_copy){
				if(n_copy % a == 1){
					found++;
				} else if(n_copy % a != 0){
					found = 3;
					break;
				}
				
				n_copy /= a;
			}	
			
			if(found == 2){
				res = a;
				break;
			}
		}	
			
		for(__int128_t i = 2; i < 10; i++){
			for(__int128_t j = 0; j < i; j++){
				double l = 101, r = n - 2;
				
				while(l <= r){
					double mid = (l + r) / 2.0;
					
					double get = std::pow(mid, i) + std::pow(mid, j);
						
					if(std::abs(get - dn) < 0.01){
						res = std::min(res, (unsigned long long) std::round(mid));
					} else if(get < dn){
						l = mid + 0.01;
					} else {
						r = mid - 0.01;
					}
				}
			}
		}
		
		std::cout << res << std::endl;
	}
}