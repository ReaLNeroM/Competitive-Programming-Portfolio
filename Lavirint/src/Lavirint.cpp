#include <iostream>
#include <queue>

struct coord {
	int x, y;
} transfer;

int x, y;
char mat[300][300];
int cost[300][300];
int used[300][300][3];

int bfs(coord start, coord end) {
	std::queue<coord> q;
	q.push(start);
	cost[start.x][start.y] = 0;

	int jump = 1, steps = 1;
	const int adder[] = {1, -1, 0, 0};

	while (!q.empty()) {
		for(int ite = q.size(); ite > 0; ite--){
			for(int i = 0; i < 4; i++){
				bool good = true;
				for(int j = 1; j <= steps; j++){
					if(q.front().x + j * adder[i] >= 0 and q.front().x + j * adder[i] < x
							and q.front().y + j * adder[(i + 2) % 4] >= 0 and q.front().y + j * adder[(i + 2) % 4] < y
								and mat[q.front().x + j * adder[i]][q.front().y + j * adder[(i + 2) % 4]] != '#'){
						transfer.x = q.front().x + j * adder[i], transfer.y = q.front().y + j * adder[(i + 2) % 4];
					} else{
						good = false;
						break;
					}
				}

				if(good and !used[transfer.x][transfer.y][steps]){
					q.push(transfer);
					cost[transfer.x][transfer.y] = std::min(cost[transfer.x][transfer.y], cost[q.front().x][q.front().y] + 1);
					used[transfer.x][transfer.y][steps] = true;
					if(transfer.x == end.x and transfer.y == end.y){
						return jump;
					}
				}
			}
			q.pop();
		}
		jump++, steps++;
		if(steps == 4) steps = 1;
	}

	return cost[end.x][end.y];
}

int main() {
	std::cin >> x >> y;
	coord start, end;

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cost[i][j] = 1000000000;
			used[i][j][0] = used[i][j][1] = used[i][j][2] = false;

			std::cin >> mat[i][j];
			if (mat[i][j] == 'P') {
				start.x = i, start.y = j;
			} else if (mat[i][j] == 'K') {
				end.x = i, end.y = j;
			}
		}
	}

	std::cout << bfs(start, end);
	return 0;
}
