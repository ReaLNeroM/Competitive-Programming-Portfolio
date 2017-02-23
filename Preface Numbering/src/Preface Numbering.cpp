/*
ID: vlade.m1
PROG: preface
LANG: C++
 */

#include <fstream>

std::ifstream fin("preface.in");
std::ofstream fout("preface.out");

int use[7];

void make(int n){
	int atdigit = 0;

	while(n > 0){
		switch (n % 10){
			case 1:
				use[(atdigit * 2)]++;
				break;
			case 2:
				use[(atdigit * 2)] += 2;
				break;
			case 3:
				use[(atdigit * 2)] += 3;
				break;
			case 4:
				use[(atdigit * 2)]++;
				use[(atdigit * 2) + 1]++;
				break;
			case 5:
				use[(atdigit * 2) + 1]++;
				break;
			case 6:
				use[(atdigit * 2) + 1]++;
				use[(atdigit * 2)]++;
				break;
			case 7:
				use[(atdigit * 2) + 1]++;
				use[(atdigit * 2)] += 2;
				break;
			case 8:
				use[(atdigit * 2) + 1]++;
				use[(atdigit * 2)] += 3;
				break;
			case 9:
				use[(atdigit * 2)]++;
				use[(atdigit * 2) + 2]++;
				break;
		}

		n /= 10;
		atdigit++;
	}
}

int main() {
	int lastpage;
	fin >> lastpage;

	for(int i = 0; i < 7; i++){
		use[i] = 0;
	}
	for(int i = 1; i <= lastpage; i++){
		make(i);
	}

	for(int i = 0; i < 7; i++){
		if(use[i] != 0){
			switch(i){
			case 0:
				fout << 'I';
				break;
			case 1:
				fout << 'V';
				break;
			case 2:
				fout << 'X';
				break;
			case 3:
				fout << 'L';
				break;
			case 4:
				fout << 'C';
				break;
			case 5:
				fout << 'D';
				break;
			case 6:
				fout << 'M';
				break;
			}
			fout << " " << use[i] << std::endl;
		}
	}
	return 0;
}
