#include <iostream>

int main() {
	int cluster, files, data = 0;
	std::cin >> cluster >> files;

	for(int i = 0, piece; i < files; i++){
		std::cin >> piece;
		if(piece % cluster == 0){
			data += piece;
		} else {
			data += piece - piece % cluster + cluster;
		}
	}

	std::cout << data;
	return 0;
}
