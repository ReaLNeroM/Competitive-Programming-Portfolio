#include <iostream>
#include <deque>
#include <set>

int main() {
	int n;
	std::cin >> n;

	std::deque<bool> inorout;
	std::set<int> found;
	for(int i = 0, id; i < n; i++){
		char ch;
		std::cin >> ch >> id;
		inorout.push_back((ch == '+'));

		if(found.count(id) == 0){
			if(ch == '-'){
				inorout.push_front(1);
			}
			found.insert(id);
		}
	}

	int curr = 0, max = 0;
	for(int i = 0; i < inorout.size(); i++){
		if(inorout[i]){
			curr++;
			max = std::max(max, curr);
		} else {
			curr--;
		}
	}
	std::cout << max;
	return 0;
}
