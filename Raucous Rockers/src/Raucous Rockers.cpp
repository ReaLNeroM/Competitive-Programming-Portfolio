/*
 ID: vlade.m1
 PROG: rockers
 LANG: C++
 */

//#define mycomputer oiaerntiuoertuiabwetuiuiabwe

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("rockers.in");
	std::ofstream fout("rockers.out");
#endif

#include <vector>

int songs, cdsize, cds;
std::vector <int> songsize;

int dp[21][21][21];
int find(int songid, int cdid, int left) {
	if(dp[songid][cdid][left] == -1){
		dp[songid][cdid][left] = 0;
		if (cdid != cds and songid != songs) {
			if (left >= songsize[songid]) {
				dp[songid][cdid][left] = std::max(find(songid + 1, cdid, cdsize), find(songid + 1, cdid, left - songsize[songid]) + 1);
			} else {
				dp[songid][cdid][left] = std::max(find(songid, cdid + 1, cdsize), find(songid + 1, cdid, left));
			}
		}

	}

	return dp[songid][cdid][left];
}

int main() {
	fin>> songs >> cdsize >> cds;

	songsize.resize(songs);
	for(int i = 0; i < songs; i++) {
		fin >> songsize[i];
	}

	for(int i = 0; i <= 20; i++){
		for(int j = 0; j <= 20; j++){
			for(int k = 0; k <= 20; k++){
				dp[i][j][k] = -1;
			}
		}
	}

	fout << find(0, 0, cdsize) << std::endl;
	return 0;
}
