#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
	ll m, n;
	std::cin >> n >> m;

	if(m != n or m != 1){
		if(m * 2 <= n){
			m++;
		} else {
			m--;
		}
	}

	std::cout << m;
//	for(int m = 1; m <= 1000; m++){
//		for(int n = m; n <= 1000; n++){
//			int best = 0, pos = 1, curr;
//
//			for(int a = 1; a <= n; a++){
//				curr = 0;
//
//				for(int c = 1; c <= n; c++){
//					if(std::abs(c - a) < std::abs(c - m)){
//						curr++;
//					}
//				}
//
//				if(curr > best){
//					best = curr;
//					pos = a;
//				}
//			}
//			if(m * 2 <= n){
//				if(m + 1 != pos){
//					std::cout << "care" << std::endl;
//				}
//			} else {
//				if(m - 1 != pos){
//					std::cout << "care" << std::endl;
//				}
//			}
//		}
//	}

	return 0;
}
