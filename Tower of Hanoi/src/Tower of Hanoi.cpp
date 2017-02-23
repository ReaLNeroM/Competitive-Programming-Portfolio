#include <iostream>
#include <deque>

std::deque<int> s[3];

int cekori = 0;
void tower(int size, int start, int temp, int end){
	if(size <= 0){
		return;
	}

	tower(size - 1, start, end, temp);
	s[end].push_back(s[start].back());
	s[start].pop_back();
	cekori++;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < s[i].size(); j++){
			std::cout << s[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "---------" << std::endl;
	tower(size - 1, temp, start, end);
}
int main() {
	int n;
	std::cin >> n;

	for(int i = 1; i <= n; i++){
		s[0].push_front(i);
	}

	tower(s[0].size(), 0, 1, 2);


	std::cout << cekori << std::endl;
	return 0;
}
