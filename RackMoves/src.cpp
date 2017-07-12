#include <bits/stdc++.h>

typedef long long ll;

class Pool {
	public:
	int need1[15] = {1, 0, 0, 1, 8, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0};
	int need2[15] = {0, 1, 1, 0, 8, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1};

	int rackMoves(std::vector<int> tri){
		int res = 0;
		int change = 0;

		for(int i = 0; i < tri.size(); i++){
			if(tri[i] == 8 and need1[i] != 8){
				change++;
				std::swap(tri[i], tri[4]);
			} else {
				if(1 <= tri[i] and tri[i] <= 7){
					tri[i] = 0;
				} else if(9 <= tri[i] and tri[i] <= 15){
					tri[i] = 1;
				}
			}
		}

		int a = 0;
		for(int i = 0; i < tri.size(); i++){
			if(need1[i] != tri[i]){
				a++;
			}
		}	
		res = a;

		a = 0;
		for(int i = 0; i < tri.size(); i++){
			if(need2[i] != tri[i]){
				a++;
			}
		}
		res = std::min(res, a);

		return res + change;
	}
};