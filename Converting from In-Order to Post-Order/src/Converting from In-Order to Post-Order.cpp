#include <iostream>
#include <cstring>
#include <stack>

int main() {
	std::string str;
	std::getline(std::cin, str);

	std::stack <std::string> izraz;

	for (int i = 2; i < str.length(); i++) {
		std::string piece = "";
		if (str[i] == ')') {
			std::string b = izraz.top();
			izraz.pop();
			std::string sign = izraz.top();
			izraz.pop();
			std::string a = izraz.top();
			izraz.pop();
			piece = a + ' ' + b + ' ' + sign;
			izraz.push(piece);
		} else if (str[i] == '-' or str[i] == '+' or str[i] == '*' or str[i] == '/') {
			piece += str[i];
			izraz.push(piece);
		} else if (str[i] >= '0' and str[i] <= '9') {
			while (str[i] >= '0' and str[i] <= '9') {
				piece += str[i];
				i++;
			}

			izraz.push(piece);
		}
	}

	std::cout << izraz.top();
}
