/*
 	 ID: vlade.m1
 	 PROG: milk
	 LANG: C++
 */

#include <iostream>
#include <algorithm>

struct seller {
	long long price, units;

	bool operator<(const seller& other) const {
		return (price < other.price);
	}
};
int main() {/*
	std::ifstream std::cin;
	std::ofstream std::cout;
	std::cin.open("milk.in");
	std::cout.open("milk.std::cout");
*/
	long long goal, sellers;
	std::cin >> goal >> sellers;
	seller s[sellers];

	for (long long i = 0; i < sellers; i++) {
		std::cin >> s[i].price >> s[i].units;
	}

	std::sort(s, s + sellers);

	long long result = 0;

	for (long long curr = 0; curr < sellers and goal > 0; curr++) {
		result += std::min(s[curr].units, goal) * s[curr].price;
		//result += s[curr].units * s[curr].price; full or empty
		goal -= s[curr].units;
	}

	std::cout << result << std::endl;
	return 0;
}
