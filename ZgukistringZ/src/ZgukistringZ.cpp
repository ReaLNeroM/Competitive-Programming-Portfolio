#include <iostream>

int main() {
	std::string strletters, strgood[2];

	std::cin >> strletters >> strgood[0] >> strgood[1];

	int letters[26], good[2][26];
	for(int i = 0; i < 26; i++){
		letters[i] = good[0][i] = good[1][i] = 0;
	}

	for(int i = 0; i < strletters.length(); i++){
		letters[strletters[i] - 'a']++;
	}

	std::string s = "HELLO WORLD";

	for(int i = 0; i < strgood[0].length(); i++){
		good[0][strgood[0][i] - 'a']++;
	}
	for(int i = 0; i < strgood[1].length(); i++){
		good[1][strgood[1][i] - 'a']++;
	}

	bool enough = true;
	int resfirst = 0, ressecond = 0;
	for(int i = 0, leastsecond; !enough; i++){
		leastsecond = strletters.length();

		for(int j = 0; j < 26; j++){
			if(letters[j] - i * good[0][j] < 0){
				enough = false;
			} else {
				leastsecond = std::min(leastsecond, (letters[j] - i * good[0][j]) / good[1][j]);
			}
		}

		if(enough and i + leastsecond > resfirst + ressecond){
			resfirst = i, ressecond = leastsecond;
		}
	}

	for(int i = 0; i < resfirst; i++){
		std::cout << strgood[0];
	}
	for(int i = 0; i < ressecond; i++){
		std::cout << strgood[1];
	}

	std::cout << resfirst << " " << ressecond << std::endl;

	for(int i = 0; i < 26; i++){
		for(int j = letters[i] - resfirst * good[0][i] - ressecond * good[1][i]; j > 0; j--){
			std::cout << (char) ('a' + i);
		}
	}

	return 0;
}
