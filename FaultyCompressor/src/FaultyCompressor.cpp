#include <string>
#include <vector>
using namespace std;

class FaultyCompressor {
public:
	string compressMe(string input) {
		int ite = 0;

		input += '0';
		std::string res = "";
		for(int i = 0; i < input.length() - 1; i++){
			if(input[i] == input[i + 1]){
				input.erase(input.begin() + i);
				ite++;
				i--;
			} else {
				res += input[i];
				ite++;
				std::string num = "";
				while(ite > 0){
					num += '0' + ite % 10;
					ite /= 10;
				}
				for(int i = num.length() - 1; i >= 0; i--){
					res += num[i];
				}
			}
		}

		return res;
	}
};
