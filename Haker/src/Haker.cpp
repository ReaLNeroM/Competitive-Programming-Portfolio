#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

const int maxpass = 100;
const int minsize = 3;
const int maxsize = 8;
const int mingirls = 2;
const int maxgirls = 5;

int words;
std::vector<std::string> passwords;

std::vector<std::string> res;

void DFS(int pos, std::string curr[], int currsize){
	if(pos == words){
		if(currsize >= mingirls and (res.size() == 0 or res.size() > currsize)){
			res.resize(currsize);
			for(int j = 0; j < currsize; j++){
				res[j] = curr[j];
			}
		}

		return;
	}

	std::string a = "", b = "";
	for(int i = minsize; i < passwords[pos].length(); i++){
		b += passwords[pos][i];
	}

	for(int i = 0; i < minsize; i++){
		a += passwords[pos][i];
	}

	for(int i = 3; i <= std::min((int) passwords[pos].length() - minsize, maxsize - 1); i++){
		bool addeda = true, addedb = true;
		for(int j = 0; j < currsize; j++){
			if(a == curr[j]){
				addeda = false;
				break;
			}
		}
		for(int j = 0; j < currsize; j++){
			if(b == curr[j]){
				addedb = false;
				break;
			}
		}

		if(currsize + addeda + addedb <= maxgirls){
			if(addeda){
				curr[currsize] = a;
			}
			if(addedb){
				curr[currsize + addeda] = b;
			}

			DFS(pos + 1, curr, currsize + addeda + addedb);
		}

		a += passwords[pos][i];
		b.erase(b.begin());
	}
}

int main() {
	std::cin >> words;

	passwords.resize(words);
	for(int i = 0; i < words; i++){
		std::cin >> passwords[i];
	}

	std::string curr[maxgirls];
	for(int i = 0; i < maxgirls; i++){
		curr[i] = "";
	}
	DFS(0, curr, 0);

	std::sort(res.begin(), res.end());
	std::cout << res.size() << std::endl;
	for(int i = 0; i < res.size(); i++){
		std::cout << res[i] << std::endl;;
	}
	return 0;
}
