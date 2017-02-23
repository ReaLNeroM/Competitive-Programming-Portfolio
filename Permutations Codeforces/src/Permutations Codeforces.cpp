#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int vala[n], valb[n], ind[n];
	for(int i = 0; i < n; i++){
		cin >> vala[i];
	}
	for(int i = 0; i < n; i++){
		cin >> valb[i];
		ind[valb[i]] = i;
	}

	if(n == 1){
		cout << 0;
	} else {
		int i;
		for(i = 1; i < n and ind[vala[i]] > ind[vala[i - 1]]; i++){

		}

		cout << n - i;
	}
	return 0;
}
