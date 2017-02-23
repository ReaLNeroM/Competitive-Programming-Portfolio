#include <iostream>
#include <map>
#include <vector>
#include <queue>

std::map<std::string, int> m;

struct state {
	std::string str;
	std::vector<int> moves;
} copy;

bool check(std::string &x) {
	int i = 0;

	for (; i < x.length() and x[i] == '1';) {
		i++;
	}
	for (; i < x.length() and x[i] == '0';) {
		i++;
	}
	for (; i < x.length() and x[i] == '2';) {
		i++;
	}

	return (i == x.length());
}

int main() {
	int pawn;
	std::cin >> pawn;

	std::string str;
	for (int i = 0, inp; i < pawn; i++) {
		std::cin >> inp;

		if (str.empty()) {
			str = '0' + inp;
		} else {
			str += '0' + inp;
		}
	}

	std::queue<state> q;

	copy.str = str;
	q.push(copy);
	do {
		str = q.front().str;
		if (check(str)) {
			std::cout << q.front().moves.size() << std::endl;
			for (int i = 0; i < q.front().moves.size(); i++) {
				std::cout << q.front().moves[i] << " ";
			}
			break;
		}

		for (int i = 0; i < str.length(); i++) {
			bool moved = false;
			if (str[i] == '1') {
				if (i != 0) {
					if (str[i - 1] == '0') {
						str[i - 1] = '1';
						str[i] = '0';
						moved = true;
					} else if (str[i - 1] != '0' and i > 1 and str[i - 2] == '0') {
						str[i - 2] = '1';
						str[i] = '0';
						moved = true;
					}
				}
			} else if (str[i] == '2') {
				if (i != str.length() - 1) {
					if (str[i + 1] == '0') {
						str[i + 1] = '2';
						str[i] = '0';
						moved = true;
					} else if (str[i + 1] != '0' and i < str.length() - 2 and str[i + 2] == '0') {
						str[i + 2] = '2';
						str[i] = '0';
						moved = true;
					}
				}
			}

			if (moved) {
				if (m[str] == 0) {
					copy.str = str;
					copy.moves = q.front().moves;
					copy.moves.push_back(i + 1);

					q.push(copy);
					m[str] = m[q.front().str] + 1;
				}
				if (i > 1) {
					str[i - 2] = q.front().str[i - 2];
				}
				if (i > 0) {
					str[i - 1] = q.front().str[i - 1];
				}
				str[i] = q.front().str[i];
				if (i < str.length() - 1) {
					str[i + 1] = q.front().str[i + 1];
				}
				if (i < str.length() - 2) {
					str[i + 2] = q.front().str[i + 2];
				}
			}
		}

		q.pop();
	} while (!q.empty());
}
