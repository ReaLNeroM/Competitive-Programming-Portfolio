#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
vector <vector <int> > pieces[4], pc[4];

void rotate(int ind, int rot) {
	pc[ind] = pieces[ind];

	if (rot % 4 == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pc[ind][j][n - 1 - i] = pieces[ind][i][j];
			}
		}
	} else if (rot % 4 == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pc[ind][n - 1 - i][n - 1 - j] = pieces[ind][i][j];
			}
		}
	} else if (rot % 4 == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				pc[ind][n - 1 - j][i] = pieces[ind][i][j];
			}
		}
	}

	if (rot >= 4) {
		for (int i = 0; i < n - 1 - i; i++) {
			std::swap(pc[ind][i], pc[ind][n - 1 - i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < 4; i++) {
		pieces[i].resize(n);
		for (int j = 0; j < n; j++) {
			pieces[i][j].resize(n);
			for (int k = 0; k < n; k++) {
				cin >> pieces[i][j][k];
			}
		}
	}

	int res[2 * n - 1][2 * n - 1];
	bool solved = false;

	for(int x = 0; x < 24 and !solved; x++){
		for (int a = 0; a < 8 and !solved; a++) {
			rotate(0, a);
			for (int b = 0; b < 8 and !solved; b++) {
				rotate(1, b);
				for (int c = 0; c < 8 and !solved; c++) {
					rotate(2, c);
					for (int d = 0; d < 8 and !solved; d++) {
						rotate(3, d);

						for (int i = 0; i < 2 * n - 1; i++) {
							for (int j = 0; j < 2 * n - 1; j++) {
								res[i][j] = 0;
							}
						}

						bool pos = true;
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								res[i][j] = pc[0][i][j];
							}
						}
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								if (pc[1][i][j] != 0 and res[i][j + n - 1] != 0) {
									pos = false;
								} else if (pc[1][i][j] != 0) {
									res[i][j + n - 1] = pc[1][i][j];
								}
							}
						}
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								if (pc[2][i][j] != 0 and res[i + n - 1][j] != 0) {
									pos = false;
								} else if (pc[2][i][j] != 0) {
									res[i + n - 1][j] = pc[2][i][j];
								}
							}
						}
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								if (pc[3][i][j] != 0 and res[i + n - 1][j + n - 1] != 0) {
									pos = false;
								} else if (pc[3][i][j] != 0) {
									res[i + n - 1][j + n - 1] = pc[3][i][j];
								}
							}
						}

						for (int i = 0; i < 2 * n - 1; i++) {
							for (int j = 0; j < 2 * n - 1; j++) {
								if (res[i][j] == 0) {
									pos = false;
								}
							}
						}
						if (pos) {
							solved = true;
						}
					}
				}
			}
		}
		next_permutation(pieces, pieces + 4);
	}

	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
