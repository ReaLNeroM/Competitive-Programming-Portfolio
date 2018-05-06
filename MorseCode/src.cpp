#include <string>
#include <vector>

typedef long long ll;

class MorseCode {
	std::string code[10] = {
			"-----",
			".----",
			"..---",
			"...--",
			"....-",
			".....",
			"-....",
			"--...",
			"---..",
			"----.",
	};
public:
	std::string decode(std::string s){
		std::string res = "";
		for(int i = 0; i < s.size(); i += 5){
			for(int j = 0; j < 10; j++){
				if(s.substr(i, 5) == code[j]){
					res += (char) ('0' + j);
				}
			}
		}

		return res;
	}
};
