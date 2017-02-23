#include <iostream>
#include <list>
#include <queue>
typedef long long ll;

int main() {
	std::list<char> l;

	std::string str;
	std::cin >> str;

	for(int i = 0; i < str.size(); i++){
		l.push_back(str[i]);
	}

	int operations;
	std::cin >> operations;
	std::list<char>::iterator ite = l.begin();
	for(int i = 0; i < operations; i++){
		char q;
		std::cin >> q;

		if(q == 'L'){
			if(ite != l.begin()){
				ite--;
			}
		} else if(q == 'R'){
			if(ite != --(l.end())){
				ite++;
			}
		} else if(q == 'D'){
			ite = l.erase(ite);
		} else if(q == 'A'){
			char val;
			std::cin >> val;
			ite++;
			ite = l.insert(ite, val);
			ite--;
		}
	}

	for(std::list<char>::iterator i = l.begin(); i != l.end(); i++){
		std::cout << *i;
	}
	return 0;
}
