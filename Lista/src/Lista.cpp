#include <iostream>
#include <vector>

typedef long long ll;

//1000100,1000???

int main() {
	std::vector<std::string> list;

	std::string input;
	std::cin >> input;

	std::string str = "";
	bool possible = true;
	for(ll i = 0; i <= input.length(); i++){
		if(input[i] == ',' or i == input.length()){
			if(str == "" or str[0] == '0'){
				possible = false;
			}

			list.push_back(str);
			str = "";
		} else {
			str += input[i];
		}
	}

	if(!possible){
		std::cout << "impossible";
	} else {
		for(ll i = 0; i < list[0].length(); i++){
			if(list[0][i] == '?'){
				list[0][i] = '0' + (i == 0);
			}
		}

		for(ll i = 1; i < list.size(); i++){
			if(list[i].length() > list[i - 1].length()){
				continue;
			}

			bool need = false;

// Celoto voa e greska, treba da se poklopat dvata for-a

//			for(ll j = list[i].length() - 1; j >= 0; j--){
//				if(list[i][j] == '?'){
//					list[i][j] = list[i - 1][j] + need;
//					if(list[i][j] > '9'){
//						need = true;
//					} else {
//						need = false;
//					}
//				} else if(list[i][j] > list[i - 1][j]){
//					need = false;
//				} else if(list[i][j] < list[i - 1][j]){
//					need = true;
//				}
//			}
//			if(list[i] == list[i - 1]){
//				for(ll j = list[i].length() - 1; j >= 0; j--){
//					if(list[i][j] == '?'){
//						list[i][j] = list[i - 1][j] + 1;
//						need = false;
//						break;
//					}
//				}
//			}
//			if(list[i].length() < list[i - 1].length()){
//				need = true;
//			}

			if(need){
				std::cout << "impossible";
				return 0;
			}
		}

		for(ll i = 0; i < list.size(); i++){
			std::cout << list[i];
			if(i != list.size() - 1){
				std::cout << ',';
			}
		}
	}

	return 0;
}
