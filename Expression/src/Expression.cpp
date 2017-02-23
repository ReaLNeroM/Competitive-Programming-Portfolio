#include <iostream>
#include <vector>

std::vector<std::vector<long long> > ways;
std::string val;

long long gen(int start, int end){
	if(ways[start][end] == -1){
		if(start > end){
			ways[start][end] = 1;
		} else {
			ways[start][end] = 0;

			for(int i = start + 1; i <= end; i++){
				if((val[start] == '?' and val[i] == '?')){
					if(i == end){
						ways[start][end] += 3 * gen(start + 1, i - 1);
					} else if(i == start + 1){
						ways[start][end] += 3 * gen(i + 1, end);
					} else {
						ways[start][end] += 3 * gen(start + 1, i - 1) * gen(i + 1, end);
					}
				} else if((val[i] == val[start] + 1) or (val[start] == '?' and val[i] % 2 != 0) or (val[start] % 2 == 0 and val[i] == '?')){
					if(i == end){
						ways[start][end] += gen(start + 1, i - 1);
					} else if(i == start + 1){
						ways[start][end] += gen(i + 1, end);
					} else {
						ways[start][end] += gen(start + 1, i - 1) * gen(i + 1, end);
					}
				}
			}

			ways[start][end] %= 100000;
		}
	}

	return ways[start][end];
}

int main() {
	int size;
	std::cin >> size >> val;

	for(int i = 0; i < val.length(); i++){
		//opening brackets( '(', '{', '[' are even numbers, closing brackets are odd numbers)
		switch (val[i]){
		case '(':
			val[i] = '0';
			break;
		case ')':
			val[i] = '1';
			break;
		case '[':
			val[i] = '4';
			break;
		case ']':
			val[i] = '5';
			break;
		case '{':
			val[i] = '8';
			break;
		case '}':
			val[i] = '9';
			break;
		}
	}
	ways.resize(size + 1);
	for(int i = 0; i <= size; i++){
		ways[i].resize(size + 1, -1);
	}

	std::cout << gen(0, size - 1);
	return 0;
}
