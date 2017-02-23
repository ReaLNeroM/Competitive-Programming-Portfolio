#include <string>
#include <vector>
using namespace std;

class CupidReloaded {
public:
	string findLoveInAHopelessPlace(int x, int y) {
		bool mat[x + 1][y + 1][x + 1][y + 1];
		for(int i = 0; i <= x; i++){
			for(int j = 0; j <= y; j++){
				for(int k = 0; k <= x; k++){
					for(int l = 0; l <= y; l++){
						mat[i][j][k][l] = false;
					}
				}
			}
		}

		queue<int> q[4];
		for(int i = 0; i < 4; i++){
			if(i == 0 or i == 3){
				q[i].push(1);
			} else {
				q[i].push(0);
			}
		}
		mat[1][0][0][1] = true;

		while(!q[0].empty()){
			int g[4] = {q[0].front(), q[1].front(), q[2].front()
		}

		return "";
	}
};

int main(){
	CupidReloaded x;
	x.findLoveInAHopelessPlace(100, 100);
}
