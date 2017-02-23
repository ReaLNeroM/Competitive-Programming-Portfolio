#include <iostream>
#include <map>
typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int val[n];
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	int res = 0;
	while(true){
		int maxleft = -1, maxright = -2, maxbneck;
		int left = 0, right = 0, bneck = 1000000000;
		for(int i = 0; i < n; i++){
			if(val[i] > 0){
				right = i;
				bneck = std::min(bneck, val[i]);
				if(maxright - maxleft < right - left){
					maxleft = left, maxright = right;
					maxbneck = bneck;
				}
			} else {
				bneck = 1000000000;
				left = i + 1;
			}
		}

		if(maxleft >= 0){
			for(int i = maxleft; i <= maxright; i++){
				val[i] -= maxbneck;
			}
			res += maxbneck;
		} else {
			break;
		}
	}

	std::cout << res;
	return 0;
}
