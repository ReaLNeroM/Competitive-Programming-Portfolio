/*
ID: vlade.m1
PROG: ariprog
LANG: C++
 */

#include <fstream>
#include <algorithm>
#include <vector>

struct result{
	int start, space;

	bool operator<(const result &x) const{
		if(this->space != x.space){
			return (this->space < x.space);
		} else{
			return (this->start < x.start);
		}
	}
} copy;

int main() {
	std::ifstream fin("ariprog.in");
	std::ofstream fout("ariprog.out");
	int n, bound;
	fin >> n >> bound;

	std::vector<int> vals;
	for(int i = 0; i <= bound; i++){
		for(int j = i; j <= bound; j++){
			vals.push_back(i * i + j * j);
		}
	}

	std::sort(vals.begin(), vals.end());

	for(int i = 0; i < vals.size() - 1; i++){
		if(vals[i] == vals[i + 1]){
			vals.erase(vals.begin() + i + 1);
			i--;
		}
	}

	bool used[125001];
	for(int i = 0; i <= 125000; i++){
		used[i] = false;
	}
	for(int i = 0; i < vals.size(); i++){
		used[vals[i]] = true;
	}

	std::vector<result> res;
	bool good;
	int space;
	for(int i = 0; i < vals.size(); i++){
		for(int j = i + 1; j < vals.size(); j++){
			good = true, space = vals[j] - vals[i];
			for(int k = 0; k < n; k++){
				if(vals[i] + k * space > 125000 or (vals[i] + k * space <= 125000 and !used[vals[i] + k * space])){
					good = false;
					break;
				}
			}
			if(good){
				copy.start = vals[i], copy.space = space;
				res.push_back(copy);
			}
		}
	}

	std::sort(res.begin(), res.end());

	if(res.empty()){
		fout << "NONE" << std::endl;
	}
	for(int i = 0; i < res.size(); i++){
		fout << res[i].start << " " << res[i].space << std::endl;
	}
	return 0;
}
