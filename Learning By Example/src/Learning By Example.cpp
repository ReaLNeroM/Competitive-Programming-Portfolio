#include <iostream>
#include <algorithm>

struct cow{
	bool spot;
	int pos;

	bool operator<(const cow &x) const{
		return (pos < x.pos);
	}
};

int main() {
	int cows, start, end;
	std::cin >> cows >> start >> end;
	cow c[cows];

	for(int i = 0; i < cows; i++){
		std::string str;
		std::cin >> str >> c[i].pos;
		c[i].spot = (str[0] == 'S');
	}

	std::sort(c, c + cows);

	int result = 0;
	for(int i = 1; i < cows - 1; i++){
		if(c[i].spot){
			if
		}
	}
	if(c[0].spot and c[0].pos > start){
		result += c[0].pos - start;
	}
	if(c[cows - 1].spot and c[cows - 1].pos < end){
		result += end - c[cows - 1].pos;
	}
	std::cout << result << std::endl;
	return 0;
}
