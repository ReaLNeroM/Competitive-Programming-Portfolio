//============================================================================
// Name        : Trapped.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <algorithm>
#include <vector>
struct bale{
	int pos, size;

	bool operator<(const bale &x) const{
		return (pos < x.pos);
	}
};

const int maxb = 100000;
int bales, pos;
bale b[maxb];
int min = 1000000000;
std::vector<std::vector<int> > res;

int attempt(int start, int end){
	if(start < 0 or end >= bales){
		return 1000000000;
	}
	if(res[start][end - start] == -1){
		int min = 1000000000;
		if(b[end].pos - b[start].pos - b[start].size > 0 and b[end].pos - b[start].pos - b[end].size <= 0){
			min = std::min(b[end].pos - b[start].pos - b[start].size, attempt(start - 1, end));
		} else if(b[end].pos - b[start].pos - b[start].size <= 0 and b[end].pos - b[start].pos - b[end].size > 0){
			min = std::min(b[end].pos - b[start].pos - b[end].size, attempt(start, end + 1));
		} else if(b[end].pos - b[start].pos - b[start].size > 0 and b[end].pos - b[start].pos - b[end].size > 0){
			min = attempt(start - 1, end + 1);
			int change = b[end].pos - b[start].pos - b[start].size, max = 0;
			b[start].size += change;
			max = change + attempt(start, end + 1);
			b[start].size -= change;
			change = b[end].pos - b[start].pos - b[end].size;
			b[end].size += change;
			min = std::min(max, change + attempt(start - 1, end));
			b[end].size -= change;
		} else{
			min = 0;
		}
		res[start][end - start] = min;
	}

	return res[start][end - start];
}

int main() {
	std::ifstream fin("trapped.in");
	std::ofstream fout("trapped.out");
	fin >> bales >> pos;
	for(int i = 0; i < bales; i++){
		fin >> b[i].size >> b[i].pos;
	}

	std::sort(b, b + bales);

	int smaller = -1, bigger;
	for(int i = 0; i < bales - 1; i++){
		if(b[i].pos < pos and b[i + 1].pos > pos){
			smaller = i, bigger = i + 1;
			break;
		}
	}

	if(smaller == -1){
		fout << -1 << std::endl;
	} else{
		std::vector<int> copy(bales - bigger + 1, -1);
		for(int i = smaller; i >= 0; i--){
			res.push_back(copy);
		}
		fout << attempt(smaller, bigger) << std::endl;
	}
	return 0;
}
