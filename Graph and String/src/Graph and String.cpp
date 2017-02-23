#include <iostream>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	bool used[n][n];
	char val[n];
	for(int i = 0; i < n; i++){
		val[i] = '0';
		for(int j = 0; j < n; j++){
			used[i][j] = false;
		}
	}

	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int f, s;
		cin >> f >> s;

		used[f - 1][s - 1] = used[s - 1][f - 1] = true;
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){

		}
	}

	cout << "Yes" << endl;
	for(int i = 0; i < n; i++){
		cout << val[i];
	}
	return 0;
}
