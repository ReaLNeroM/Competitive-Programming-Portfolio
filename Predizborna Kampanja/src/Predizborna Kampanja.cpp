#include <iostream>

long long mat[21][21][21][21];

long long dp(int pos, int positive, int negative, int pn){
	if(mat[pos][positive][negative][pn] == -1){
		mat[pos][positive][negative][pn] = dp(pos + 1, positive, negative, pn);
		if(positive > 0){
			mat[pos][positive][negative][pn] += dp(pos + 1, positive - 1, negative, pn);
		}
		if(negative > 0){
			mat[pos][positive][negative][pn] += dp(pos + 1, positive, negative - 1, pn);
		}
		if(positive > 0 and negative > 0 and pn > 0){
			mat[pos][positive][negative][pn] += dp(pos + 1, positive - 1, negative - 1, pn - 1);
		}
	}

	return mat[pos][positive][negative][pn];
}
int main() {
	int tvstations, positive, negative, pn;
	std::cin >> tvstations >> positive >> negative >> pn;

	for(int i = 0; i < tvstations; i++){
		for(int j = 0; j <= positive; j++){
			for(int k = 0; k <= negative; k++){
				for(int l = 0; l <= pn; l++){
					mat[i][j][k][l] = -1;
				}
			}
		}
	}

	for(int i = 0; i <= positive; i++){
		for(int j = 0; j <= negative; j++){
			for(int k = 0; k <= pn; k++){
				mat[tvstations][i][j][k] = 1;
			}
		}
	}

	std::cout << dp(0, positive, negative, pn);
	return 0;
}
