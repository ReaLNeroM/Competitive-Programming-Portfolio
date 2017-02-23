#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	ll n, m, a;
	cin >> n >> m >> a;

	ll fir = n / a;
	if(n % a != 0){
		fir++;
	}

	ll sec = m / a;
	if(m % a != 0){
		sec++;
	}

	cout << fir * sec;
	return 0;
}
