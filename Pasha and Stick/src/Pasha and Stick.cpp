#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	int res = 0;
	if(n % 2 == 0){
		n /= 2;

		res = n / 2;
		if(n % 2 == 0){
			res--;
		}
	}

	cout << res;
	return 0;
}
