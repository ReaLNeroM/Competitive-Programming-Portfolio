#include <iostream>

int main() {
	std::string ip;
	std::cin >> ip;

	int ways = 0;
	std::string check = "255", stri = "", strj = "", strk = "", strl = "";
	for(int i = 0; i < ip.length() - 1; i++){
		stri += ip[i];
		if((stri[0] == '0' and stri.length() > 1) or stri.length() > check.length() or (stri.length() == check.length() and stri > check)){
			break;
		}
		strj = "";
		for(int j = i + 1; j < ip.length() - 1; j++){
			strj += ip[j];
			if((strj[0] == '0' and strj.length() > 1) or strj.length() > check.length() or (strj.length() == check.length() and strj > check)){
				break;
			}
			strk = "";
			for(int k = j + 1; k < ip.length() - 1; k++){
				strk += ip[k];
				if((strk[0] == '0' and strk.length() > 1) or strk.length() > check.length() or (strk.length() == check.length() and strk > check)){
					break;
				}
				strl = "";
				for(int l = k + 1; l < ip.length(); l++){
					strl += ip[l];
				}
				if((strl[0] == '0' and strl.length() > 1) or strl.length() > check.length() or (strl.length() == check.length() and strl > check)){
				} else {
					ways++;
				}
			}
		}
	}

	std::cout << ways;
	return 0;
}
