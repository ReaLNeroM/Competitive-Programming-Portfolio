#include <bits/stdc++.h>

class LongLiveZhangzj{
public:
	int donate(std::vector<std::string> speech, std::vector<std::string> words){
		int res = 0;

		for(std::string i : speech){
			for(std::string j : words){
				if(i == j){
					res++;
				}
			}
		}

		return res;
	}
};