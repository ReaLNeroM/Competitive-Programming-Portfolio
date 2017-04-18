#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

class MakePalindrome {
public:
	std::vector<std::string> constructMinimal(std::string card){
		int available[26];

		std::fill(available, available + 26, 0);

		for(int i = 0; i < card.size(); i++){
			available[card[i] - 'a']++;
		}

		std::string start = "";
		std::string end = "";

		for(int i = 0; i < 26; i++){
			if(available[i] >= 2){
				for(int j = 1; j < available[i]; j += 2){
					start += 'a' + i;
				}

				for(int j = 1; j < available[i]; j += 2){
					end += 'a' + i;
				}
				available[i] %= 2;
			}
		}

		std::vector<std::string> result;
		std::reverse(end.begin(), end.end());
		
		bool put = false;
		for(int i = 0; i < 26; i++){
			if(available[i] % 2 == 1 and !put){
				start += 'a' + i;
				available[i] = 0;
				put = true;
			} else if(available[i] % 2 == 1){
				std::string make = "a";
				make[0] += i;
				result.push_back(make);
			}
		}
		result.push_back(start + end);

		return result;
	}
};