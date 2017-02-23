#include <iostream>
#include <vector>

int n = 1;
int* val = new int[n];

bool isodd(int num) {
	return (num % 2);
}

void sift_down(int pos, int heapsize) {
	int biggest = val[pos], follower = pos;
	for (int i = 1; i <= 2; i++) {
		if (pos * 2 + i < heapsize and ((!isodd(val[2 * pos + i]) and isodd(biggest)) or ((isodd(val[2 * pos + i]) == isodd(biggest)) and val[2 * pos + i] > biggest))) {
			biggest = val[pos * 2 + i], follower = pos * 2 + i;
		}
	}

	std::swap(val[pos], val[follower]);
	if(follower != pos){
		sift_down(follower, heapsize);
	}
}

void heap_sort() {
	int heapsize = n;
	for (int pos = n / 2; pos >= 0; pos--) {
		sift_down(pos, heapsize);
	}

	while (heapsize > 0) {
		heapsize--;
		std::swap(val[0], val[heapsize]);
		sift_down(0, heapsize);
	}
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> val[i];
	}

	heap_sort();

	for (int i = 0; i < n; i++) {
		std::cout << val[i] << " ";
	}
}
