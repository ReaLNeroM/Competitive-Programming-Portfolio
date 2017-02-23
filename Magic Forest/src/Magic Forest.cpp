#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	int cases;
	std::cin >> cases;

	int res[cases];

	for (int test = 0; test < cases; test++) {
		int y, x;
		std::cin >> y >> x;

		char mat[y][x];
		int steps[y][x];
		static int wizard[1000003][2], end[2], power[1000003];
		int wiz = 0;

		for (int k = 0; k <= 1000002; k++) {
			wizard[k][0] = wizard[k][1] = -1;
		}

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				std::cin >> mat[i][j];

				if (mat[i][j] == 'S') {
					wizard[0][0] = i;
					wizard[0][1] = j;
				} else if (mat[i][j] > '0' and mat[i][j] <= '9') {
					wizard[wiz + 1][0] = i;
					wizard[wiz + 1][1] = j;
					power[wiz + 1] = mat[i][j] - '0';
					wiz++;
				} else if (mat[i][j] == 'E') {
					end[0] = i;
					end[1] = j;
				}

				for (int k = 0; k < 10; k++) {
					steps[i][j] = 1000001;
				}
			}
		}

		const int adderx[] = {1, -1, 0, 0};
		const int addery[] = {0, 0, 1, -1};

		std::queue <int> qy, qx;
		qy.push(end[0]);
		qx.push(end[1]);

		steps[qy.front()][qx.front()] = 0;
		while (!qy.empty()) {
			for (int l = 0; l < 4; l++) {
				int copyy = qy.front() + addery[l];
				int copyx = qx.front() + adderx[l];

				if (copyy >= 0 and copyy < y and copyx >= 0 and copyx < x and mat[copyy][copyx] != 'T' and steps[copyy][copyx] == 1000001) {
					steps[copyy][copyx] = steps[qy.front()][qx.front()] + 1;

					qy.push(copyy);
					qx.push(copyx);
				}
			}

			qy.pop();
			qx.pop();
		}

		res[test] = 100;
		for (int i = 1; i <= wiz; i++) {
			if (steps[wizard[i][0]][wizard[i][1]] <= steps[wizard[0][0]][wizard[0][1]]) {
				res[test] -= power[i];
			}
		}

		if (res[test] <= 0) {
			res[test] = 0;
		}

	}

	for (int test = 0; test < cases; test++) {
		std::cout << res[test] << std::endl;
	}
	return 0;
}
