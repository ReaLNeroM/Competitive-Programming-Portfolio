#include <iostream>
#include <algorithm>
#include <vector>

struct bandera{
	int pos, cena, rad, use;
};

struct follower{
	int nowfirst = 0, nowsecond = 0;
	int first = 0, second = 0, value = 0;
	bool included = false;
} empty, copy;

int main() {
	int dolz, plata, banderi;
	std::cin >> dolz >> plata >> banderi;

	bool vkl[dolz];
	for(int i = 0; i < dolz; i++){
		vkl[i] = false;
	}

	std::vector<bandera> b(banderi);

	for(int i = 0; i < banderi; i++){
		std::cin >> b[i].pos >> b[i].cena >> b[i].rad;
		b[i].use = b[i].rad * 2;

		if(b[i].pos - b[i].rad < 0){
			b[i].use -= b[i].rad - b[i].pos;
		}
		if(b[i].pos + b[i].rad >= dolz){
			b[i].use -= b[i].pos + b[i].rad - dolz;
		}
	}

	follower best[plata + 1][banderi + 1];

	for(int i = 0; i <= plata; i++){
		best[i][0] = empty;
	}
	for(int j = 0; j <= banderi; j++){
		best[0][j] = empty;
	}
	for(int i = 1; i <= plata; i++){
		for(int j = 1; j <= banderi; j++){
			best[i][j].nowfirst = i, best[i][j].nowsecond = j - 1;
			best[i][j].first = i, best[i][j].second = j - 1;
			if(b[j - 1].cena > i){
				best[i][j].value = best[i][j - 1].value;
			} else {
				if(best[i - b[j - 1].cena][j - 1].value + b[j - 1].use > best[i][j - 1].value){
					best[i][j].included = true;
					best[i][j].first = i - b[j - 1].cena;
					best[i][j].value = best[i - b[j - 1].cena][j - 1].value + b[j - 1].use;
				} else {
					best[i][j].value = best[i][j - 1].value;
				}
			}
		}
	}

	follower pos = best[plata][banderi];

	while(pos.nowfirst + pos.nowsecond != 0){
		if(pos.included){
			for(int j = std::max(b[pos.nowsecond].pos - b[pos.nowsecond].rad, 0); j < std::min(b[pos.nowsecond].pos + b[pos.nowsecond].rad, dolz); j++){
				vkl[j] = true;
			}
		}

		pos = best[pos.first][pos.second];
	}

	int osvetl = 0, nedlgo = 0, najnedlgo = 0;

	for(int i = 0; i < dolz; i++){
		if(vkl[i]){
			najnedlgo = std::max(najnedlgo, nedlgo);
			nedlgo = 0;
			osvetl++;
		} else {
			nedlgo++;
		}
	}

	najnedlgo = std::max(najnedlgo, nedlgo);

	std::cout << osvetl << " " << najnedlgo;
	return 0;
}
