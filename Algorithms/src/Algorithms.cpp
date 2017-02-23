#include <iostream>
#include <vector>

typedef long long ll;

struct ival { //interval
		int left = 1, right = 1;
};

int main() {
	std::ios::sync_with_stdio(false);
	static ival iv[100001];

	int days, tasks, pickable;
	std::cin >> days >> tasks >> pickable;

	static ll type[100001][4];
	static int val[100001][4];
	std::string str;
	for (int i = 0; i < days; i++) {
		for (int j = 0; j < tasks; j++) {
			std::cin >> str;
			type[i][j] = 0;

			for (int k = 0; k < str.length(); k++) {
				type[i][j] *= 26;
				type[i][j] += str[k] - 'A';
			}

			val[i][j] = -1;
		}
	}

	int size = 0;
	for (int i = 0; i < days; i++) {
		for (int j = 0; j < tasks; j++) {
			if (val[i][j] == -1) {
				iv[size].left = iv[size].right = i;
				size++;

				val[i][j] = size - 1;
				for (int k = i; k < days; k++) {
					for (int l = 0; l < tasks; l++) {
						if (val[k][l] == -1 and type[i][j] == type[k][l]) {
							iv[size - 1].right = k;
							val[k][l] = size - 1;
						}
					}

					if (iv[size - 1].right != k) {
						break;
					}
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < size; i++) {
		int left = iv[i].left, right = iv[i].right;
		if (pickable > 1 and left > 0) {
			for (int l = 0; l < tasks; l++) {
				left = std::min(left, iv[val[iv[i].left - 1][l]].left);
			}
		}
		if (pickable > 2 and right < days - 1) {
			for (int l = 0; l < tasks; l++) {
				right = std::max(right, iv[val[iv[i].right + 1][l]].right);
			}
		}

		max = std::max(max, right - left + 1);
	}

	std::cout << max;
	return 0;
}
