#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int inps;
	cin >> inps;
	string full[inps];
	int length[inps];

	for (int i = 0; i < inps; i++) {
		length[i] = 1;
		cin >> full[i];
		for (int j = 0; j < i; j++) {
			for(int k = 0; k < full[i].length() and k < full[j].length(); k++){
				if(full[i][k] != full[j][k]){
					length[i] = max(length[i], k + 1);
					length[j] = max(length[j], k + 1);
					break;
				}
			}
		}
	}

	for (int i = 0; i < inps; i++) {
		cout << full[i].substr(0, length[i]) << endl;
	}
	return 0;
}
