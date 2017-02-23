#include <iostream>
#include <algorithm>

//std::ifstream fin("learning.in");
//std::ofstream fout("learning.out");

#define fin std::cin
#define fout std::cout

int main(){
	int cows, a, b;
	fin >> cows >> a >> b;

	std::pair<int, bool> c[cows];
	for(int i = 0; i < cows; i++){
		std::string s;
		fin >> s >> c[i].first;

		if(s == "S"){
			c[i].second = true;
		} else {
			c[i].second = false;
		}
	}


	std::sort(c, c + cows);

	int res = 0;
	if(c[0].first > a and c[0].second){
		res += c[0].first - a;
	}
	if(c[cows - 1].first < b and c[cows - 1].second){
		res += b - c[cows - 1].first;
	}

	for(int i = 0; i < cows - 1; i++){
		if(c[i].second){
			res++;
		}

		if((c[i + 1].first - c[i].first - 1) % 2 == 1 and (c[i].second or c[i + 1].second)){
			res++;
		}

		if(c[i].second){
			res += (c[i + 1].first - c[i].first - 1) / 2;
		}
		if(c[i + 1].second){
			res += (c[i + 1].first - c[i].first - 1) / 2;
		}
	}
	res += c[cows - 1].second;

	fout << res;
}
