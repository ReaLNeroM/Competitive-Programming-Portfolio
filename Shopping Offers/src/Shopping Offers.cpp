/*
ID: vlade.m1
PROG: shopping
LANG: C++
 */

#ifdef test
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("shopping.in");
	std::ofstream fout("shopping.out");
#endif

#include <vector>

struct offer{
	int price;

	std::vector<int> item, count;
};

struct item{
	int id, cost, need;
};

int main() {
	int offers;
	fin >> offers;

	offer o[offers];
	for(int i = 0, offered; i < offers; i++){
		fin >> offered;
		for(int j = 0, id, amount; j < offered; j++){
			fin >> id >> amount;
			o[i].item.push_back(id);
			o[i].count.push_back(amount);
		}

		fin >> o[i].price;
	}

	int items;
	fin >> items;

	item p[1001];
	int dp[6][6][6][6][6];
	int itemid[5];
	for(int i = 0; i <= 1000; i++){
		p[i].id = 0, p[i].cost = 1000, p[i].need = 0;
	}
	for(int i = 0, id; i < items; i++){
		fin >> id;
		itemid[i] = id;
		p[id].id = i;

		fin >> p[id].need >> p[id].cost;
	}
	for(int i = items; i < 5; i++){
		itemid[i] = 1000;
	}

	int left[5];
	for(int i = 0; i <= 5; i++){
		left[0] = i;
		for(int j = 0; j <= 5; j++){
			left[1] = j;
			for(int k = 0; k <= 5; k++){
				left[2] = k;
				for(int l = 0; l <= 5; l++){
					left[3] = l;
					for(int m = 0; m <= 5; m++){
						left[4] = m;
						dp[left[0]][left[1]][left[2]][left[3]][left[4]] = 0;

						int copy[5];
						for (int ite = 0; ite < 5; ite++) {
							dp[left[0]][left[1]][left[2]][left[3]][left[4]] += left[ite] * p[itemid[ite]].cost;
							copy[ite] = left[ite];
						}

						for (int ite = 0; ite < offers; ite++) {
							bool good = true;
							for (int jte = 0; jte < o[ite].item.size(); jte++) {
								copy[p[o[ite].item[jte]].id] -= o[ite].count[jte];

								if(copy[p[o[ite].item[jte]].id] < 0){
									good = false;
								}
							}

							if(good){
								dp[left[0]][left[1]][left[2]][left[3]][left[4]] = std::min(dp[left[0]][left[1]][left[2]][left[3]][left[4]],
										o[ite].price + dp[copy[0]][copy[1]][copy[2]][copy[3]][copy[4]]);
							}

							for (int jte = 0; jte < o[ite].item.size(); jte++) {
								copy[p[o[ite].item[jte]].id] = left[p[o[ite].item[jte]].id];
							}
						}

					}
				}
			}
		}
	}


	fout << dp[p[itemid[0]].need][p[itemid[1]].need][p[itemid[2]].need][p[itemid[3]].need][p[itemid[4]].need] << std::endl;
	return 0;
}
