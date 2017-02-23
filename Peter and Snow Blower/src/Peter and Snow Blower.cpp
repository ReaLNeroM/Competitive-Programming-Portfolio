#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

const double PI = 3.14159265358979323846264338;
int x, y;

double euclid(int x1, int y1){
	double xc = x1 - x;
	double yc = y1 - y;

	xc *= xc;
	yc *= yc;

	return sqrt(xc + yc);
}
int main() {
	ios::sync_with_stdio(false);
	int n;

	cin >> n >> x >> y;
	double mindist = 1000000000, maxdist = 0;

	for(int i = 0; i < n; i++){
		int x1, y1;
		cin >> x1 >> y1;

		mindist = min(mindist, euclid(x1, y1));
		maxdist = max(maxdist, euclid(x1, y1));
	}

	cout.precision(15);
	cout << fixed << PI * (maxdist * maxdist - mindist * mindist);
	return 0;
}
