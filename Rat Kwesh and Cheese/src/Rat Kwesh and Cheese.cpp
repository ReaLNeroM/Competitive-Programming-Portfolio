#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	long double x, y, z;
	cin >> x >> y >> z;

	long double f[12] = {log(x) * pow(y, z), log(x) * pow(z, y),
			log(x) * y * z, log(x) * z * y,
			log(y) * pow(x, z), log(y) * pow(z, x),
			log(y) * x * z, log(y) * z * x,
			log(z) * pow(x, y), log(z) * pow(y, x),
			log(z) * x * y, log(z) * y * x};

	long double found = f[0];

	string p[12] = {"x^y^z", "x^z^y",
			"(x^y)^z", "(x^z)^x",
			"y^x^z", "y^z^x",
			"(y^x)^z", "(y^z)^x",
			"z^x^y", "z^y^x",
			"(z^x)^y", "(z^y)^x"};
	int pos = 0;
	for(int i = 1; i < 12; i++){
		if(found + 0.000000001 < f[i]){
			found = f[i];
			pos = i;
		}
	}

	cout << p[pos];
	return 0;
}
