#include <iostream>

int main() {
	int knigi, nosenje;
	cin>>knigi>>nosenje;
	int loc[knigi], podredeno[knigi];

	for(int i = 0; i < knigi; i++){
		cin>>loc[i];
	}

	int leadingnum = 0, follower;

	for(int i = 0; i < knigi; i++){
		for(int j = 0; j < knigi; j++){
			if(leadingnum <= loc[j]){
				follower = j;
				leadingnum = loc[j];
			}
		}
		podredeno[i] = loc[follower];
		loc[follower] = 0;
		leadingnum = 0;
	}
	for(int i = 0; i < knigi; i += nosenje){
		leadingnum += podredeno[i] * 2;
	}

	cout<<leadingnum;
	return 0;
}
