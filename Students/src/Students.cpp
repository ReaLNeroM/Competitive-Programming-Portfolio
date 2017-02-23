#include <iostream>
#include <vector>

int main() {
	int cases;
	std::cin >> cases;

	int teamsize[2], teamavg[2], teamavgfloor[2];
	int team[2][20000];

	int res[cases];
	for(int i = 0; i < cases; i++){
		res[i] = 0;

		for(int j = 0; j < 2; j++){
			std::cin >> teamsize[j];
			teamavg[j] = 0;

			for(int k = 0; k < teamsize[j]; k++){
				std::cin >> team[j][k];
				teamavg[j] += team[j][k];
			}

			teamavgfloor[j] = (teamavg[j] % teamsize[j] != 0);
			teamavg[j] = teamavg[j] / teamsize[j];
		}


		for(int j = 0; j < 2; j++){
			for(int k = 0; k < teamsize[j]; k++){
				if(team[j][k] < teamavg[j] + teamavgfloor[1 - j] and team[j][k] > teamavg[1 - j]){
					res[i]++;
				}
			}
		}
	}

	for(int i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
