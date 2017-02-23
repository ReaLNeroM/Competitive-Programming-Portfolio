/*
ID: vlade.m1
PROG: sort3
LANG: C++
 */
#include <fstream>
std::ifstream fin("sort3.in");
std::ofstream fout("sort3.out");


int main() {
	int values;
	fin >> values;

	int points[] = {0, 0, 0, 0}, val[values];
	for(int i = 0; i < values; i++){
		fin >> val[i];
		for(int j = 3; j >= val[i]; j--){
			points[j]++;
		}
	}

	int res = 0;
	for(int i = 0; i < values; i++){
		if(i < points[val[i] - 1] or i >= points[val[i]]){
			for(int j = points[val[i] - 1]; j < points[val[i]]; j++){
				if(points[val[j] - 1] <= i and points[val[j]] > i){
					std::swap(val[i], val[j]);
					res++;
					break;
				}
			}
		}
		if(points[val[i] - 1] > i or points[val[i]] <= i){
			for(int j = points[val[i] - 1]; j < points[val[i]]; j++){
				if(points[val[j] - 1] > j or points[val[j]] <= j){
					std::swap(val[j], val[i]);
					res++;
					break;
				}
			}
		}

	fout << res << std::endl;
	return 0;
}
