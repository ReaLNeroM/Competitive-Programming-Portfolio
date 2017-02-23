/*
 ID: vlade.m1
 PROG: transform
 LANG: C++
 */
#include <fstream>
#include <vector>

std::vector<std::string> mat[2];
int size;

bool zero90(std::vector<std::string> copy) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (copy[i][j] != mat[1][j][size - i - 1]) {
				return false;
			}
		}
	}

	return true;
}
bool one80(std::vector<std::string> copy) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (copy[i][j] != mat[1][size - i - 1][size - j - 1]) {
				return false;
			}
		}
	}

	return true;
}
bool two70(std::vector<std::string> copy) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (copy[i][j] != mat[1][j][size - i - 1]) {
				return false;
			}
		}
	}

	return true;
}
bool reflection() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mat[0][i][j] != mat[1][i][size - j - 1]) {
				return false;
			}
		}
	}

	return true;
}
bool combination() {
	std::vector<std::string> copy = mat[0];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			copy[i][j] = mat[0][i][size - j - 1];
		}
	}

	if (zero90(copy) or one80(copy) or two70(copy)) {
		return true;
	}

	return false;
}

bool nochange() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (mat[0][i][j] != mat[1][i][j]) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	std::ifstream fin;
	std::ofstream out;
	fin.open("transform.in");
	out.open("transform.out");
	fin >> size;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < size; j++) {
			std::string copy;
			fin >> copy;
			mat[i].push_back(copy);
		}
	}

	if (zero90(mat[0])) {
		out << 1;
	} else if (one80(mat[0])) {
		out << 2;
	} else if (two70(mat[0])) {
		out << 3;
	} else if (reflection()) {
		out << 4;
	} else if (combination()) {
		out << 5;
	} else if (nochange()) {
		out << 6;
	} else {
		out << 7;
	}

	out << std::endl;

	return 0;
}
