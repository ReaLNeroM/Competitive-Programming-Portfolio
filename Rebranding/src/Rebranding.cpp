#include <iostream>

typedef long long ll;

int main() {
	std::string alphabet = "";
	for(char i = 'a'; i <= 'z'; i++){
		alphabet += i;
	}

	int length, designers;
	std::cin >> length >> designers;

	std::string str;
	std::cin >> str;

	for(int i = 0; i < designers; i++){
		char a, b;

		std::cin >> a >> b;

		for(int i = 0; i < alphabet.length(); i++){
			if(alphabet[i] == a){
				alphabet[i] = b;
			} else if(alphabet[i] == b){
				alphabet[i] = a;
			}
		}
	}

	for(int i = 0; i < length; i++){
		std::cout << alphabet[str[i] - 'a'];
	}

	return 0;
}
