#include <iostream>
#include <stack>

typedef long long ll;

int main() {
	std::string str;
	std::getline(std::cin, str);

	std::stack <int> stint;
	std::stack <std::string> st;

	for (int i = 0; i < str.length(); i++) {
		int a, b;
		if (str[i] == '+' or str[i] == '-' or str[i] == '*' or str[i] == '/') {
			b = stint.top();
			stint.pop();
			a = stint.top();
			stint.pop();
			if (str[i] == '+') {
				stint.push(a + b);
			} else if (str[i] == '-') {
				stint.push(a - b);
			} else if (str[i] == '*') {
				stint.push(a * b);
			} else if (str[i] == '/') {
				stint.push(a / b);
			}
		} else if (str[i] >= '0' and str[i] <= '9') {
			int num = 0;
			while (str[i] != ' ') {
				num *= 10;
				num += str[i] - '0';
				i++;
			}
			stint.push(num);
		}
	}

	std::cout << stint.top();
	return 0;
}
