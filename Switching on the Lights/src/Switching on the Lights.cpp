//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("lightson.in");
	std::ofstream fout("lightson.out");
#endif
#include <vector>
#include <utility>

typedef long long ll;

int n;

bool withinboundaries(int y, int x){
	return (y >= 0 and y < n and x >= 0 and x < n);
}
int main() {
	int switches;
	fin >> n >> switches;

	int used[n][n], lit[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			used[i][j] = false;
			lit[i][j] = false;
		}
	}

	std::vector<std::pair<int, int> > sw[n][n];
	for(int i = 0, y1, x1, y2, x2; i < switches; i++){
		fin >> y1 >> x1 >> y2 >> x2;

		sw[y1 - 1][x1 - 1].push_back(std::make_pair(y2 - 1, x2 - 1));
	}

	lit[0][0] = true;

	const int addery[] = {0, 0, 1, -1};
	const int adderx[] = {1, -1, 0, 0};
	bool open = false;
	do{
		open = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(lit[i][j] and !used[i][j]){
					int k;
					for(k = 0; k < 4; k++){
						if(withinboundaries(i + addery[k], j + adderx[k]) and used[i + addery[k]][j + adderx[k]]){
							break;
						}
					}

					if(k != 4 or i + j == 0){
						used[i][j] = true;
						open = true;
						for(int l = 0; l < sw[i][j].size(); l++){
							lit[sw[i][j][l].first][sw[i][j][l].second] = true;
						}
					}
				}
			}
		}
	} while(open);

	int usable = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(lit[i][j]){
				usable++;
			}
		}
	}

	fout << usable << std::endl;
	return 0;
}
