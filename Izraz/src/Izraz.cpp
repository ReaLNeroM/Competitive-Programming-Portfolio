#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

std::string str, cifri;
std::priority_queue<int> min, max;

void removebrackets() {
	char sign, digsign;
	std::stack<char> s;
	bool found = false;
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '?' and count != 0) {
			if (((s.empty() or s.top() == '+') and digsign == '+') or ((s.empty() or s.top() == '-') and digsign == '-')) {
				max.push(count);
			} else {
				min.push(count);
			}
		}
		if (str[i] == '(') {
			sign = str[i - 1];
			if (!s.empty() and s.top() == '-') {
				if (sign == '-') {
					sign = '+';
				} else {
					sign = '-';
				}
			}
			s.push(sign);
		} else if (str[i] == ')') {
			s.pop();
		} else if (str[i] == '?') {
			if (count == 0) {
				if(i == 0 or str[i - 1] != '-'){
					digsign = '+';
				} else{
					digsign = '-';
				}
			}
			count++;
			continue;
		}
		count = 0;
	}

	if (count != 0) {
		if (digsign == '+') {
			max.push(count);
		} else {
			min.push(count);
		}
	}
}

std::string sum(std::string a, std::string b) {
	std::string buf;
	for (int i1 = a.length() - 1, i2 = b.length() - 1, carry = 0; (i1 >= 0 or i2 >= 0) or carry != 0; i1--, i2--) {
		int digit1 = (i1 < 0) ? 0 : a[i1] - '0';
		int digit2 = (i2 < 0) ? 0 : b[i2] - '0';

		int digit = digit1 + digit2 + carry;
		if (digit > 9) {
			carry = 1;
			digit -= 10;
		} else {
			carry = 0;
		}

		buf.insert(buf.begin(), digit + '0');
	}

	return buf;
}

std::string diff(std::string a, std::string b){
	std::string buf;
	for (int i1 = a.length() - 1, i2 = b.length() - 1, carry = 0; (i1 >= 0 or i2 >= 0) or carry != 0; i1--, i2--) {
		int digit1 = (i1 < 0) ? 0 : a[i1] - '0';
		int digit2 = (i2 < 0) ? 0 : b[i2] - '0';

		int digit = digit1 - digit2 - carry;
		if (digit < 0) {
			carry = 1;
			digit += 10;
		} else {
			carry = 0;
		}

		buf.insert(buf.begin(), digit + '0');
	}

	return buf;
}

std::string assign() {
	std::string result = "0", copy;
	while (!max.empty() or !min.empty()) {
		if (!max.empty() and (min.empty() or max.top() > min.top())) {
			copy = cifri[0];
			for (int i = 0; i < max.top() - 1; i++) {
				copy += "0";
			}
			result = sum(result, copy);

			cifri.erase(cifri.begin());
			max.pop();
			if (copy.length() > 1) {
				max.push(copy.length() - 1);
			}

		} else if (!min.empty()) {
			copy = cifri[cifri.length() - 1];
			for (int i = 0; i < min.top() - 1; i++) {
				copy += "0";
			}
			result = diff(result, copy);

			cifri.erase(cifri.end() - 1);
			min.pop();
			if (copy.length() > 1) {
				min.push(copy.length() - 1);
			}
		}
	}

	return result;
}

int main() {
	std::cin >> str >> cifri;

	std::sort(cifri.begin(), cifri.end(), std::greater<int>());

	removebrackets();

	std::cout << assign();
	return 0;
}
