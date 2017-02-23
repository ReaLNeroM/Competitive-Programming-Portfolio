#include <iostream>
#include <queue>

int main() {
	int res;
	std::string str;
	std::cin >> res >> str;

	std::queue<char> last;
	last.push(str[0]);
	for(int i = 1; i < str.length(); i++){
		if(!last.empty() and str[i] + last.back() == '0' + '1'){
			last.pop();
			res -= 2;
		} else {
			last.push(str[i]);
		}
	}

	std::cout << res;
	return 0;
}
