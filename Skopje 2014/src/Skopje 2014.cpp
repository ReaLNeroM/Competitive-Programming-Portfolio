#include <iostream>
#include <queue>

typedef long long ll;

struct fence{
	int start, end;
	int line;
};

const int adderx[] = {1, -1, 0, 0}, addery[] = {0, 0, 1, -1};
int x, y;

bool collision(int gx, int gy, int direction, fence i, bool vertical){
	if(vertical){
		if(direction <= 1 or ()){
			return false;
		}

		return true;
	} else {
		if(direction >= 2 or ()){
			return false;
		}

		return true;
	}
}
int main() {
	int cases;
	std::cin >> cases;

	int res[cases];
	for(int test = 0; test < cases; test++){
		std::cin >> x >> y;

		int steps[y][x];
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				steps[i][j] = 1000000;
			}
		}

		int fences;
		std::cin >> fences;

		int housex, housey, gymx, gymy;
		std::cin >> housex >> housey >> gymx >> gymy;

		int hfences, vfences;

		std::cin >> hfences;
		fence hf[hfences];
		for(int i = 0; i < hfences; i++){
			std::cin >> hf[i].start >> hf[i].end >> hf[i].line;
		}

		std::cin >> vfences;
		fence vf[vfences];
		for(int i = 0; i < vfences; i++){
			std::cin >> vf[i].start >> vf[i].end >> vf[i].line;
		}

		std::queue<int> qx, qy;
		qx.push(housex), qy.push(housey);
		steps[housey][housex] = 0;

		while(!qx.empty()){
			for(int i = 0; i < 4; i++){
				if(qx.front() + adderx[i] < 0 or qx.front() + adderx[i] >= x or qy.front() + addery[i] < 0 or qy.front() + addery[i] >= y){
					continue;
				}
				bool possible = true;
				for(int j = 0; j < hfences and collision; j++){
					if(collision(qx.front(), qy.front(), i, hf[j], false)){
						possible = false;
					}
				}
				for(int j = 0; j < vfences and collision; j++){
					if(collision(qx.front(), qy.front(), i, vf[j], true)){
						possible = false;
					}
				}

				if(possible){
					qx.push(qx.front() + adderx[i]);
					qy.push(qy.front() + addery[i]);
				}
			}

			qx.pop(), qy.pop();
		}

		res[i] = steps[gymy][gymx];
	}
	for(int i = 0; i < cases; i++){
		std::cout << res[i];
	}
	return 0;
}
