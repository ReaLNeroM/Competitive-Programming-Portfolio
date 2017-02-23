#include <iostream>
#include <queue>
#include <vector>

struct coord{
	int x = -1, y = -1;
} start, end, copy;

std::vector<std::vector<int> > mat;
std::queue<coord> q;
int x, y;
const int adder[] = { 1, -1, 0, 0 };

bool bfs(int cost){
	q.push(start);

	bool m[x][y];

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			m[i][j] = false;
		}
	}

	while(!q.empty()){
		for(int i = 0; i < 4; i++){
			copy.x = q.front().x + adder[i], copy.y = q.front().y + adder[(i + 2) % 4];
			if(copy.x >= 0 and copy.x < x and copy.y >= 0 and copy.y < y and mat[copy.x][copy.y] >= cost and !m[copy.x][copy.y]){
				if(copy.x == end.x and copy.y == end.y){
					return true;
				}
				q.push(copy);
				m[copy.x][copy.y] = true;

			}
		}

		q.pop();
	}

	return false;
}

int main(){
	std::cin >> x >> y;

	for(int i = 0; i < x; i++){
		std::vector<int> row;
		for(int j = 0; j < y; j++){
			char sign;
			int res = 1000;
			std::cin >> sign;

			if(sign == 'R'){
				start.x = i, start.y = j;
			} else if(sign == 'G'){
				copy.x = i, copy.y = j;
				res = 0;
				q.push(copy);
			} else if(sign == 'Z'){
				end.x = i, end.y = j;
			} else if(sign == '*'){
				res = -1;
			}
			row.push_back(res);
		}

		mat.push_back(row);
	}

	if(start.x == -1 or end.x == -1){
		std::cout << 0 << std::endl;
		return 0;
	}

	while(!q.empty()){
		for(int i = 0; i < 4; i++){
			copy.x = q.front().x + adder[i], copy.y = q.front().y + adder[(i + 2) % 4];
			if(copy.x >= 0 and copy.x < x and copy.y >= 0 and copy.y < y and mat[copy.x][copy.y] > mat[q.front().x][q.front().y] + 1){
				mat[copy.x][copy.y] = mat[q.front().x][q.front().y] + 1;

				q.push(copy);
			}
		}

		q.pop();
	}
	for(int i = mat[start.x][start.y]; i >= 0; i--){
		if(i == 0){
			std::cout << 0;
			break;
		} else if(bfs(i)){
			std::cout << i;
			break;
		}
	}
	return 0;
}
