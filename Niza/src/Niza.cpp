#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	long long n;
	cin >> n;

	ll prefix[10];
	prefix[0] = 0;
	ll repunit = 0;
	for(int i = 1; i < 10; i++){
		repunit *= 10;
		repunit += 1;
		prefix[i] = (prefix[i - 1] + repunit) * 9;
		cout << prefix[i] << endl;
	}

	for(int i = 9; i > 1; i++){

	}
	return 0;
}
