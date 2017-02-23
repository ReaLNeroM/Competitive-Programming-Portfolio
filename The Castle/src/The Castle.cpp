/*
 ID: vlade.m1
 PROG: castle
 LANG: C++
 */

#include <fstream>
#include <vector>

std::ifstream fin("castle.in");
std::ofstream fout("castle.out");

std::vector<std::vector<int> > mat, comp;

int dfs(int x, int y, int color) {
	if (comp[x][y] != -1) {
		return 0;
	}

	int sum = 1;
	comp[x][y] = color;
	if (x > 0 and (mat[x][y] & 2) == 0) {
		sum += dfs(x - 1, y, color);
	}
	if (x < mat.size() - 1 and (mat[x][y] & 8) == 0) {
		sum += dfs(x + 1, y, color);
	}
	if (y > 0 and (mat[x][y] & 1) == 0) {
		sum += dfs(x, y - 1, color);
	}
	if (y < mat[x].size() - 1 and (mat[x][y] & 4) == 0) {
		sum += dfs(x, y + 1, color);
	}

	return sum;
}

int main() {
	int x, y;
	fin >> y >> x;

	mat.resize(x), comp.resize(x);
	for (int i = 0; i < x; i++) {
		mat[i].resize(y), comp[i].resize(y);
		for (int j = 0; j < y; j++) {
			fin >> mat[i][j];
			comp[i][j] = -1;
		}
	}

	int components = 0, biggestroom = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (comp[i][j] == -1) {
				biggestroom = std::max(biggestroom, dfs(i, j, components));
				components++;
			}
		}
	}

	fout << components << std::endl << biggestroom << std::endl;

	int bestx, besty;
	char bestrot;
	for (int j = 0; j < y; j++) {
		for (int i = x - 1; i >= 0; i--) {
			if ((mat[i][j] & 2) != 0 and i > 0) {
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < y; j++) {
						comp[i][j] = -1;
					}
				}
				mat[i][j] -= 2;
				int test = dfs(i, j, 0);
				if (test > biggestroom) {
					biggestroom = test;
					bestx = i, besty = j, bestrot = 'N';
				}
				mat[i][j] += 2;
			}
			if ((mat[i][j] & 4) != 0 and j < y - 1) {
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < y; j++) {
						comp[i][j] = -1;
					}
				}
				mat[i][j] -= 4;
				int test = dfs(i, j, 0);
				if (test > biggestroom) {
					biggestroom = test;
					bestx = i, besty = j, bestrot = 'E';
				}
				mat[i][j] += 4;
			}
		}
	}

	fout << biggestroom << std::endl;
	fout << bestx + 1 << " " << besty + 1 << " " << bestrot << std::endl;
}
