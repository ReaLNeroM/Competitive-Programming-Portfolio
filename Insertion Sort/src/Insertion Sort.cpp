#include <iostream>

void insertionsort(int array[], int size){
	for(int i = 0; i < size; i++){
		int j = i - 1;

		while(j >= 0 and array[j] > array[j + 1]){
			std::swap(array[j], array[j + 1]);
			j--;
		}
	}
}
int main() {
	int n;
	std::cin >> n;

	int array[n];
	for(int i = 0; i < n; i++){
		std::cin >> array[i];
	}

	insertionsort(array, n);

	for(int i = 0; i < n; i++){
		std::cout << array[i] << " ";
	}
	return 0;
}
