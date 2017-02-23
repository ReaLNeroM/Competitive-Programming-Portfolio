#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int log(int num) {
	int log = 0;
	while (num >= 10) {
		num /= 10;
		log++;
	}

	return log + 1;
}

bool ispald(int num) {
	if (log(num) == 1) {
		return true;
	}
	for (int i = 0; i < log(num) / 2; i++) {
		if ((num / ((int) std::pow(10, log(num) - i - 1))) % 10 != (num / ((int) std::pow(10, i))) % 10) {
			return false;
		}
	}

	return true;
}

std::vector<int> palindromes;

int bfs(int start, int end) {
	std::queue<int> q;
	q.push(start);
	int passed[end + 1];

	for (int i = 1; i <= end; i++) {
		passed[i] = -1;
	}
	passed[start] = 0;

	do {
		for (int i = 0; i < palindromes.size(); i++) {
			int copier = palindromes[i] + q.front();
			if (copier > end or palindromes[i] >= q.front()) {
				break;
			}
			if (passed[copier] == -1) {
				passed[copier] = passed[q.front()] + 1;
				q.push(copier);

				if(q.back() == end){
					return passed[end];
				}
			}
		}

		q.pop();
	} while (!q.empty());

	return passed[end];
}

int main() {
	std::map<int, bool> st;
	int start, end;
	std::cin >> start >> end;
	if (start == end) {
		std::cout << 0;
		return 0;
	}

	for (int i = 1; i <= end; i++) {
		if (ispald(i)) {
			palindromes.push_back(i);
			st[i] = true;
		}
	}

	std::cout << bfs(start, end);
}
