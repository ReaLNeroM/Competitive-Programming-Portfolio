#include <iostream>
#include <cmath>
#include <algorithm>

typedef long long ll;

const double pi = 3.141592653589793238462643383279;

struct vector { // i toa vistinski vektor
	int index;
	long double angle;

	bool operator<(const vector &x) const {
		return angle < x.angle;
	}
};

int main() {
	int n;
	std::cin >> n;

	vector v[n];
	for(int i = 0, x, y; i < n; i++){
		std::cin >> x >> y;
		v[i].index = i;
		v[i].angle = std::atan2(y, x);
	}

	std::sort(v, v + n);

	double maxdist = 10;
	int bestindex1, bestindex2;
	for(int i = 0; i < n - 1; i++){
		if(v[i + 1].angle - v[i].angle < maxdist){
			maxdist = v[i + 1].angle - v[i].angle;
			bestindex1 = v[i].index;
			bestindex2 = v[i + 1].index;
		}
	}

	if((pi - v[n - 1].angle) + (pi + v[0].angle) < maxdist){
		bestindex1 = v[0].index;
		bestindex2 = v[n - 1].index;
	}

	std::cout << bestindex1 + 1 << ' ' << bestindex2 + 1;
	return 0;
}
