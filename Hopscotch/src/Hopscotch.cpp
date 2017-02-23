#include <fstream>

int mat[100][100];
std::string way[100][100];
long long x, y, k;

std::string sum(std::string a, std::string b) {
	std::string c;

	long long lim = std::min(a.length(), b.length());
	for (int i = 1; i < lim; i++) {
		if (a[a.length() - i] + b[b.length() - i] - 96 > 9) {
			int j = i + 1;
			while (true) {
				if (a[a.length() - j] - 48 <= 9) {
					a[a.length() - j]++;
				} else if (b[b.length() - i] - 48 <= 9) {
					b[a.length() - j]++;
				} else{
					j++;
				}
			}
		}
		c.insert(c.begin(), a[a.length() - i - 1] + b[b.length() - i - 1] - 96 % 10);
	}
	return c;
}

std::string mod(std::string a, std::string b) {
}

std::string ftd(long long a = 0, long long b = 0) {
	if (way[a][b] == "-") {
		way[a][b] = '0';
		for (long long i = a + 1; i < x; i++) {
			for (long long j = b + 1; j < y; j++) {
				if (mat[a][b] != mat[i][j]) {
					way[a][b] = sum(way[a][b], ftd(i, j));
				}
			}
		}
	}

	return way[a][b];
}

int main() {
	std::ifstream fin;
	std::ofstream fout;

	fin.open("hopscotch.in");
	fout.open("hopscotch.out");
	fin >> x >> y >> k;

	for (long long i = 0; i < x; i++) {
		for (long long j = 0; j < y; j++) {
			fin >> mat[i][j];
			way[i][j] = '-';
		}
	}

	way[x - 1][y - 1] = '1';

	fout << mod(ftd(), "1000000007") << std::endl;
	return 0;
}
