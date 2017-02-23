#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct coord {
	int x = -1, y = -1;

	bool operator==(const coord &x) const {
		return (this->x == x.x and this->y == x.y);
	}
} start, end, copy, none;

std::vector<std::vector<char> > mat;
int x, y;

std::vector<coord> bfs() {
	coord pred[x][y];
	pred[start.x][start.y] = start;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			pred[i][j] = none;
		}
	}
	std::queue<coord> q;
	q.push(start);

	int adder[] = { 1, -1, 0, 0 };
	while (pred[end.x][end.y] == none and !q.empty()) {
		for (int i = 0; i < 4; i++) {
			copy.x = q.front().x + adder[i], copy.y = q.front().y + adder[(i + 2) % 4];
			if (copy.x >= 0 and copy.x < x and copy.y >= 0 and copy.y < y and pred[copy.x][copy.y] == none and mat[copy.x][copy.y] != '#') {
				q.push(copy);
				pred[copy.x][copy.y] = q.front();
			}
		}
		q.pop();
	}

	while (!q.empty()) {
		q.pop();
	}
	q.push(end);

	std::vector<coord> path;
	while (!(q.front() == start)) {
		path.push_back(q.front());
		q.push(pred[q.front().x][q.front().y]);
		q.pop();

		if(q.front() == none){
			path.clear();
			break;
		}
	}

	return path;
}

int main() {
	std::cin >> x >> y;

	for (int i = 0; i < x; i++) {
		std::vector<char> copy(x);
		for (int j = 0; j < y; j++) {
			std::cin >> copy[j];

			if (copy[j] == 'S') {
				start.x = j, start.y = i;
			} else if (copy[j] == 'E') {
				end.x = j, end.y = i;
			}
		}
		mat.push_back(copy);
	}

	std::vector<coord> path = bfs();

	std::reverse(path.begin(), path.end());
	for (int i = path.size() - 1; i >= 0; i--) {
		std::cout << path[i].x + 1 << " " << path[i].y + 1 << std::endl;
	}
	return 0;
}
