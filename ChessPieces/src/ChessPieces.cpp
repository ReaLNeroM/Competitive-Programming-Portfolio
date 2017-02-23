#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class ChessPieces {
public:
	std::string howMany(std::vector<int> pieces) {
		std::string res = "", push = "";

		int min = std::min(pieces[0] / 8, pieces[6] / 8);
		for (int i = 1; i < 4; i++) {
			min = std::min(min, pieces[i] / 2);
			min = std::min(min, pieces[i + 6] / 2);
		}
		for (int i = 4; i < 6; i++) {
			min = std::min(min, pieces[i]);
			min = std::min(min, pieces[i + 6]);
		}

		int left = pieces[0] - 8 * min + pieces[6] - 8 * min;
		for (int i = 1; i < 4; i++) {
			left += pieces[i] - 2 * min;
			left += pieces[i + 6] - 2 * min;
		}
		for (int i = 4; i < 6; i++) {
			left += pieces[i] - min;
			left += pieces[i + 6] - min;
		}

		do {
			push += '0' + (min % 10);
			min /= 10;
		} while (min >= 1);

		std::reverse(push.begin(), push.end());

		res += push;
		res += ',';

		push = "";
		do {
			push += '0' + (left % 10);
			left /= 10;
		} while (left >= 1);

		std::reverse(push.begin(), push.end());
		res += push;

		return res;
	}
};

int main() {
	ChessPieces instance;
	std::vector<int> query;
	query.resize(12);
	for (int i = 0; i < 12; i++) {
		std::cin >> query[i];
	}

	std::cout << instance.howMany(query);
}
