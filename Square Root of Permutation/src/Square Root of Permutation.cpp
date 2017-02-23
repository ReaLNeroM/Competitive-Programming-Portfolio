#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int val[n];
	for(int i = 0; i < n; i++){
		cin >> val[i];
		val[i]--;
	}

	for(int i = 0; i < n; i++){
		cout << val[val[i]] + 1<< ' ';
	}
	return 0;
}
