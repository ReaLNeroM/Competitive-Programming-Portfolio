/*
	ID: vlade.m1
	LANG: C++
	PROG: skidesign
 */
#include <fstream>

#define mine i - 17

int main() {
	std::ifstream inp;
	std::ofstream outp;
	inp.open("skidesign.in"), outp.open("skidesign.out");
	int n;
	inp >> n;

	int h[n];
	for(int i = 0; i < n; i++){
		inp >> h[i];
	}

	long long result = 10000000;
	for(int i = 18; i <= 83; i++){
		long long copy = 0;
		for(int j = 0; j < n; j++){
			if(h[j] < mine){
				copy += (mine - h[j]) * (mine - h[j]);
			} else if(h[j] > i){
				copy += (h[j] - i) * (h[j] - i);
			}
		}

		result = std::min(result, copy);
	}

	outp << result << std::endl;

	return 0;
}
