#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 50;
const ll INF = 1000000000000000010;

int y, x;
char mat[maxn][maxn];

string words[] = {
	"ATOMIC",
	"CARPET",
	"CHERRY",
	"FORK",
	"HYDROGEN",
	"MAIL",
	"NEUTRON",
	"NUCLEAR",
	"PHOTO",
	"SMOKE",
	"STINK",
	"TIME"
};

bool isHorizontallyRight(int a, int b, string word){
	for(int i = 0; i < word.size(); i++){
		if(b + i >= x or mat[a][b + i] != word[i]){
			return false;
		}
	}

	return true;
}

bool isVerticallyDown(int a, int b, string word){
	for(int i = 0; i < word.size(); i++){
		if(a + i >= y or mat[a + i][b] != word[i]){
			return false;
		}
	}

	return true;
}

bool isDiagonallyDown(int a, int b, string word){
	for(int i = 0; i < word.size(); i++){
		if(a + i >= y or b + i >= x or mat[a + i][b + i] != word[i]){
			return false;
		}
	}

	return true;
}

bool isDiagonallyUp(int a, int b, string word){
	for(int i = 0; i < word.size(); i++){
		if(a - i < 0 or b + i >= x or mat[a - i][b + i] != word[i]){
			return false;
		}
	}

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> y >> x;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> mat[i][j];
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			for (string word : words){
				if(isHorizontallyRight(i, j, word)){
					std::cout << word << '\n';
					continue;
				}
				std::string reverseWord = word;
				std::reverse(reverseWord.begin(), reverseWord.end());
				if(isHorizontallyRight(i, j, word)){
					std::cout << word << '\n';
				}
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			for (string word : words){
				if(isVerticallyDown(i, j, word)){
					std::cout << word << '\n';
					continue;
				}
				std::string reverseWord = word;
				std::reverse(reverseWord.begin(), reverseWord.end());
				if(isVerticallyDown(i, j, word)){
					std::cout << word << '\n';
				}
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			for (string word : words){
				if(isDiagonallyDown(i, j, word)){
					std::cout << word << '\n';
					continue;
				}
				std::string reverseWord = word;
				std::reverse(reverseWord.begin(), reverseWord.end());
				if(isDiagonallyDown(i, j, word)){
					std::cout << word << '\n';
				}
			}
		}
	}
}