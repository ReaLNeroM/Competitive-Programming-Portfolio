#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	ll l, r, k, val = 1;
	cin >> l >> r >> k;

	double dval = 1, dr = r, dk = k;

	bool couted = false;
	while(dval <= dr + 100000){
		if(val >= l and val <= r){
			couted = true;
			cout << val << ' ';
		}
		val *= k;
		dval *= k;
	}

	if(!couted){
		cout << -1;
	}
	return 0;
}
