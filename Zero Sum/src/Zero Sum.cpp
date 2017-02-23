/*
ID: vlade.m1
PROG: zerosum
LANG: C++
 */
#include <fstream>

std::ifstream fin("zerosum.in");
std::ofstream fout("zerosum.out");

bool check(std::string str){
	for(int i = 0; i < str.length(); i++){
		if(str[i] == ' '){
			str.erase(str.begin() + i);
		}
	}

	int num, sum = 0;
	int i = 1;
	while(!str.empty()){
		num = 0;
		for(i = (str[0] == '+' or str[0] == '-'); i < str.length() and str[i] != '+' and str[i] != '-'; i++){
			num *= 10;
			num += str[i] - '0';
		}
		if(str[0] == '-'){
			sum -= num;
		} else {
			sum += num;
		}

		str.erase(str.begin(), str.begin() + i);

	}

	return (sum == 0);
}

void pick(int pos, std::string str){
	if(pos >= str.length()){
		if(check(str)){
			fout << str << std::endl;
		}
		return;
	}

	pick(pos + 2, str);
	str[pos] = '+';
	pick(pos + 2, str);
	str[pos] = '-';
	pick(pos + 2, str);
}
int main(){
	int n;
	fin >> n;

	std::string str;
	for(int i = 0; i < 2 * n - 1; i++){
		if(i % 2 == 1){
			str.push_back(' ');
		} else{
			str.push_back('0' + (i / 2) + 1);
		}
	}

	pick(1, str);
}
