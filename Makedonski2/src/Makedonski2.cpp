#include <iostream>
#include <string>
using namespace std;

int main() {

	string soglaski = "АЕИОУаеиоу", stih;
	int result;
	bool no = false;
	do {
		getline(cin, stih);
		result = 0;

		for (int i = 0; i < stih.length(); i++) {
			if (stih[i] == 'Р' or stih[i] == 'р') {
				no = false;
				for (int j = 0; j < soglaski.length(); j++) {
					if ((i != 0 and stih[i - 1] == soglaski[j]) or (i != stih.length() - 1 and stih[i + 1] == soglaski[j])) {
						no = true;
						break;
					}
				}
				if (!no){
					result++;
				}
			} else{
				for (int j = 0; j < soglaski.length(); j++) {
					if (stih[i] == soglaski[j]) {
						result++;
						break;
					}
				}
			}
		}

		cout << result << std::endl;
	} while (stih != "0");

}
