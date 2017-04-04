#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("test.in", "w", stdout);
	cout << 15;

	srand(time(0));
	for(int x = 0; x < 15; x++){
		int n = rand() % 100000 + 1;
		cout << n << endl;

		for(int i = 0; i < n; i++){
			cout << rand() % 10000000 + 1 << ' ';
		}
		cout << endl;

		int q = rand() % 100000 + 1;
		cout << q << endl;

		for(int i = 0; i < q; i++){
			int t = rand() % 2 + 1;
			if(t == 1){
				int l = rand() % n + 1;
				int r = rand() % n + 1;

				if(l > r){
					swap(l, r);
				}

				cout << t << ' ' << l << ' ' << r << endl;
			} else {
				int l = rand() % n + 1;
				int r = rand() % n + 1;

				int d = rand() % 101;

				cout << t << ' ' << l << ' ' << r << ' ' << d << endl;
			}
		}
	}
	return 0;
}
