#include <iostream>

typedef long long ll;
using namespace std;

const double eps = 0.00000001;
int main() {
	ios::sync_with_stdio(false);
	double luke, len, v1, v2;
	cin >> luke >> len >> v1 >> v2;

	double l = 0, r = 10000;

	while(l + eps < r){
		double mid = (l + r) / 2;

		double l1 = v1 * mid, r1 = len - v2 * mid;

		if(r1 - l1 + eps > luke){
			l = mid + eps;
		} else {
			r = mid - eps;
		}
	}

	cout.precision(8);
	cout << l;
	return 0;
}
