#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    int strings;
    std::cin >> strings;

    static std::pair<long long, int> list[60][50005];
    int size[60];

    for(int i = 0; i < 60; i++){
    	size[i] = 0;
    }

    std::string str;
    for (int i = 0; i < strings; i++) {
        std::cin >> str;
        for (int j = 0; j < str.length(); j++) {
            std::pair<long long, int> copy;
            copy.first = 0, copy.second = 1 << i;
            for (int k = 0; k < std::min((int) str.length() - j, 60); k++) {
                if(str[j + k] == 'b'){
                    copy.first |= (1LL << k);
                }

                list[k][size[k]] = copy;
                size[k]++;
            }
        }
    }

    for(int i = 59; i >= 0; i--){
    	if(size[i] > 0){
			std::sort(list[i], list[i] + size[i]);

			std::pair<long long, int> copy = list[i][0];
			for(int j = 0; j < size[i]; j++){
				if(copy.first == list[i][j].first){
					copy.second |= list[i][j].second;
				} else {
					if(copy.second == (1 << strings) - 1){
						std::cout << i + 1;
						return 0;
					}

					copy = list[i][j];
				}
			}

			if(copy.second == (1 << strings) - 1){
				std::cout << i + 1;
				return 0;
			}
    	}
    }

    std::cout << 0;
    return 0;
}
