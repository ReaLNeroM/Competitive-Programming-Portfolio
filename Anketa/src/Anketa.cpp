#include <iostream>
using namespace std;

int main(){
	int broj;
	cin>>broj;
	string lista[broj];
	int povtaranja[broj] = {0}, leadingnum = 0, follower;

	for(int i = 0; i < broj; i++){
		cin>>lista[i];
		for(int j = 0; j < i; j++){
			if(lista[j] == lista[i]){
				povtaranja[j]++;
				if(povtaranja[j] > leadingnum){
					leadingnum = povtaranja[j];
					follower = j;
				}
			}
		}
	}

	cout<<lista[follower];
}
