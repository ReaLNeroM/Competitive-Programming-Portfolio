#include <iostream>

typedef long long ll;

int main() {
	ll teams;
	std::cin >> teams;

	teams *= 2;
	ll team[teams];
	for(int i = 0; i < teams; i++){
		team[i] = -1;
	}

	ll quality[teams][teams];
	quality[0][0] = 0;
	for(int i = 1; i < teams; i++){
		quality[i][i] = 0;
		for(int j = 0; j < i; j++){
			std::cin >> quality[i][j];
			quality[j][i] = quality[i][j];
		}
	}


	for(int i = 0; i < teams / 2; i++){
		ll biggesty = 0, biggestx = 0;
		for(int j = 0; j < teams; j++){
			for(int k = 0; k < teams; k++){
				if(team[j] == -1 and team[k] == -1 and quality[j][k] > quality[biggesty][biggestx]){
					biggesty = j, biggestx = k;
				}
			}
		}

		team[biggesty] = biggestx + 1;
		team[biggestx] = biggesty + 1;
	}

	for(int i = 0; i < teams; i++){
		std::cout << team[i] << ' ';
	}
	return 0;
}
