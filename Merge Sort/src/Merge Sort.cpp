#include <iostream>


void merge(int left[], int leftsize, int right[], int rightsize){
	int res[leftsize + rightsize];

	int rescurr = 0, leftcurr = 0, rightcurr = 0;

	while(leftcurr < leftsize and rightcurr < rightsize){
		if(left[leftcurr] <= right[rightcurr]){
			res[rescurr] = left[leftcurr];
			leftcurr++;
		} else {
			res[rescurr] = right[rightcurr];
			rightcurr++;
		}
		rescurr++;
	}

	while(leftcurr < leftsize){
		res[rescurr] = left[leftcurr];
		leftcurr++;
		rescurr++;
	}
	while(rightcurr < rightsize){
		res[rescurr] = right[rightcurr];
		rightcurr++;
		rescurr++;
	}

	for(int i = 0; i < leftsize; i++){
		left[i] = res[i];
	}
	for(int j = 0; j < rightsize; j++){
		right[j] = res[leftsize + j];
	}
}

void mergesort(int array[], int size){
	if(size == 1){
		return;
	}
	int left = size / 2, right = size - left;

	mergesort(array, left);
	mergesort(array + left, right);

	merge(array, left, array + left, right);
}

int main() {
	int n;
	std::cin >> n;

	int array[n];
	for(int i = 0; i < n; i++){
		std::cin >> array[i];
	}

	mergesort(array, n);

	for(int i = 0; i < n; i++){
		std::cout << array[i] << " ";
	}
	return 0;
}
