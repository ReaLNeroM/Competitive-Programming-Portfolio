#include <iostream>
#include <queue>

int roombenefit[300][11];
int leaks[300];
int rooms, budget, size;
bool visited[11][20][20];

int getroombenefit(int room, int roombitset){
    int leaksfixed = 0;

    for(int i = 0, bit = 1; i < leaks[room]; i++, bit *= 2){
        if((bit & roombitset) != 0){
            leaksfixed++;
        }
    }

    int dry = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
        	bool flooded = false;
        	for(int k = 0, bit = 1; k < leaks[room]; k++, bit *= 2){
        		if((bit & roombitset) == 0 and visited[k][i][j]){
        			flooded = true;
        			break;
        		}
        	}
        	if(!flooded){
        		dry++;
        	}
        }
    }

    roombenefit[room][leaksfixed] = std::max(roombenefit[room][leaksfixed], dry);
    return dry;
}

int bestfix[301][3001];
int bestfixes(int room, int budgetleft){
    if(bestfix[room][budgetleft] == -1){
        bestfix[room][budgetleft] = 0;
        if(room != rooms){
            for(int i = 0; i <= leaks[room] and i <= budgetleft; i++){
                bestfix[room][budgetleft] = std::max(bestfix[room][budgetleft], roombenefit[room][i] + bestfixes(room + 1, budgetleft - i));
            }
        }
    }

    return bestfix[room][budgetleft];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> rooms >> budget >> size;

	char mat[20][20];
    for(int i = 0; i < rooms; i++){
        leaks[i] = 0;
        int leakpos[10][2];
        for(int j = 0; j <= 10; j++){
            leakpos[j][0] = leakpos[j][1] = -1;
            roombenefit[i][j] = 0;
        }

        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                std::cin >> mat[j][k];
                for(int l = 0; l <= 10; l++){
                	visited[l][j][k] = false;
                }
                if(mat[j][k] == 'L'){
                    leakpos[leaks[i]][0] = j;
                    leakpos[leaks[i]][1] = k;
                    leaks[i]++;
                }
            }
        }

        for(int j = 0; j < leaks[i]; j++){
        	std::queue<int> qy, qx;

        	qy.push(leakpos[j][0]);
        	qx.push(leakpos[j][1]);
			visited[j][qy.front()][qx.front()] = true;

            const int adderx[] = {1, -1, 0, 0};
            const int addery[] = {0, 0, 1, -1};

            while(!qy.empty()){
                for(int i = 0; i < 4; i++){
                    int copyy = qy.front() + addery[i];
                    int copyx = qx.front() + adderx[i];

                    if(copyy >= 0 and copyy < size and copyx >= 0 and copyx < size and mat[copyy][copyx] <= mat[qy.front()][qx.front()] and !visited[j][copyy][copyx]){
                        qy.push(copyy);
                        qx.push(copyx);
						visited[j][copyy][copyx] = true;
                    }
                }

                qy.pop(), qx.pop();
            }
        }

        for(int j = (1 << leaks[i]) - 1; j >= 0; j--){
            getroombenefit(i, j);
        }
    }

    for(int i = 0; i <= rooms; i++){
        for(int j = 0; j <= budget; j++){
            bestfix[i][j] = -1;
        }
    }

    std::cout << bestfixes(0, budget) << std::endl;
    return 0;
}
