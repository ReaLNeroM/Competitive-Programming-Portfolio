#include <iostream>
using namespace std;

int main(){
	int godini;
	cin >> godini;
	int svekipotrebni[10] = {0};

	while(godini > 0){
		if(godini % 10 == 9 or godini % 10 == 6){
			svekipotrebni[6]++;
		} else{
			svekipotrebni[godini % 10] += 2;
		}

		godini /= 10;
	}

	if(svekipotrebni[6] % 2 == 1){
		svekipotrebni[6]++;
	}

	int najgolem = 0;
	for(int i = 0; i < 10; i++){
		if(najgolem < svekipotrebni[i]){
			najgolem = svekipotrebni[i] / 2;
		}
	}

	std::cout << najgolem;
}
