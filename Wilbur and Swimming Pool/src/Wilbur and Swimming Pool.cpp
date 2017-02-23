#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;

#define fir first
#define sec second

int main() {
	int v;
	std::cin >> v;

	std::pair <int, int> p[v];
	for (int i = 0; i < v; i++) {
		std::cin >> p[i].sec >> p[i].fir;
	}

	int othery = p[0].sec, otherx = p[0].fir;
	for (int j = 1; j < v; j++) {
		if (p[j].fir != p[0].fir) {
			otherx = p[j].fir;
		}
		if (p[j].sec != p[0].sec) {
			othery = p[j].sec;
		}
	}

	if(othery != p[0].sec and otherx != p[0].fir){
		std::cout << std::abs((otherx - p[0].fir) * (othery - p[0].sec));
	} else {
		std::cout << -1;
	}
	return 0;
}
