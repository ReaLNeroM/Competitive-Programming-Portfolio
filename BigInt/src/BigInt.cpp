#include <iostream>
#include <algorithm>

const int base = 10;

struct BigInt {
	std::vector<int> v;
	int sign;

	void parse(std::string &str){
		sign = 1;

		int start = 0;

		if(str[start] == '-'){
			sign *= -1;
			start++;
		}

		while(start < str.length() - 1 and str[start] == '0'){
			start++;
		}
		for(int i = start; i < str.length(); i++){
			v.push_back(str[i] - '0');
		}

	}
	std::string print(){
		std::string res = "";
		if(sign == -1){
			res += '-';
		}

		for(int i = v.size() - 1; i >= 0; i--){
			res += v[i] + '0';
		}

		return res;
	}
};

bool bigger(BigInt a, BigInt b){ // a > b return true
	if(a.v[0] == 0 and b.v[0] == 0){
		return false;
	}
	if(a.sign < b.sign){
		return false;
	} else if(a.sign > b.sign){
		return true;
	} else {
		bool changer = (a.sign == -1); // for negatives, bigger is worse
		if(a.v.size() > b.v.size()){
			return (true ^ changer);
		} else if(a.v.size() < b.v.size()){
			return (false ^ changer);
		} else {
			for(int i = a.v.size() - 1; i >= 0; i--){
				if(a.v[i] != b.v[i]){
					return ((a.v[i] > b.v[i]) ^ changer);
				}
			}
		}
	}

	return false;
}

BigInt abs_add(BigInt a, BigInt b){
	int size = std::max(a.v.size(), b.v.size());
	int carry = 0;

	BigInt res;
	res.v.resize(size);
	res.sign = a.sign;

	for(int i = 0; i < size; i++){
		if(i < a.v.size()){
			res.v[i] += a.v[i];
		}
		if(i < b.v.size()){
			res.v[i] += b.v[i];
		}

		res.v[i] += carry;
		if(res.v[i] >= base){
			res.v[i] -= base;
			carry = 1;
		} else {
			carry = 0;
		}
	}

	if(carry == 1){
		res.v.push_back(1);
	}

	return res;
}

BigInt abs_sub(BigInt a, BigInt b){

}

BigInt add(BigInt a, BigInt b){
	if(a.sign == b.sign){
		return add(a, b);
	} else {

	}
}

BigInt sub(BigInt a, BigInt b){
	b.sign *= -1;
	add(a, b);
}

BigInt mult(BigInt a, BigInt b){

}

BigInt div(BigInt a, BigInt b){

}

int main() {
	std::string str1, str2;
	std::cin >> str1 >> str2;

	BigInt a, b;

	a.parse(str1);
	b.parse(str2);

	std::cout << ((bigger(a, b)) ? "true" : "false");
}
