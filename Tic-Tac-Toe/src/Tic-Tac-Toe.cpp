#include <iostream>
#include <string>
using namespace std;

int main(){
	int grid[3] [3], turn = 1, x, y;
	memset(grid, -1, 3, 3);
	bool won = false;
	memset
	stoi(turn);
	do{
		cout<<"it\'s ";
		if(turn % 2 == 0){
			cout<<'X';
		} else {
			cout<<'O';
		}
		cout<<" turn."<<endl;
		while(true){
			cin>>x>>y;
			if(grid[x - 1][y - 1] == 0){
				grid[x - 1][y - 1] = turn % 2;
				break;
			} else{
				cout<<"It's taken!"<<endl;
			}

		}
		if(turn == 2){
			turn--;
		} else{
			turn++;
		}

	} while(!won);
}
