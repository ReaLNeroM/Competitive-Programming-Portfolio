#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main() {
	int cars;
	std::cin >> cars;

	std::vector<std::pair<int, int> > a, b;

	for(int i = 0; i < cars; i++){
		char c;
		std::pair<int, int> p;

		std::cin >> c >> p.first >> p.second;

		if(c == 'A'){
			a.push_back(p);
		} else {
			b.push_back(p);
		}
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	int leasttime[a.size() + 1][b.size() + 1];

	leasttime[0][0] = 0;

	for(int i = 0; i <= a.size(); i++){
		for(int j = 0; j <= b.size(); j++){
			leasttime[i][j] = std::min(std::max(leasttime[i - 1][j], a[i - 1].first) + a[i - 1].second,
										std::max(leasttime[i][j - 1], b[j - 1].first) + b[j - 1].second);
		}
	}
	std::cout << leasttime[a.size()][b.size()];
	return 0;
}
