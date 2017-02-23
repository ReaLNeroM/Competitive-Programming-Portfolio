/*
 ID: vlade.m1
 PROG: lgame
 LANG: C++
*/

#define mycomputer true

#ifdef mycomputer
#include <iostream>
#define fin std::cin
#define fdict std::cin
#define fout std::cout
#else
#include <fstream>
std::ifstream fin("lgame.in");
std::ofstream fout("lgame.out");
std::ifstream fdict("lgame.dict");
#endif

#include <vector>
#include <algorithm>

typedef long long ll;

int value[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int entry = 0;
std::string dict[40000];
//jicuzza

bool greater(std::string &str, std::string &a){
	int min = std::min(str.length(), a.length());
	for(int i = 0; i < min; i++){
		if(str[i] > a[i]){
			return true;
		} else if(str[i] < a[i]){
			return false;
		}
	}

	if(str.length() > a.length()){
		return true;
	}

	return false;
}

bool exists(std::string &str){
	int l = 0, r = entry - 1;
	while(l <= r){
		int mid = l + (r - l) / 2;

		if(str == dict[mid]){
			return true;
		} else if(greater(str, dict[mid])){
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return false;
}

bool cmp(std::pair<std::string, std::string> a, std::pair<std::string, std::string> b){
	if(a.first > b.first){
		return true;
	} else if(a.first < b.first){
		return false;
	} else {
		if(a.second > b.second){
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	std::string str = "";

	while(fdict >> str){
		if(str == "."){
			break;
		}
		dict[entry] = str;
		entry++;
	}

	fout << entry << std::endl;
	fin >> str;

	std::vector<std::pair<std::string, std::string> > v;
	int maxscore = 0;

	do{
		std::string a = "", b = "";
		int ascore = 0, bscore = 0;
		for(int i = 0; i < str.size(); i++){
			b += str[i];
		}

		for(int i = 0; i < str.size(); i++){
			a += str[i];
			b.erase(b.begin());

			if(exists(a)){
				if(exists(b)){
					if(ascore + bscore > maxscore){
						maxscore = ascore + bscore;

						v.clear();
						v.push_back(make_pair(a, b));
					} else if(ascore + bscore == maxscore){
						v.push_back(make_pair(a, b));
					}
				} else {
					if(ascore > maxscore){
						maxscore = ascore;

						v.clear();
						v.push_back(make_pair(a, ""));
					} else if(ascore == maxscore){
						v.push_back(make_pair(a, ""));
					}
				}
			}
		}
	} while(std::next_permutation(str.begin(), str.end()));
	for(int i = 0; i < v.size(); i++){
		if(greater(v[i].second, v[i].first)){
			std::swap(v[i].first, v[i].second);
		}
	}

	std::sort(v.begin(), v.end(), cmp);
	std::vector<std::pair<std::string, std::string> >::iterator ite = std::unique(v.begin(), v.end());
	v.erase(ite, v.end());

	fout << maxscore << std::endl;
	for(int i = 0; i < v.size(); i++){
		fout << v[i].first << ' ' << v[i].second << std::endl;
	}
	return 0;
}
