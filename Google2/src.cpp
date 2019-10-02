#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 10;
const ll INF = 1000000000000000010;

std::vector<std::vector<int>> v[11];
int sizes[] = {
	117042,
	 30802,
	  7702,
	  2752,
	   552,
	   460,
	   100,
	    72,
	    27,
	     5
};
std::string names[] = {
	"Rainbow",
	"Apartment Building",
	"Hotel Sign",
	"Bonsai",
	"Soccer Ball",
	"Brick",
	"Check Book",
	"Maple Leaf",
	"Short Screw",
	"Ant",
};

int main(){
	std::ios::sync_with_stdio(false);

	int curr = 6;
	std::map<std::string, int> m;
	while (curr <= 117042){
		for(int i = 0; i < 10; i++){
			if(sizes[i] < curr){
				m[names[i]]++;
				curr += sizes[i] / 5;
				break;
			}
		}
	}

	for(int i = 9; i >= 0; i--){
		std::cout << names[i] << ' ' << m[names[i]] << ' ' << (char) ('A' - 1 + m[names[i]]) << '\n';
	}

	std::cout << curr << '\n';
}