#include <iostream>
#include <vector>
using namespace std;

int main(){
	int gr;
	cin>>gr;
	int g[2][gr], sg[2][gr];
	for(int i = 0; i < gr; i++){
		cin>>g[0][i]>>g[1][i];
	}

	int leadingnum, follower;

	for(int i = 0; i < gr; i++){
		leadingnum = 99999;
		for(int j = 0; j < gr; j++){
			if(leadingnum > g[1][j]){
				leadingnum = g[1][j];
				follower = j;
			}
		}
		sg[0][i] = g[0][follower];
		sg[1][i] = g[1][follower];
		g[0][follower] = g[1][follower] = 99999;
//		cout<<sg[0][i]<<" AND "<<sg[1][i]<<endl;
	}

	int temp;
	leadingnum = 0;

	for(int i = 0; i < gr; i++){
		temp = 0;
		for(int j = i; j < gr; j++){
			temp += sg[0][j] * sg[1][i];
		}
		if(temp > leadingnum)
			leadingnum = temp;
	}
	cout<<leadingnum;
}
