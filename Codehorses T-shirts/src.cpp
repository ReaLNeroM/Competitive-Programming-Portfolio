#include <bits/stdc++.h>

typedef long long ll;

std::map<std::string, int> ma, mb;
int res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
	std::string str;
	for(int i = 0; i < n; i++){
		std::cin >> str;
		ma[str]++;
	}

	for(int i = 0; i < n; i++){
		std::cin >> str;
		mb[str]++;
	}

	for(auto ite = ma.begin(); ite != ma.end(); ite++){
		res += std::abs(ite->second - mb[ite->first]);
		ma[ite->first] = 0;
		mb[ite->first] = 0;
	}

	for(auto ite = mb.begin(); ite != mb.end(); ite++){
		res += std::abs(ite->second - ma[ite->first]);
		ma[ite->first] = 0;
		mb[ite->first] = 0;
	}

    std::cout << res / 2 << '\n';
}