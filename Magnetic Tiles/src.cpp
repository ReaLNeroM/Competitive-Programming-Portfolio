#include <bits/stdc++.h>

typedef long long ll;

std::string board[] = {"SSSS",
					   "SSSN",
					   "SSNN",
					   "SNSN",
					   "SNNN",
					   "NNNN"};

std::string selected[6];
std::set<std::vector<int>> s;
std::vector<int> selectedind(6);

void dfs(int pos){
	if(pos == 6){
		bool valid = true;

		if(selected[0][0] == selected[3][2] or
			selected[0][1] == selected[5][3] or
			selected[0][2] == selected[1][0] or
			selected[0][3] == selected[4][1] or
			selected[1][1] == selected[5][2] or
			selected[1][2] == selected[2][0] or
			selected[1][3] == selected[4][2] or
			selected[2][1] == selected[5][1] or
			selected[2][2] == selected[3][0] or
			selected[2][3] == selected[4][3] or
			selected[3][1] == selected[5][0] or
			selected[3][3] == selected[4][0]){
			valid = false;
		}

		if(valid and s.find(selectedind) == s.end()){
			s.insert(selectedind);
			
			for(int i = 0; i < 6; i++){
				std::cout << selectedind[i] << ' ';
			}
			std::cout << std::endl;
		}

		return;
	}

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 4; j++){
			selected[pos] = "";
			for(int k = j; k < j + 4; k++){
				selected[pos] += board[i][k % 4];
			}
			selectedind[i]++;
			dfs(pos + 1);
			selectedind[i]--;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);

	dfs(0);
}