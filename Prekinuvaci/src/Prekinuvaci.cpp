#include <iostream>
#include <queue>

typedef long long ll;


int main() {
	int rooms;
	std::cin >> rooms;

	int switchin[rooms];
	static int res[16][1 << 17];
	for(int i = 0; i < rooms; i++){
		std::cin >> switchin[i];
		switchin[i]--;

		for(int j = 0; j < (1 << rooms); j++){
			res[i][j] = -1;
		}
	}

	std::queue<int> pos, bitset;
	pos.push(0);
	bitset.push(1);
	res[0][1] = 0;

	while(!pos.empty()){
		for(int i = 0; i < rooms; i++){
			if((bitset.front() & (1 << i)) and res[i][bitset.front()] == -1){
				res[i][bitset.front()] = res[pos.front()][bitset.front()] + 1;
				pos.push(i);
				bitset.push(bitset.front());
			}
		}

		if(res[pos.front()][bitset.front() ^ (1 << switchin[pos.front()])] == -1){
			res[pos.front()][bitset.front() ^ (1 << switchin[pos.front()])] = res[pos.front()][bitset.front()];
			pos.push(pos.front());
			bitset.push(bitset.front() ^ (1 << switchin[pos.front()]));
		}

		pos.pop();
		bitset.pop();
	}

	if(res[rooms - 1][1 << (rooms - 1)] == -1){
		std::cout << "NE";
	} else {
		std::cout << res[rooms - 1][1 << (rooms - 1)];
	}
	return 0;
}
