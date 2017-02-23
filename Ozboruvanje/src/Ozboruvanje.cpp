//============================================================================
// Name        : Ozboruvanje.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

struct muab{
	int x, y;
};

int main() {
	int clenovi, muabeti;
	std::cin>>clenovi>>muabeti;
	bool zbso[clenovi][clenovi];
	memset(zbso, 0, clenovi * clenovi);
	muab m[muabeti];
	for(int i = 0; i < clenovi; i++){
		zbso[i][i] = true;
	}
	for(int i = 0; i < muabeti; i++){
		std::cin>>m[i].x>>m[i].y;
		m[i].x--, m[i].y--;
	}

	for(int i = 0; i < muabeti; i++){
		for(int j = 0; j < clenovi; j++){
			if(zbso[m[i].x][j] or zbso[m[i].y][j]){
				zbso[m[i].y][j] = zbso[m[i].x][j] = true;
			}
		}
	}

	int max = 0;

	for(int i = 0, curr = 0; i < clenovi; i++, curr = 0){
		for(int j = 0; j < clenovi; j++){
			if(zbso[i][j]){
				curr++;
			}
		}

		max = std::max(max, curr);
	}

	std::cout<<max - 1;
	return 0;
}
