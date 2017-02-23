#include <iostream>
#include <algorithm>

typedef long long ll;

struct tree{
	ll pos, height;

	bool operator<(tree const &x) const {
		return (pos < x.pos);
	}
};
int main() {
	ll trees;
	std::cin >> trees;

	tree t[trees + 1];
	t[trees].pos = 3000000000;
	for(ll i = 0; i < trees; i++){
		std::cin >> t[i].pos >> t[i].height;
	}

	std::sort(t, t + trees);

	ll pos = t[0].pos, treescut = 1;
	for(ll i = 1; i < trees; i++){
		if(pos < t[i].pos - t[i].height){
			treescut++;
		} else if((pos > t[i].pos + t[i].height or pos < t[i].pos) and t[i + 1].pos > t[i].pos + t[i].height) {
			if(pos < t[i].pos){
				treescut++;
			}
			pos = t[i].pos + t[i].height;
		}
		pos = std::max(pos, t[i].pos);
	}

	std::cout << treescut;
	return 0;
}
