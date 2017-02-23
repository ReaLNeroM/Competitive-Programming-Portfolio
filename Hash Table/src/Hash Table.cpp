#include <iostream>

typedef long long ll;

const int start = 10003;
class hashtable{
	int hash[start];

	public:
	hashtable(){
		for(int i = 0; i < start; i++){
			hash[i] = -1;
		}
	}
	int find(int val){
		return hash[val % start];
	}
	bool insert(int val, int secondval){
		val %= start;
		if(hash[val] != -1){
			return true;
		}
		hash[val] = secondval;

		return false;
	}
};
int main() {
	int n;
	std::cin >> n;

	hashtable H;
	for(int i = 0; i < n; i++){
		int firstval, secondval;
		std::cin >> firstval >> secondval;

		H.insert(firstval, secondval);
	}

	for(int i = 0; i < n; i++){
		int inp;
		std::cin >> inp;

		std::cout << H.find(inp) << std::endl;
	}
	return 0;
}
