/*
ID: vlade.m1
PROG: beads
LANG: C++
 */

#include <fstream>
#include <vector>

struct elem{
	int times = 0;
	char color = '0';
} copy;

int main(){
	std::ifstream in;
	std::ofstream out;
	in.open("beads.in");
	out.open("beads.out");
	int length;
	in >> length;
	std::vector<elem> chain;

	for(int i = 0; i < length; i++){
		char c;
		in >> c;
		if(copy.color == c or copy.color == '0'){
			copy.times++;
			copy.color = c;
		} else {
			chain.push_back(copy);
			copy.times = 1;
			copy.color = c;
		}
	}
	chain.push_back(copy);

	int max = 0;
	for(int i = 0; i < chain.size(); i++){
		int num = 0, copy = i, j = i;
		if(chain[i].color == 'w'){
			num += chain[i].times;
			j = (j + 1) % chain.size();
			copy++;
		}

		while((chain[copy % chain.size()].color == chain[j].color or chain[copy % chain.size()].color == 'w') and copy < chain.size() + i){
			num += chain[copy % chain.size()].times;
			copy++;
		}

		while(chain[copy % chain.size()].color != chain[j].color and copy < chain.size() + i){
			num += chain[copy % chain.size()].times;
			copy++;
		}

		max = std::max(max, num);
	}

	out << max << std::endl;
	return 0;
}
