#include <iostream>
#include <algorithm>

struct program {
	int preparetime, runtime;

	bool operator<(const program &x) const {
		return runtime > x.runtime;
	}
};
int main() {
	int programs;
	std::cin >> programs;

	program p[programs];

	for(int i = 0; i < programs; i++){
		std::cin >> p[i].preparetime >> p[i].runtime;
	}

	std::sort(p, p + programs);

	int actualtime = 0, lastprepare = 0;
	for(int i = 0; i < programs; i++){
		lastprepare += p[i].preparetime;
		actualtime = std::max(actualtime, lastprepare + p[i].runtime);
	}

	std::cout << actualtime;
	return 0;
}
