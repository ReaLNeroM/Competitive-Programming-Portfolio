/*
ID: vlade.m1
PROG: comehome
LANG: C++
 */
#include <fstream>

std::ifstream fin("comehome.in");
std::ofstream fout("comehome.out");

int encode(char c){
	return c - 'A' - 6 * (c > 'Z');
}
int main() {
	int edges;
	fin >> edges;
	int adjMatrix[52][52];
	for(int i = 0; i < 52; i++){
		for(int j = 0; j < 52; j++){
			adjMatrix[i][j] = 500000000;
		}
		adjMatrix[i][i] = 0;
	}

	for(int i = 0, cost; i < edges; i++){
		char first, second;
		fin >> first >> second >> cost;

		adjMatrix[encode(first)][encode(second)] = std::min(adjMatrix[encode(first)][encode(second)], cost);
		adjMatrix[encode(second)][encode(first)] = std::min(adjMatrix[encode(second)][encode(first)], cost);
	}

	for(int i = 0; i < 52; i++){
		for(int j = 0; j < 52; j++){
			for(int k = 0; k < 52; k++){
				adjMatrix[j][k] = std::min(adjMatrix[j][k], adjMatrix[j][i] + adjMatrix[i][k]);
			}
		}
	}

	int best = 500000000;
	char bestchar;
	for(int i = 0; i < 25; i++){
		if(best > adjMatrix[i][25]){
			bestchar = 'A' + i;
			best = adjMatrix[i][25];
		}
	}

	fout << bestchar << " " << best << std::endl;
	return 0;
}
