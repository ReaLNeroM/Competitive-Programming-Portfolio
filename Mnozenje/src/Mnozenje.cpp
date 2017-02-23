#include <iostream>
#include <vector>
#include <algorithm>

const int base = 10;

std::string add(std::string a, std::string b) {
	std::string res = "";

	int carry = 0, i, end = std::min(a.length(), b.length());
	for (i = 0; i < end; i++) {
		if (a[a.length() - i - 1] - '0' + b[b.length() - i - 1] - '0' + carry >= base) {
			res += a[a.length() - i - 1] + b[b.length() - i - 1] - '0' + carry - base;
			carry = 1;
		} else {
			res += a[a.length() - i - 1] + b[b.length() - i - 1] - '0' + carry;
			carry = 0;
		}
	}

	while (i < a.length()) {
		if (a[a.length() - i - 1] - '0' + carry == base) {
			res += '0';
			carry = 1;
		} else {
			res += a[a.length() - i - 1] + carry;
			carry = 0;
		}

		i++;
	}
	while (i < b.length()) {
		if (b[b.length() - i - 1] - '0' + carry == base) {
			res += '0';
			carry = 1;
		} else {
			res += b[b.length() - i - 1] + carry;
			carry = 0;
		}

		i++;
	}

	if (carry == 1) {
		res += '1';
	}

	std::reverse(res.begin(), res.end());

	return res;
}

int main() {
	int digits[base];
	for (int i = 1; i <= base - 1; i++) {
		std::cin >> digits[i];
	}

	std::string a = "", b = "";

	for (int i = base - 1; i > 0; i--) {
		while (digits[i] > 0) {
			digits[i]--;
			if (a.length() < b.length() or (a.length() == b.length() and a < b)) {
				a += i + '0';
			} else {
				b += i + '0';
			}
		}
	}

	std::string res = "";

	for (int i = a.length() - 1; i >= 0; i--) {
		int carry = 0;
		std::string tmp = "";
		for(int j = a.length() - 1; j > i; j--){
			tmp += "0";
		}

		for (int j = b.length() - 1; j >= 0; j--) {
			tmp += '0' + (((a[i] - '0') * (b[j] - '0') + carry) % base);
			carry = ((a[i] - '0') * (b[j] - '0') + carry) / base;
		}

		if (carry > 0) {
			tmp += '0' + carry;
		}

		std::reverse(tmp.begin(), tmp.end());
		res = add(res, tmp);
	}

	std::cout << res << std::endl;
}
