#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct tree {
	ll pos, apples;

	bool operator<(const tree &x) const{
		return pos < x.pos;
	}
};

std::vector<tree> t;

int main() {
	ll trees;
	std::cin >> trees;

	t.resize(trees);

	for(ll i = 0; i < trees; i++){
		std::cin >> t[i].pos >> t[i].apples;
	}

	std::sort(t.begin(), t.end());

	if(t[0].pos > 0){
		std::cout << t[0].apples;
	} else if(t[trees - 1].pos < 0){
		std::cout << t[trees - 1].apples;
	} else {
		int first = 0, second = 0;

		for(ll i = 1; i < trees; i++){
			if(t[i - 1].pos < 0 and t[i].pos > 0){
				for(ll j = i; j < trees; j++){
					first += t[j].apples;
					if(i - (j - i) - 1 >= 0){
						first += t[i - (j - i) - 1].apples;
					} else {
						break;
					}
				}
				for(ll j = i - 1; j >= 0; j--){
					second += t[j].apples;
					if(i + (i - j) - 1 < trees){
						second += t[i + (i - j) - 1].apples;
					} else {
						break;
					}
				}
			}
		}

		std::cout << std::max(first, second);
	}

	return 0;
}
