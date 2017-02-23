#include <fstream>

std::ifstream fin("whatbase.in");
std::ofstream fout("whatbase.out");

int main(){
	int cases;
	fin >> cases;

	long long
	int wina[cases], winb[cases];
	for(int i = 0, xbase, ybase; i < cases; i++){
		fin >> xbase >> ybase;

	}

	for(int i = 0; i < cases; i++){
		fout << wina[i] << " " << winb[i] << std::endl;
	}
}
