#include <iostream>
using namespace std;

int main() {
	int poraki;
	cin>>poraki;
	string prva, vtora;

	for(int i = 0; i < poraki;i++){
		cin>>prva>>vtora;
		int j = 0, k = 0;
		for(;true;k++) {
			if(prva[j] == vtora[k]){
				j++;
			}

			if(j == prva.length()){
				cout<<"DA"<<endl;
				break;
			}
			if(k == vtora.length()){
				cout<<"NE"<<endl;
				break;
			}
		}
	}

	return 0;
}
