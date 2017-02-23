//============================================================================
// Name        : Drinks.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<char> > mat;
std::vector<std::vector<int> > cost[3];

struct coord {
	int x = -1, y = -1;
} start, drink[3], end;

void bfs(coord start, int from, int x, int y) {
	std::queue<coord> q;
	q.push(start);
	cost[from][start.x][start.y] = 0;

	coord copy;
	const int jumper[] = { 1, -1, 0, 0 };
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			copy.x = q.front().x + jumper[i], copy.y = q.front().y + jumper[(i + 2) % 4];
			if (copy.x >= 0 and copy.x < x and copy.y >= 0 and copy.y < y and mat[copy.x][copy.y] != '#' and cost[from][copy.x][copy.y] == -1) {
				q.push(copy);
				cost[from][copy.x][copy.y] = cost[from][q.front().x][q.front().y] + 1;
			}
		}
		q.pop();
	}
}

int main() {
	int x, y;
	std::cin >> x >> y;

	int drinks = 0;
	mat.resize(x);
	for (int i = 0; i < x; i++) {
		mat[i].resize(y);
		for (int j = 0; j < y; j++) {
			std::cin >> mat[i][j];
			if (mat[i][j] == 'S') {
				start.x = i, start.y = j;
			} else if (mat[i][j] == 'D') {
				drinks++;
				drink[drinks - 1].x = i, drink[drinks - 1].y = j;
			} else if (mat[i][j] == 'B') {
				end.x = i, end.y = j;
			}
		}
	}

	for (int i = 0; i < drinks; i++) {
		cost[i].resize(x);
		for (int j = 0; j < x; j++) {
			cost[i][j].resize(y);
			for (int k = 0; k < y; k++) {
				cost[i][j][k] = -1;
			}
		}

		bfs(drink[i], i, x, y);
	}
	int min = -1;
	if(drinks == 1 and cost[0][start.x][start.y] != -1 and cost[0][end.x][end.y] != -1){
		min = cost[0][start.x][start.y] + cost[0][end.x][end.y];
	} else if(drinks == 2 and cost[0][start.x][start.y] != -1 and cost[0][drink[1].x][drink[1].y] != -1 and cost[0][end.x][end.y] != -1){
		min = 10000000;
		for(int i = 0; i < 2; i++){
			min = std::min(min, cost[i % 2][start.x][start.y] +
								cost[i % 2][drink[1 - i % 2].x][drink[1 - i % 2].y] +
									cost[1 - i % 2][end.x][end.y]);
		}
	} else if(cost[0][start.x][start.y] != -1 and cost[0][drink[1].x][drink[1].y] != -1 and cost[0][drink[2].x][drink[2].y] != -1 and cost[0][end.x][end.y] != -1){
		min = cost[0][start.x][start.y] +
				std::min(cost[0][drink[1].x][drink[1].y] + cost[1][drink[2].x][drink[2].y] + cost[2][end.x][end.y],
							cost[0][drink[2].x][drink[2].y] + cost[2][drink[1].x][drink[1].y] + cost[1][end.x][end.y]);
		min = std::min(min, cost[1][start.x][start.y] +
				std::min(cost[1][drink[2].x][drink[2].y] + cost[2][drink[0].x][drink[0].y] + cost[0][end.x][end.y],
							cost[1][drink[0].x][drink[0].y] + cost[0][drink[2].x][drink[2].y] + cost[2][end.x][end.y]));
		min = std::min(min, cost[2][start.x][start.y] +
				std::min(cost[2][drink[1].x][drink[1].y] + cost[1][drink[0].x][drink[0].y] + cost[0][end.x][end.y],
							cost[2][drink[0].x][drink[0].y] + cost[0][drink[1].x][drink[1].y] + cost[1][end.x][end.y]));
	}

	std::cout << min;
	return 0;
}
