#include <iostream>
#include <vector>

int n;
std::vector<int> val;

void sift(int pos){
	int biggest = val[pos], follower = pos;

	for(int i = 1; i <= 2; i++){
		if(2 * pos + i < n and val[2 * pos + i] > biggest){
			biggest = val[2 * pos + i], follower = 2 * pos + i;
		}
	}

	if(follower != pos){
		std::swap(val[pos], val[follower]);
		sift(follower);
	}
}
void heap_sort(){
	for(int i = n / 2; i >= 0; i--){
		sift(i);
	}

	while(n > 0){
		std::swap(val[0], val[n - 1]);
		n--;
		sift(0);
	}
}

int main() {
	std::cin >> n;

	val.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	heap_sort();

	for(int i = 0; i < val.size(); i++){
		std::cout << val[i]<< " ";
	}
	return 0;
}
