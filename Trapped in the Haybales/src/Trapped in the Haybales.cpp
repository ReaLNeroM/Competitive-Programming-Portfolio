#include <fstream>
#include <algorithm>

std::ofstream fout("trapped.out");
std::ifstream fin("trapped.in");

struct bale{
	int pos, size;

	bool operator<(const bale &x) const{
		return (pos < x.pos);
	}
};


int main() {
	int bales, pos;
	bale b[bales];
	fin >> bales >> pos;
	int minindex = -1, maxindex = -1;
	for(int i = 0; i < bales; i++){
		fin >> b[i].size >> b[i].pos;
		if(minindex == -1 or (b[i].pos < pos and b[minindex].pos < b[i].pos)){
			minindex = i;
		}
		if(maxindex == -1 or (b[i].pos > pos and b[maxindex].pos > b[i].pos)){
			maxindex = i;
		}
	}

	int min = 1000000000;

	std::sort(b, b + bales);

	for(int i )

	return 0;
}
