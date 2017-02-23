//============================================================================
// Name        : Barok.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>

struct zgrada {
	int x, y;
};

int main() {
	int x, y, barani, barok;
	std::cin >> x >> y >> barani >> barok;
	barani -= barok;
	x += 2, y += 2;
	char passed[x][y];
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (i == 0 or i == x - 1 or j == 0 or j == y - 1) {
				passed[i][j] = 'x';
			} else {
				passed[i][j] = '.';
			}
		}
	}

	std::queue<zgrada> zgr;
	zgrada copier;
	for (int i = 0; i < barok; i++) {
		std::cin >> copier.x >> copier.y;
		zgr.push(copier);
		passed[copier.x][copier.y] = 's';
	}
	int ite = 0;
	while (barani > 0) {
		ite++;
		for (int i = zgr.size() - 1; i >= 0; i--) {
			if (passed[zgr.front().x - 1][zgr.front().y] == '.') {
				passed[zgr.front().x - 1][zgr.front().y] = 'o';
				copier.x = zgr.front().x - 1;
				copier.y = zgr.front().y;
				zgr.push(copier);
				barani--;
			}
			if (passed[zgr.front().x + 1][zgr.front().y] == '.') {
				passed[zgr.front().x + 1][zgr.front().y] = 'o';
				copier.x = zgr.front().x + 1;
				copier.y = zgr.front().y;
				zgr.push(copier);
				barani--;
			}
			if (passed[zgr.front().x][zgr.front().y - 1] == '.') {
				passed[zgr.front().x][zgr.front().y - 1] = 'o';
				copier.x = zgr.front().x;
				copier.y = zgr.front().y - 1;
				zgr.push(copier);
				barani--;
			}
			if (passed[zgr.front().x][zgr.front().y + 1] == '.') {
				passed[zgr.front().x][zgr.front().y + 1] = 'o';
				copier.x = zgr.front().x;
				copier.y = zgr.front().y + 1;
				zgr.push(copier);
				barani--;
			}
			zgr.pop();
		}
	}

	std::cout<<ite;

	return 0;
}
