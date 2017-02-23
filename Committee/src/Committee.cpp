/*
	int people, longest = 0;
	cin >> people;
	vector<int> visocina;

	for(int i = 0, copier; i < people; i++){
		cin>>copier;
		visocina.push_back(copier);
		if(visocina.size() < 2){

		}

	}
	cout<<longest;
	return 0;
}
*/

#include <iostream>
using namespace std;

int main() {
	int people;
	cin >> people;
	people += 2;
	int visocina[people], longest = 0;
	visocina[0] = visocina[people - 1] = -1;

	cin >> visocina[1] >> visocina[2];
	for (int i = 3, happy = 0; i < people - 1; i++) {
		cin>>visocina[i];

		if((visocina[i - 2] > visocina[i - 1] and visocina[i] > visocina[i - 1]) or
				(visocina[i - 2] < visocina[i - 1] and visocina[i] < visocina[i - 1])){
			happy++;
		} else{
			happy = 0;
		}

		if(happy > longest){
			longest = happy;
		}
	}

	cout<<longest;
	return 0;
}
