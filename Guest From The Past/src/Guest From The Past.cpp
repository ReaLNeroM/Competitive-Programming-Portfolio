#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	ll m, a, b, ra;
	cin >> m >> b >> a >> ra;

	ll onetake = m / b;

	ll twotake = 0;
	if(m >= a){
		twotake = (m - a) / (a - ra) + 1;
		twotake += (m - twotake * (a - ra)) / b;
	}

	cout << max(onetake, twotake);
	return 0;
}
