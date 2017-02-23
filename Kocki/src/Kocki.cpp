#include <iostream>
#include <deque>

int main() {
	int n;
	std::cin >> n;

	std::deque<long long> secondtable(4, 0);

	long long table[] = {0, 0};
	for(int i = n - 3; i >= 0; i--){
		table[0] = n - i - 2 + secondtable.back() + table[1];
		secondtable.push_front(secondtable.front() + table[0]);
		secondtable.pop_back();
		table[1] = table[0];
	}

	std::cout << table[0] + 1 << std::endl;
	return 0;
}
