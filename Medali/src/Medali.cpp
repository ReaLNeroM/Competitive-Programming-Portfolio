#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int val[n + 1];

	for (int i = 1; i <= n; i++) {
		std::cin >> val[i];
		val[i]--;
	}

	int min = n;
	int best[n + 1][3];
	best[0][0] = best[0][1] = best[0][2] = 0;
	for (int i = 0; i < 2; i++) {
		for (int pos = 1; pos <= n; pos++) {
			for (int medal = 0; medal < 3; medal++) {
				best[pos][medal] = n;
				for (int i = 0; i <= medal; i++) {
					best[pos][medal] = std::min(best[pos][medal], best[pos - 1][i] + (val[pos] != i));
				}
			}
		}

		min = std::min(min, best[n][2]);
		std::reverse(val + 1, val + n + 1);
	}


	std::cout << min;
	return 0;
}
