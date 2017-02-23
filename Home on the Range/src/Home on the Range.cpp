/*
 ID: vlade.m1
 PROG: range
 LANG: C++
 */

#include <fstream>
#include <deque>

std::ifstream fin("range.in");
std::ofstream fout("range.out");

int main() {
	int size;
	fin >> size;

	int exists[size][size];
	std::deque <int> squaresx, squaresy;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			char inp;
			fin >> inp;

			exists[i][j] = (inp == '1');

			squaresx.push_back(i);
			squaresy.push_back(j);
		}
	}

	for (int i = 2; i <= size and squaresx.size() > 0; i++) {
		for (int j = squaresx.size() - 1; j >= 0; j--) {
			if (squaresx.front() <= size - i and squaresy.front() <= size - i and exists[squaresx.front() + 1][squaresy.front()] >= i - 1 and exists[squaresx.front()][squaresy.front() + 1] >= i - 1 and exists[squaresx.front() + 1][squaresy.front() + 1] >= i - 1) {
				exists[squaresx.front()][squaresy.front()]++;
				squaresx.push_back(squaresx.front()), squaresy.push_back(squaresy.front());
			}

			squaresx.pop_front(), squaresy.pop_front();
		}

		if (squaresx.size() > 0) {
			fout << i << " " << squaresx.size() << std::endl;
		}
	}
	return 0;
}
