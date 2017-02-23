#include <iostream>
#include <ios>
long long result = 0;

void collect(int left[], int leftsize, int right[], int rightsize, int array[]){
	int lcur = 0, rcur = 0, acur = 0;

	while(lcur < leftsize and rcur < rightsize){
		if(left[lcur] < right[rcur]){
			array[acur] = left[lcur];
			lcur++, acur++;
		} else{
			array[acur] = right[rcur];
			rcur++, acur++;
			result += leftsize - lcur;
		}
	}
	if(lcur < leftsize){
		while(lcur < leftsize){
			array[acur] = left[lcur];
			acur++, lcur++;
		}
	} else if(rcur < rightsize){
		while(rcur < rightsize){
			array[acur] = right[rcur];
			acur++, rcur++;
		}
	}

}

void mergesort(int array[], int size){
	if(size < 2)
		return;

	int left[size / 2], right[size - size / 2];
	for(int i = 0; i < size / 2; i++){
		left[i] = array[i];
	}
	for(int i = size / 2; i < size; i++){
		right[i - size / 2] = array[i];
	}

	mergesort(left, size / 2);
	mergesort(right, size - size / 2);

	collect(left, size / 2, right, size - size / 2, array);

	delete[] left;
	delete[] right;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int num;
	std::cin >> num;

	int array[num];
	for(int i = 0; i < num; i++){
		std::cin >> array[i];
	}

	mergesort(array, num);

	std::cout << result;
}
