#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 7005;
std::vector<int> jump[2];
int left[2][maxn];
int allow[2][maxn];
int n;

int main(){
	std::cin >> n;

	for(int i = 0; i < 2; i++){
		int size;
		std::cin >> size;
		jump[i].resize(size);
		for(int j = 0; j < size; j++){
			std::cin >> jump[i][j];
		}
	}

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			left[i][j] = jump[i].size();
			allow[i][j] = -1;
		}
	}

	allow[0][0] = allow[1][0] = 1;

	std::queue<int> qsi, qsj;

	for(int i = 0; i < jump[0].size(); i++){
		int next = (n - jump[0][i]) % n;

		if(allow[0][next] == -1){
			allow[0][next] = true;
			qsi.push(0);
			qsj.push(next);
		}
	}
	for(int i = 0; i < jump[1].size(); i++){
		int next = (n - jump[1][i]) % n;

		if(allow[1][next] == -1){
			allow[1][next] = true;
			qsi.push(1);
			qsj.push(next);
		}
	}
	
	while(!qsi.empty()){
		int fri = qsi.front(), frj = qsj.front();
		qsi.pop(), qsj.pop();

		for(int i = 0; i < jump[!fri].size(); i++){
			int next = (frj + n - jump[!fri][i]) % n;

			left[!fri][next]--;
			
			if(left[!fri][next] == 0 and allow[!fri][next] == -1){
				allow[!fri][next] = !allow[fri][frj];
				if(allow[!fri][next] == 0){
					for(int j = 0; j < jump[fri].size(); j++){
						int sec_next = (next + n - jump[fri][j]) % n;
						if(allow[fri][sec_next] == -1){
							allow[fri][sec_next] = true;
							qsi.push(fri), qsj.push(sec_next);
						}
					}
				}
				qsi.push(!fri), qsj.push(next);
			}
		}
	}

	for(int x = 0; x < 2; x++){
		for(int i = 1; i < n; i++){
			bool found = false;

			if(allow[x][i] == 0){
				std::cout << "Lose ";
			} else if(allow[x][i] == -1){
				std::cout << "Loop ";	
			} else {
				std::cout << "Win ";
			}
		}
		std::cout << std::endl;
	}
}
