#include <iostream>

int main() {
	std::string comp = "", digits = "";
	std::cin >> comp >> digits;

	int left[10];
	for (int i = 0; i < 10; i++) {
		left[i] = 0;
	}
	for (int i = 0; i < digits.length(); i++) {
		left[digits[i] - '0']++;
	}

	std::string max = "", min = "A", curr = "";
	for (int i = 0; i < comp.length(); i++) {
		if (left[comp[i] - '0'] == 0) {
			for (int j = comp[i] - '0' + 1; j < 10; j++) {
				if (left[j] != 0) {
					curr += '0' + j;
					left[j]--;

					for (int k = 0; k < 10; k++) {
						for (int l = 0; l < left[k]; l++) {
							curr += '0' + k;
						}
					}

					if (curr >= comp) {
						min = std::min(min, curr);
					}
					left[j]++;
					break;
				}
			}

			break;
		}

		left[comp[i] - '0']--;
		curr += comp[i];
	}

	if (curr.length() == comp.length() and curr >= comp) {
		min = std::min(min, curr);
	}
	if (min == "A") {
		min = "0";
	}

	for (int i = 0; i < curr.length(); i++) {
		left[curr[i] - '0']++;
	}

	curr = "";
	for (int i = 0; i < comp.length(); i++) {
		if (left[comp[i] - '0'] == 0) {
			for (int j = comp[i] - '0' - 1; j >= 0; j--) {
				if (left[j] != 0) {
					curr += '0' + j;
					left[j]--;

					for (int k = 9; k >= 0; k--) {
						for (int l = 0; l < left[k]; l++) {
							curr += '0' + k;
						}
					}

					if (curr < comp) {
						max = std::max(max, curr);
					}
					left[j]++;
					break;
				}
			}

			break;
		}

		left[comp[i] - '0']--;
		curr += comp[i];
	}

	for (int i = 0; i < max.length(); i++) {
		if (max[i] != '0') {
			break;
		} else {
			max = "0";
			break;
		}
	}

	if (max == "") {
		max = "0";
	}

	std::cout << min << std::endl << max << std::endl;
}
