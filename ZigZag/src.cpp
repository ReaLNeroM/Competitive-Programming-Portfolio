#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int words, q;
	std::cin >> words >> q;

	std::multiset<std::pair<std::pair<char, int>, std::string>> s;
	for(int i = 0; i < words; i++){
		std::string str;
		std::cin >> str;
		s.insert({{str[0], 0}, str});
	}

	for(int i = 0; i < q; i++){
		char c;
		std::cin >> c;

		auto ite = s.lower_bound({{c, 0}, ""});
		auto new_element = *ite;
		std::cout << ite->second << '\n';
		s.erase(ite);
		new_element.first.second++;
		s.insert(new_element);
	}
}