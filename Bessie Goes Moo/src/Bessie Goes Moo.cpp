#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("bgm.in");
	std::ofstream fout("bgm.out");
#endif

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){

	}
	return 0;
}
