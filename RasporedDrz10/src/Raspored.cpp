#include <iostream>
#include <algorithm>

int main() {
	int gr, minst, maxst;
	std::cin >> gr >> minst >> maxst;
	int grup[gr];
	for (int i = 0; i < gr; i++) {
		std::cin >> grup[i];
	}
	std::sort(grup, grup + gr);
	int razmesteni = 0;

	for (int i = gr - 1; i >= 0; i--) {
		for (int j = 0; j < gr and grup[i] < minst; j++) {
			if (i == j) {
				continue;
			}

			if (grup[j] > maxst) {
				if (grup[j] - maxst >= minst - grup[i]) {
					razmesteni += minst - grup[i];
					grup[j] -= minst - grup[i];
					grup[i] = minst;
					break;
				} else {
					razmesteni += grup[j] - maxst;
					grup[i] += grup[j] - maxst;
					grup[j] = maxst;

				}
			}
		}
		for (int j = 0; j < gr and grup[i] < minst; j++) {
			if (i == j) {
				continue;
			}

			if (grup[j] > minst) {
				if (grup[j] - minst >= minst - grup[i]) {
					razmesteni += minst - grup[i];
					grup[j] -= minst - grup[i];
					grup[i] = minst;
					break;
				} else {
					razmesteni += grup[j] - minst;
					grup[i] += grup[j] - minst;
					grup[j] = minst;

				}
			}
		}
	}

	for (int i = 0; i < gr; i++) {
		for (int j = 0; j < gr and grup[i] > maxst; j++) {
			if (i == j) {
				continue;
			}

			if (grup[j] >= minst and grup[j] < maxst) {
				if (maxst - grup[j] >= grup[i] - maxst) {
					razmesteni += grup[i] - maxst;
					grup[j] += grup[i] - maxst;
					grup[i] = maxst;
				} else {
					razmesteni += maxst - grup[j];
					grup[i] -= maxst - grup[j];
					grup[j] = maxst;
				}
			}
		}
	}

	for (int i = 0; i < gr; i++) {
		if (grup[i] < minst or maxst < grup[i]) {
			razmesteni = -1;
			break;
		}
	}

	std::cout << razmesteni << std::endl;
	return 0;
}
