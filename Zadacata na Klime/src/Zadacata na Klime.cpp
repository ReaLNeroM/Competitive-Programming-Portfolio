#include <iostream>
#include <algorithm>

std::string num, fifthpow[22];
int parts[51];

std::string encode(long long n){
	std::string code = "";

	long long pow = 1;
	while(pow <= n){
		code.insert(code.begin(), '0' + (n % (pow * 2) == pow));
		n -= (n % (pow * 2) == pow) * pow;
		pow *= 2;
	}

	return code;
}

void genfifthpowers(){
	long long ite = 1;

	for(int i = 0; i < 22; i++){
		fifthpow[i] = encode(ite);
		ite *= 5;
	}
}

int part(int index){
	if(parts[index] == num.length() * 2){
		if(num[index] != '0'){
			for(int i = 0; i < 22 and index + fifthpow[i].length() <= num.length(); i++){
				if(std::equal(fifthpow[i].begin(), fifthpow[i].end(), num.begin() + index)){
					if(part(index + fifthpow[i].length()) + 1 < parts[index] - index){

					}
					parts[index] = std::min(parts[index], part(index + fifthpow[i].length()) + 1);
				}
			}
		}
	}

	return parts[index];
}

int main() {
	std::cin >> num;

	genfifthpowers();

	for(int i = 0; i < num.length(); i++){
		parts[i] = num.length() * 2;
	}
	parts[num.length()] = 0;

	if(part(0) > num.length()){
		std::cout << -1;
	} else {
		std::cout << part(0);
	}

	return 0;
}
