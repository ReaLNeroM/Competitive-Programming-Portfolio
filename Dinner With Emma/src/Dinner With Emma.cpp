#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int y, x;
	cin >> y >> x;

	int maxx = 0, curr;
	for(int i = 0; i < y; i++){
		curr = 1000000000;

		for(int j = 0, inp; j < x; j++){
			cin >> inp;
			curr = min(curr, inp);
		}

		maxx = max(maxx, curr);
	}

	cout << maxx;
	return 0;
}
