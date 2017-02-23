#include <iostream>
#include <queue>

typedef long long ll;
using namespace std;

static bool used[201][201][201];

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int pos[3] = {0, 0, 0};
	for(int i = 0; i < n; i++){
		char inp;
		cin >> inp;

		if(inp == 'B'){
			pos[0]++;
		} else if(inp == 'G'){
			pos[1]++;
		} else if(inp == 'R'){
			pos[2]++;
		}
	}

	used[pos[0]][pos[1]][pos[2]] = true;
	queue<int> q[3];

	q[0].push(pos[0]);
	q[1].push(pos[1]);
	q[2].push(pos[2]);

	int op[3][3] = { {-1, 2, 1}, {2, -1, 0}, {1, 0, -1}};
	while(!q[0].empty()){
		int g[3];
		for(int i = 0; i < 3; i++){
			g[i] = q[i].front();
			q[i].pop();
		}

		for(int i = 0; i < 3; i++){
			if(g[i] >= 2){
				g[i] -= 1;
				if(!used[g[0]][g[1]][g[2]]){
					used[g[0]][g[1]][g[2]] = true;
					for(int k = 0; k < 3; k++){
						q[k].push(g[k]);
					}
				}
				g[i] += 1;
			}
			for(int j = i + 1; j < 3; j++){
				if(g[i] >= 1 and g[j] >= 1){
					g[i] -= 1, g[j] -= 1;
					g[op[i][j]] += 1;
					if(!used[g[0]][g[1]][g[2]]){
						used[g[0]][g[1]][g[2]] = true;
						for(int k = 0; k < 3; k++){
							q[k].push(g[k]);
						}
					}
					g[op[i][j]] -= 1;
					g[i] += 1, g[j] += 1;
				}
			}
		}
	}

	if(used[1][0][0]){
		cout << 'B';
	}
	if(used[0][1][0]){
		cout << 'G';
	}
	if(used[0][0][1]){
		cout << 'R';
	}
	return 0;
}
