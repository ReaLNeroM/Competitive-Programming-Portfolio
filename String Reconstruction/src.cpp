#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e6 + 1e2;
std::vector<int> v[maxn];
std::string str[maxn];
char res[maxn];
int size = 0;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> str[i];

		int app;
		std::cin >> app;

		for(int j = 0; j < app; j++){
			int ind;
			std::cin >> ind;
			ind--;
			v[ind].push_back(i);
			size = std::max(size, ind + (int) str[i].size());
		}
	}

	int curr_s = -1;
	int curr_pos = 0;
	for(int i = 0; i < size; i++){
		if(curr_s != -1 and curr_pos == str[curr_s].size()){
			curr_s = -1;
			curr_pos = 0;
		}

		for(int j = 0; j < v[i].size(); j++){
			if(curr_s == -1 or ((int) str[curr_s].size() - curr_pos < (int) str[v[i][j]].size())){
				curr_s = v[i][j];
				curr_pos = 0;
			}
		}

		if(curr_s == -1){
			res[i] = 'a';
		} else {
			res[i] = str[curr_s][curr_pos];
			curr_pos++;
		}
		std::cout << res[i];
	}

	std::cout << std::endl;
}