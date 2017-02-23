/*
 ID: vlade.m1
 PROG: lgame
 LANG: C++
 */

//#define testing true

#ifdef testing
	#include <iostream>
	#define din std::cin
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream din("lgame.dict");
	std::ifstream fin("lgame.in");
	std::ofstream fout("lgame.out");
#endif

#include <vector>
#include <utility>
#include <algorithm>

const int maxdictsize = 40000;
const int alphabet[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

int dictsize = 0;
std::string dict[maxdictsize];

bool smaller(std::string a, std::string b) {
	for (int i = 0; i < std::min(a.length(), b.length()); i++) {
		if (a[i] > b[i]) {
			return false;
		} else if (a[i] < b[i]) {
			return true;
		}
	}

	if (a.length() > b.length()) {
		return false;
	}

	return true;
}

int exists(std::string str) {
	int left = 0, right = dictsize - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (smaller(str, dict[mid])) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	int val = 0;
	if(dict[left] == str){
		for (int i = 0; i < str.length(); i++) {
			val += alphabet[str[i] - 'a'];
		}
	}

	return val;
}

std::vector <std::pair <std::string, std::string> > list;
int val = 0;

void push(std::string a, std::string b){
	int sum = 0;
	if(exists(a)){
		sum += exists(a);

		if(b == "" or exists(b)){
			sum += exists(b);
			if(sum > val){
				list.clear();
				list.push_back(std::make_pair(a, b));
				val = sum;
			} else if(sum == val){
				list.push_back(std::make_pair(a, b));
			}
		}
	}
}

int main() {
	std::string curr;
	while (din >> curr) {
		if (curr == ".") {
			break;
		}
		dict[dictsize] = curr;
		dictsize++;
	}

	std::string str;
	fin >> str;
	std::sort(str.begin(), str.end());

	do {
		push(str, "");

		std::string a = "", b = "";
		for (int i = 0; i < str.length(); i++) {
			b += str[i];
		}

		for (int i = 0; i < str.length(); i++) {
			if (a.size() >= 3) {
				push(a, "");

				if(b.size() >= 3){
					if(smaller(a, b)){
						push(a, b);
					} else {
						push(b, a);
					}
				}
				if(b.size() == 4){
					b.erase(b.begin());
					if(smaller(a, b)){
						push(a, b);
					} else {
						push(b, a);
					}

					b.insert(b.begin(), ' ');
				}
			}

			a.push_back(str[i]);
			b.erase(b.begin());
		}
	} while (std::next_permutation(str.begin(), str.end()));

	std::stable_sort(list.begin(), list.end());

	fout << val << std::endl;
	for(int i = 0; i < list.size(); i++){
		if(i == list.size() - 1 or list[i] != list[i + 1]){
			fout << list[i].first;
			if(list[i].second != ""){
				fout << ' ' << list[i].second;
			}
			fout << std::endl;
		}
	}

	return 0;
}
