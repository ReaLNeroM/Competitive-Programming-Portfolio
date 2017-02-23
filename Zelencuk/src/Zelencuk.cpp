#include <iostream>

int main() {
	int y, x;
	std::cin >> y >> x;

	char mat[y][x];
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> mat[i][j];
		}
	}

	char allowed[2];
	int max = 0, curr;
	for(int i = 0; i < y; i++){
		for(int size = i; size < y; size++){
			for(int j = 0; j < x; j++){
				allowed[0] = allowed[1] = '0';
				int curr = 0;
				for(int checkx = j, checky; checkx < x; checkx++){
					for(checky = i; checky <= size; checky++){
						if(allowed[0] == '0'){
							allowed[0] = mat[checky][checkx];
						} else if(mat[checky][checkx] != allowed[0] and allowed[1] == '0'){
							allowed[1] = mat[checky][checkx];
						} else if(mat[checky][checkx] != allowed[0] and mat[checky][checkx] != allowed[1]){
							break;
						}
					}

					if(checky == size + 1){
						curr += size - i + 1;
					} else {
						break;
					}
				}

				max = std::max(max, curr);
			}
		}
	}

	std::cout << max;
	return 0;
}
