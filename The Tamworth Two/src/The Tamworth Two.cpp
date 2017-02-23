/*
ID: vlade.m1
PROG: ttwo
LANG: C++
*/

#include <fstream>

std::ifstream fin("ttwo.in");
std::ofstream fout("ttwo.out");

struct coord{
	int x, y, rot;
};

int main() {
	char mat[10][10];

	coord piece[2];
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			fin >> mat[i][j];
			if(mat[i][j] == 'F'){
				piece[0].x = i, piece[0].y = j, piece[0].rot = 0;
			} else if(mat[i][j] == 'C'){
				piece[1].x = i, piece[1].y = j, piece[1].rot = 0;
			}
		}
	}

	const int addery[] = {0, 1, 0, -1};
	const int adderx[] = {-1, 0, 1, 0};

	for(int move = 0; move <= 500; move++){
		if(piece[0].x == piece[1].x and piece[0].y == piece[1].y){
			fout << move << std::endl;
			return 0;
		}
		for(int i = 0; i < 2; i++){
			if(piece[i].x + adderx[piece[i].rot] >= 0 and piece[i].x + adderx[piece[i].rot] < 10 and piece[i].y + addery[piece[i].rot] >= 0 and piece[i].y + addery[piece[i].rot] < 10 and mat[piece[i].x + adderx[piece[i].rot]][piece[i].y + addery[piece[i].rot]] != '*'){
				piece[i].x += adderx[piece[i].rot], piece[i].y += addery[piece[i].rot];
			} else{
				piece[i].rot = (piece[i].rot + 1) % 4;
			}
		}
	}

	fout << 0 << std::endl;
	return 0;
}
