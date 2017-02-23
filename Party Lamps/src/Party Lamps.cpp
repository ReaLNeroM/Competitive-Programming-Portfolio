/*
ID: vlade.m1
PROG: lamps
LANG: C++
*/

#include <fstream>
#include <algorithm>
#include <vector>

std::ifstream fin("lamps.in");
std::ofstream fout("lamps.out");

int lamps;
int change;
std::vector<int> must;
std::vector<std::string> res;

bool check(std::string &str){
	for(int i = 0; i < lamps; i++){
		if(must[i] != '2' and str[i] != must[i]){
			return false;
		}
	}

	return true;
}

bool compare(std::string x, std::string y){
	for(int i = 0; i < x.length(); i++){
		if(x[i] != y[i]){
			return (x[i] < y[i]);
		}
	}

	return true;
}

void button(int depth, int used, std::string str){
	if(change % 2 == used % 2){
		if(check(str)){
			res.push_back(str);
		}
	}
	if(depth > 0 and change > 0){
		button(depth - 1, used, str);
		for(int i = (depth == 3); i < lamps; i += depth - (depth >= 3)){
			str[i] = (str[i] + 1) % 2 + '0';
		}
		button(depth - 1, used + 1, str);
	}

}

int main() {
	fin >> lamps >> change;

	std::string str(lamps, '1');

	must.resize(lamps, '2');
	for(int i = 1, musts; i >= 0; i--){
		fin >> musts;
		while(musts != -1){
			must[musts - 1] = '0' + i;
			fin >> musts;
		}
	}

	button(4, (change % 4), str);

	std::sort(res.begin(), res.end(), compare);
	if(res.empty()){
		fout << "IMPOSSIBLE" << std::endl;
	}
	for(int i = 0; i < res.size(); i++){
		if(i == res.size() - 1 or res[i] != res[i + 1]){
			fout << res[i] << std::endl;
		}
	}
	return 0;
}
