#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int m[3];
	for (int i = 0; i < 3; i++) {
		cin >> m[i];
	}
	sort(m, m + 3);

	set <int> str;
	bool imp = false;
	for (int i = 0; i < n; i++) {
		int inp;
		cin >> inp;

		str.insert(inp);
		if (m[0] + m[1] + m[2] < inp) {
			imp = true;
		}
	}

	if (imp) {
		cout << -1;
	} else {
		int hours = 0;
		int i;
		for (i = 0; i < n - 1; i++) {
			hours++;

			if (i < n - 2 and m[0] >= *(str.begin()) and m[1] >= *(++str.begin()) and m[2] >= *(str.begin()++++)) {
				i += 2;
				str.erase(str.begin());
				str.erase(str.begin());
				str.erase(str.begin());
			}
		}

		hours += (i == n - 1);

		cout << hours;
	}

	return 0;
}
