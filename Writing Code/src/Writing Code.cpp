#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

typedef long long ll;

ll coders, linesneeded, maxbugs, modulo;

ll bugsperline[5];

ll ways(ll coderpos, ll linepos, ll bugpos){
	if(bugpos > maxbugs or coderpos > coders){
		return 0;
	} else if(linepos == linesneeded){
		return 1;
	} else if(coderpos == coders){
		return 0;
	}

	return ways(coderpos + 1, linepos, bugpos)
			+ ways(coderpos, linepos + 1, bugpos + bugsperline[coderpos]);
}

int main() {
	std::cin >> coders >> linesneeded >> maxbugs >> modulo;

	for(ll i = 0; i < coders; i++){
		std::cin >> bugsperline[i];
	}

	std::cout << ways(0, 0, 0);
//	ll ways[2][4][4];
//
//	for(ll i = 0; i < linesneeded; i++){
//		for(ll j = 0; j <= maxbugs; j++){
//			ways[1][i][j] = 0;
//		}
//	}
//	for(ll j = 0; j <= maxbugs; j++){
//		ways[1][linesneeded][j] = 1;
//	}
//
//	ll res = 0;
//	for(ll i = coders - 1, period = 0; i >= 0; i--){
//		for(ll j = linesneeded; j >= 0; j--){
//			for(ll k = maxbugs; k >= 0; k--){
//				ways[period][j][k] = ways[1 - period][j][k];
//				if(j + 1 <= linesneeded and k + bugsperline[i] <= maxbugs){
//					ways[period][j][k] += ways[period][j + 1][k + bugsperline[i]];
//				}
//
//			}
//		}
//
//		period ^= 1;
//
//		if(i == 0){
//			for(ll k = 0; k <= maxbugs; k++){
//				res += ways[period][0][k];
//			}
//		}
//	}
//
//	std::cout << res;
//	return 0;
}
