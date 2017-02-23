#include <iostream>
#include <set>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int c[n];
	std::multiset<int> s;
	for(int i = 0; i < n; i++){
		std::cin >> c[i];
		s.insert(c[i]);
	}

	int blocks = 1, max = 0;
	for(int i = 0; i < n; i++){
		max = std::max(max, c[i]);
		s.erase(s.find(c[i]));
		if(*s.begin() >= max){
			blocks++;
			max = 0;
		}
	}

	std::cout << blocks;
	return 0;
}
