#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::string photos;
	std::cin >> photos;

	std::vector<std::string> res;
	for(int i = 0; i < photos.length(); i++){
		for(char j = 'a'; j <= 'z'; j++){
			photos.insert(photos.begin() + i, j);
			res.push_back(photos);
			photos.erase(photos.begin() + i);
		}
	}

	for(char i = 'a'; i <= 'z'; i++){
		photos += i;
		res.push_back(photos);
		photos.erase(photos.end() - 1);
	}

	std::sort(res.begin(), res.end());
	for(int i = 0; i < res.size() - 1; i++){
		if(res[i] == res[i + 1]){
			res.erase(res.begin() + i);
			i--;
		}
	}

	std::cout << res.size();
	return 0;
}
