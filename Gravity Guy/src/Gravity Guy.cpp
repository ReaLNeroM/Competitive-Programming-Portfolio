#include <iostream>

int main() {
	int cases;
	std::cin >> cases;

	static int pos[200000][2];
	int res[cases];

	std::string a, b;
	for(int i = 0; i < cases; i++){
		std::cin >> a >> b;

		pos[a.length() - 1][0] = (a[a.length() - 1] == '#') * 10000000;
		pos[b.length() - 1][1] = (b[b.length() - 1] == '#') * 10000000;

		for(int i = a.length() - 2; i >= 0; i--){
			if(a[i] == '#'){
				pos[i][0] = 10000000;
			} else {
				pos[i][0] = std::min(pos[i + 1][0], pos[i + 1][1] + 1);
			}
			if(b[i] == '#'){
				pos[i][1] = 10000000;
			} else {
				pos[i][1] = std::min(pos[i + 1][1], pos[i + 1][0] + 1);
			}

		}

		res[i] = std::min(pos[0][0], pos[0][1]);
	}

	for(int i = 0; i < cases; i++){
		if(res[i] == 10000000){
			std::cout << "No" << std::endl;
		} else {
			std::cout << "Yes" << std::endl << res[i] << std::endl;
		}
	}
	return 0;
}
