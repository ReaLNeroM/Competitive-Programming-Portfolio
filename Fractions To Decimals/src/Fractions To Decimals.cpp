/*
ID: vlade.m1
PROG: fracdec
LANG: C++
 */
#include <fstream>

std::ifstream fin("fracdec.in");
std::ofstream fout("fracdec.out");

int main() {
	int a, b;
	fin >> a >> b;

	std::string result = "0";
	int units = 0;
	while (a >= b){
		a -= b;
		int carry = 1;
		for(int j = result.length() - 1; j >= 0; j--){
			if(result[j] + carry > '9'){
				result[j] = '0';
			} else {
				result[j] += 1;
				carry = 0;
				break;
			}
		}

		if(carry == 1){
			result.insert(result.begin(), '1');
		}
	}

	result += '.';
	a *= 10;
	if(a == 0){
		result.push_back('0');
	}
	bool usedremainder[b * 10 + 1];
	short remainderat[b * 10 + 1];
	for(int i = 0; i <= b * 10; i++){
		usedremainder[i] = false;
	}

	while(a != 0){
		if(usedremainder[a]){
			result.push_back(')');
			for(int i = 0; i < result.length(); i++){
				if(remainderat[i] == a){
					result.insert(result.begin() + i, '(');
					break;
				}
			}
			break;
		}
		usedremainder[a] = true;
		remainderat[result.length()] = a;
		if(a >= b){
			result.push_back('0' + a / b);
			a %= b;
			a *= 10;
		} else{
			result.push_back('0');
			a *= 10;
		}
	}
	for(int i = 0; i < result.length(); i += 76){
		for(int j = i; j < std::min(i + 76, (int) result.length()); j++){
			fout << result[j];
		}
		fout << std::endl;
	}
	return 0;
}
