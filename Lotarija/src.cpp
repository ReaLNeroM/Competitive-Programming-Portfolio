#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::map<int, int> dobitni;
	for(int i = 0; i < 7; i++){
		int get;
		std::cin >> get;
		dobitni[get]++;
	}

	std::map<int, int> livce;
	for(int i = 0; i < 30; i++){
		int get;
		std::cin  >> get;
		livce[get]++;
	}

	bool dobitno = true;
	for(auto ite = dobitni.begin(); ite != dobitni.end(); ite++){
		int get = ite->first;

		int query = livce[get];

		if(query < ite->second){
			dobitno = false;
		}
	}

	if(dobitno){
		std::cout << "DA\n";
	} else {
		std::cout << "NE\n";
	}
}