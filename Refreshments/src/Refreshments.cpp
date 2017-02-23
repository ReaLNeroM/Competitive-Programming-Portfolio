#include <iostream>
#include <queue>

int main() {
	int cases;
	std::cin >> cases;

	int res[cases];

	for(int c = 0; c < cases; c++){
		int x, y;
		std::cin >> y >> x;

		char mat[x][y];
		int used[x][y], endx, endy;
		std::queue<int> qx, qy;
		for(int i = 0; i < x; i++){
			for(int j = 0; j < y; j++){
				std::cin >> mat[i][j];
				used[i][j] = -1;

				if(mat[i][j] == 'S'){
					qx.push(i);
					qy.push(j);
					used[i][j] = 0;
				} else if(mat[i][j] == 'F'){
					endx = i, endy = j;
				} else if(mat[i][j] == '#'){
					used[i][j] = 1000000;
				}
			}
		}

		const int adder[] = {1, -1, 0, 0};
		int copyx, copyy;
		while(!qx.empty()){
			for(int i = 0; i < 4; i++){
				copyx = qx.front() + adder[i];
				copyy = qy.front() + adder[(i + 2) % 4];

				if(copyx >= 0 and copyx < x and copyy >= 0 and copyy < y and used[copyx][copyy] == -1){
					used[copyx][copyy] = used[qx.front()][qy.front()] + 1;
					qx.push(copyx);
					qy.push(copyy);
				}
			}

			qx.pop();
			qy.pop();
		}

		res[c] = used[endx][endy];
	}

	for(int c = 0; c < cases; c++){
		std::cout << res[c] + 1 << std::endl;
	}
	return 0;
}
