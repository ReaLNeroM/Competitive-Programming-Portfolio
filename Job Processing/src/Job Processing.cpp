/*
ID: vlade.m1
PROG: job
LANG: C++
 */

//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("job.in");
	std::ofstream fout("job.out");
#endif

#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	int a, b, jobs;
	fin >> jobs >> a>> b;

	int speeda[a], queuea[a];
	for (int i = 0; i < a; i++){
		fin >> speeda[i];
		queuea[i] = 0;
	}
	std::sort(speeda, speeda + a);

	int speedb[b], queueb[b];
	for (int i = 0; i < b; i++){
		fin >> speedb[i];
		queueb[i] = 0;
	}
	std::sort(speedb, speedb + b);

	std::vector<int> dumpa, dumpb;
	for (int i = 0; i < jobs; i++) {
		int min = 0;
		for (int j = 0; j < a; j++) {
			if (queuea[min] + speeda[min] > queuea[j] + speeda[j]) {
				min = j;
			}
		}

		queuea[min] += speeda[min];
		dumpa.push_back(queuea[min]);
	}

	for (int i = 0; i < jobs; i++) {
		int min = 0;
		for (int j = 0; j < b; j++) {
			if (queueb[min] + speedb[min] > queueb[j] + speedb[j]) {
				min = j;
			}
		}

		queueb[min] += speedb[min];
		dumpb.push_back(queueb[min]);
	}

	int max = 0;
	for(int i = 0; i < dumpa.size(); i++){
		max = std::max(max, dumpa[i] + dumpb[dumpb.size() - i - 1]);
	}

	fout << dumpa.back() << ' ';
	fout << max << std::endl;
	return 0;
}
