#include <iostream>
#include <vector>
#include <cmath>

//int dp(int depth = 0, int div1 = 0){
//	if(depth == dvds){
//		return (std::abs(zbir - div1 - div1));
//	}
//	if(res[depth][div1] == -1){
//		res[depth][div1] = std::min(dp(depth + 1, div1 + val[depth]), dp(depth + 1, div1));
//	}
//
//	return res[depth][div1];
//}

int main(){
	int dvds, zbir = 0;
	std::cin >> dvds;

	std::vector<int> val(dvds);
	for(int i = 0; i < dvds; i++){
		std::cin >> val[i];
		zbir += val[i];
	}

	std::vector<int> res[2];
	res[0].resize(zbir + 1);
	res[1].resize(zbir + 1);
	for(int j = 0; j <= zbir; j++){
		res[0][j] = res[1][j] = std::abs(zbir - j - j);
	}

	for(int i = dvds - 1; i >= 0; i--){
		for(int j = zbir; j >= 0; j--){
			if(j + val[i] > zbir){
				res[i % 2][j] = res[(i + 1) % 2][j];
			} else {
				res[i % 2][j] = std::min(res[(i + 1) % 2][j], res[(i + 1) % 2][j + val[i]]);
			}
		}
	}

	std::cout << zbir / 2 - res[0][0] / 2;
	std::cout << " ";
	std::cout << zbir / 2 + res[0][0] / 2 + (zbir % 2);
	return 0;
}
