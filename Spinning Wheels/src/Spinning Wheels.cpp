/*
ID: vlade.m1
PROG: spin
LANG: C++
 */

#include <fstream>
#include <vector>

std::ifstream fin("spin.in");
std::ofstream fout("spin.out");

struct wheel{
	int speed;

	std::vector<int> wedgestart, wedgeend;
};

wheel w[5];

bool fit(int start, int end, int pos){
	if(pos == 5){
		return true;
	}

	int cmpend = end;
	if(end < start){
		cmpend += 360;
	}
	for(int i = 0; i < w[pos].wedgestart.size(); i++){
		int wcmp = 0;
		if(w[pos].wedgeend[i] < w[pos].wedgestart[i]){
			wcmp += 360;
		}

		for(int ite = -360; ite <= 360; ite += 360){
			if(start + ite <= w[pos].wedgestart[i] and w[pos].wedgeend[i] + wcmp <= cmpend + ite){
				if(fit(w[pos].wedgestart[i], w[pos].wedgeend[i], pos + 1)){
					return true;
				}
			} else if(start + ite <= w[pos].wedgeend[i] + wcmp and cmpend + ite >= w[pos].wedgeend[i] + wcmp){
				if(fit(start, w[pos].wedgeend[i], pos + 1)){
					return true;
				}
			} else if(start + ite <= w[pos].wedgestart[i] and w[pos].wedgestart[i] <= cmpend + ite){
				if(fit(w[pos].wedgestart[i], end, pos + 1)){
					return true;
				}
			} else if(start + ite >= w[pos].wedgestart[i] and cmpend + ite <= w[pos].wedgeend[i] + wcmp){
				if(fit(start, end, pos + 1)){
					return true;
				}
			}
		}
	}

	return false;
}

int main() {

	for(int i = 0, wedges; i < 5; i++){
		fin >> w[i].speed;

		fin >> wedges;

		for(int j = 0, start, size; j < wedges; j++){
			fin >> start >> size;
			w[i].wedgestart.push_back(start);
			w[i].wedgeend.push_back(start + size);
			if(w[i].wedgestart.back() >= 360){
				w[i].wedgestart.back() -= 360;
			}
			if(w[i].wedgeend.back() >= 360){
				w[i].wedgeend.back() -= 360;
			}
		}
	}

	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < w[0].wedgestart.size(); j++){
			if(fit(w[0].wedgestart[j], w[0].wedgeend[j], 1)){
				fout << i << std::endl;
				return 0;
			}
		}

		for(int j = 0; j < 5; j++){
			for(int k = 0; k < w[j].wedgestart.size(); k++){
				w[j].wedgestart[k] += w[j].speed;
				w[j].wedgeend[k] += w[j].speed;
				if(w[j].wedgestart[k] >= 360){
					w[j].wedgestart[k] -= 360;
				}
				if(w[j].wedgeend[k] >= 360){
					w[j].wedgeend[k] -= 360;
				}
			}
		}
	}

	fout << "none" << std::endl;
	return 0;
}
