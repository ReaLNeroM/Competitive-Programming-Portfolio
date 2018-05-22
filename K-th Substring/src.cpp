#include <bits/stdc++.h>

typedef long long ll;

bool cmp (std::string a, std::string b){
	for(int i = 0; i < std::min(a.size(), b.size()); i++){
		if(a[i] < b[i]){
			return true;
		} else if(a[i] > b[i]){
			return false;
		}
	}

	if(a.size() <= b.size()){
		return true;
	} else {
		return false;
	}
}
int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	int k;

	std::cin >> s >> k;

	std::vector<std::string> v;
	for(int i = 1; i <= 10; i++){
		for(int j = 0; j + i <= s.size(); j++){
			v.push_back(s.substr(j, i));
		}
	}

	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	std::sort(v.begin(), v.end());

	std::cout << v[k - 1];
}