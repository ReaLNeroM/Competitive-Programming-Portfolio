#include <iostream>
using namespace std;

int main() {
	int fin = 0, copier;
	string nums, tr;
	cin >> nums >> tr;

	for (int i = 0; i < 4; i++) {
		if (nums[i] > tr[i])
			copier = nums[i] - tr[i];
		else
			copier = tr[i] - nums[i];

		if(copier > 5){
			fin += 10 - copier;
		} else{
			fin += copier;
		}
	}

	cout << fin;
	return 0;
}
