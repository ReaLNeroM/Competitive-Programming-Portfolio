#include <iostream>

using namespace std;
typedef long long ll;

static int mat[500][500];
int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	k--;

	int sum = 0;
	int used = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			mat[i][j] = used;
			used++;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = k; j < n; j++){
			mat[i][j] = used;
			used++;
		}
		sum += mat[i][k];
	}

	cout << sum << endl;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
