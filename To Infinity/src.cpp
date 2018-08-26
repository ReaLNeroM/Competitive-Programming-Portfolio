#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;

	int k;	
	std::cin >> k;

	for(int i = 0; i < s.size(); i++){
		if(s[i] != '1'){
			std::cout << s[i] << '\n';
			break;
		} else if(s[i] == '1' and i == k - 1){
			std::cout << s[i] << '\n';
			break;
		}
	}
}