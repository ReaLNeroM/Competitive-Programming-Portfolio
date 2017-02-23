#include <iostream>
#include <sstream>
typedef long long ll;

struct node {
	node* parent = this;
	int val = 0, rank = 1;

	node* head() {
		if (this != parent) {
			parent = parent->head();
		}

		return parent;
	}
	void unite(node* second) {
		node* parenthead = head();
		second = second->head();

		if (parenthead->rank > second->rank) {
			second->parent = parenthead->parent;
		} else if (parenthead->rank < second->rank) {
			parenthead->parent = second;
		} else {
			second->parent = parenthead->parent;
			rank++;
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	int y, x, queries;
	std::cin >> y >> x >> queries;

	node p[y][x];
	char mat[y][x];
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			std::cin >> mat[i][j];
		}
	}

	const int addery[] = { 1, -1, 0, 0 };
	const int adderx[] = { 0, 0, 1, -1 };
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (mat[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					int ni = i + addery[k];
					int nj = j + adderx[k];

					if (ni >= 0 and ni < y and nj >= 0 and nj < x) {
						if (mat[ni][nj] == '.') {
							p[i][j].unite(&p[ni][nj]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (mat[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					int ni = i + addery[k];
					int nj = j + adderx[k];

					if (ni >= 0 and ni < y and nj >= 0 and nj < x) {
						if (mat[ni][nj] == '*') {
							p[i][j].head()->val++;
						}
					}
				}
			}
		}
	}

	for (int i = 0, qy, qx; i < queries; i++) {
		std::cin >> qy >> qx;

		std::cout << p[qy - 1][qx - 1].head()->val << std::endl;
	}
	return 0;
}
