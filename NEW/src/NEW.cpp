#include <iostream>
#include <list>

int main() {
	int a, b;
	std::cin >> a >> b;

	std::list<int> l(0);

	l.push_back(a);
	l.push_back(b);

	std::cout << l.front() + l.back();
	return 0;
}
