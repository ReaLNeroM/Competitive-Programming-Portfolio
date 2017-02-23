#include <iostream>
#include <vector>

int main(){
	int digits;
	std::cin >> digits;
	std::vector<long long> p;

	long long currd, i = 2, num = 1;
	do {
		currd = 0;
		for(int copy = num; copy > 0; copy /= 10){
			currd++;
		}
		if(currd == digits){
			p.push_back(i - 1);
		}
		num *= i;
		i++;
	} while(currd <= digits);

	if(p.empty()){
		std::cout << "NO";
	} else{
		for(int i = 0; i < p.size(); i++){
			std::cout << p[i] << std::endl;
		}
	}
}
