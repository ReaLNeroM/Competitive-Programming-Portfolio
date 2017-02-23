/*
ID: vlade.m1
PROG: holstein
LANG: C++
 */

#include <fstream>
#include <vector>

std::ifstream fin("holstein.in");
std::ofstream fout("holstein.out");

const int maxvits = 25, maxfeeds = 15;
int vits, feeds;
int f[maxfeeds][maxvits], need[maxvits], curr[maxvits];
std::vector<int> res, best;

int atfeed(int depth = 0, int taken = 0){
	if(depth == feeds){
		for(int i = 0; i < vits; i++){
			if(curr[i] < need[i]){
				return maxvits;
			}
		}
		if(taken < best.size()){
			best = res;
			return taken;
		}

		return maxvits;
	}

	res.push_back(depth);
	for(int i = 0; i < vits; i++){
		curr[i] += f[depth][i];
	}
	int min = atfeed(depth + 1, taken + 1);
	for(int i = 0; i < vits; i++){
		curr[i] -= f[depth][i];
	}
	res.pop_back();

	min = std::min(min, atfeed(depth + 1, taken));
	return min;
}

int main() {
	fin >> vits;
	for(int i = 0; i < vits; i++){
		fin >> need[i];
		curr[i] = 0;
	}
	fin >> feeds;
	for(int i = 0; i < feeds; i++){
		for(int j = 0; j < vits; j++){
			fin >> f[i][j];
		}
	}
	best.resize(maxvits, -1);

	fout << atfeed() << " ";
	for(int i = 0; i < best.size(); i++){
		fout << best[i] + 1;
		if(i != best.size() - 1){
			fout << " ";
		}
	}
	fout << std::endl;
	return 0;
}
