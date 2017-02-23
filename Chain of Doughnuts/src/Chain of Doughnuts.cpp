#include <iostream>
#include <algorithm>
typedef long long ll;

ll size, chain[20000];

void sift(ll pos){
	ll biggest = chain[pos], follower = pos;

	if(2 * pos + 1 < size and chain[2 * pos + 1] < biggest){
		biggest = chain[2 * pos + 1], follower = 2 * pos + 1;
	}
	if(2 * pos + 2 < size and chain[2 * pos + 2] < biggest){
		biggest = chain[2 * pos + 2], follower = 2 * pos + 2;
	}

	if(follower != pos){
		std::swap(chain[pos], chain[follower]);
		sift(follower);
	}
}

void heap_sort(){
	for(int i = size / 2; i >= 0; i--){
		sift(i);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::ios_base::sync_with_stdio(false);
	ll cases;
	std::cin >> cases;

	ll res[cases];
	for(ll test = 0; test < cases; test++){
		std::cin >> size >> size;

		for(ll i = 0; i < size; i++){
			std::cin >> chain[i];
		}

		heap_sort();

		res[test] = size;
		ll poss = -1, pose = size - 1;
		while(pose > poss){
			res[test]--;
			poss++;
			pose -= chain[0];
			std::swap(chain[0], chain[size - 1]);
			size--;
			sift(0);
		}
	}

	for(ll test = 0; test < cases; test++){
		std::cout << res[test] << std::endl;
	}
	return 0;
}
