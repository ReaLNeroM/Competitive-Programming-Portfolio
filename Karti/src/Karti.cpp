#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string line;
	cin>>line;
	int n, e, w, s, left, right, transfer, j = 0;

	for(int i = 1; i < line.length(); i++){
		left = 0;
		do{
			if(isdigit(line[i])){
				left = i;
			} else{
				right = i - 1;
			}
		} while(left != 0);
		switch(line[left - 1]){
		1				case 'n':
							n = transfer;
							break;
						case 'e':
							e = transfer;
							break;
						case 'w':
							w += transfer;
							break;
						case 's':
							s+= transfer;
							break;
		}
	}
	return 0;
}
