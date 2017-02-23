/*
ID: vlade.m1
PROG: maze1
LANG: C++
 */
#include <fstream>
#include <queue>
#include <string>

std::ifstream fin("maze1.in");
std::ofstream fout("maze1.out");

struct coord{
	int x, y;
} copy;

int main(){
	int x, y;
	fin >> y >> x;

	std::vector<std::vector<char> > mat(2 * x + 1);
	std::vector<std::vector<int> > used(2 * x + 1);
	std::queue<coord> q;

	std::string str;
	std::getline(fin, str);
	for(int i = 0; std::getline(fin, str); i++){
		used[i].resize(2 * y + 1, -1);
		for(int j = 0; j < str.length(); j++){
			mat[i].push_back(str[j]);
		}
	}

	for(int i = 1; i < mat[0].size(); i += 2){
		if(mat[0][i] == ' '){
			copy.x = 1, copy.y = i;
			q.push(copy);
			used[copy.x][copy.y] = 1;
		}
		if(mat[2 * x][i] == ' '){
			copy.x = 2 * x - 1, copy.y = i;
			q.push(copy);
			used[copy.x][copy.y] = 1;
		}
	}
	for(int j = 1; j < 2 * x; j += 2){
		if(mat[j][0] == ' '){
			copy.x = j, copy.y = 1;
			q.push(copy);
			used[copy.x][copy.y] = 1;
		}
		if(mat[j][2 * y] == ' '){
			copy.x = j, copy.y = 2 * y - 1;
			q.push(copy);
			used[copy.x][copy.y] = 1;
		}
	}

	int biggest = 1;
	const int adder[] = {2, -2, 0, 0};
	while(!q.empty()){
		for(int i = 0; i < 4; i++){
			copy = q.front();
			copy.x += adder[i], copy.y += adder[(i + 2) % 4];

			if(copy.x >= 0 and copy.x < mat.size() and copy.y >= 0 and copy.y < mat[0].size() and mat[q.front().x + (adder[i] / 2)][q.front().y + (adder[(i + 2) % 4] / 2)] == ' ' and  used[copy.x][copy.y] == -1){
				used[copy.x][copy.y] = used[q.front().x][q.front().y] + 1;
				if(used[copy.x][copy.y] > biggest){
					biggest = used[copy.x][copy.y];
				}
				q.push(copy);
			}
		}
		q.pop();
	}

	fout << biggest << std::endl;
}
