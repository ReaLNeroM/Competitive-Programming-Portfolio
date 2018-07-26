#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int type[maxn];
int in[maxn][2];
int change[maxn];
int result[maxn];

bool dfs0(int pos){
	if(type[pos] == 0){
		result[pos] = (dfs0(in[pos][0]) & dfs0(in[pos][1]));
	} else if(type[pos] == 1){
		result[pos] = (dfs0(in[pos][0]) | dfs0(in[pos][1]));
	} else if(type[pos] == 2){
		result[pos] = (dfs0(in[pos][0]) ^ dfs0(in[pos][1]));
	} else if(type[pos] == 3){
		result[pos] = !dfs0(in[pos][0]);
	} else if(type[pos] == 4){
		result[pos] = in[pos][0];
	}

	return result[pos];
}

bool dfs1(int pos){
	if(type[pos] == 0){
		int a_ans = result[in[pos][0]];
		int b_ans = result[in[pos][1]];

		if(a_ans and b_ans){
			change[pos] |= dfs1(in[pos][0]);
			change[pos] |= dfs1(in[pos][1]);
		} else if(a_ans){
			change[pos] |= dfs1(in[pos][1]);
		} else if(b_ans){
			change[pos] |= dfs1(in[pos][0]);
		}
	} else if(type[pos] == 1){
		int a_ans = result[in[pos][0]];
		int b_ans = result[in[pos][1]];

		if(!a_ans and !b_ans){
			change[pos] |= dfs1(in[pos][0]);
			change[pos] |= dfs1(in[pos][1]);
		} else if(a_ans and !b_ans){
			change[pos] |= dfs1(in[pos][0]);
		} else if(!a_ans and b_ans){
			change[pos] |= dfs1(in[pos][1]);
		}
	} else if(type[pos] == 2){
		change[pos] |= dfs1(in[pos][0]);
		change[pos] |= dfs1(in[pos][1]);
	} else if(type[pos] == 3){
		change[pos] |= dfs1(in[pos][0]);
	} else if(type[pos] == 4){
		change[pos] = true;
	}

	return change[pos];
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::string s;
		int val;

		std::cin >> s >> val;
		val--;

		if(s == "AND"){
			type[i] = 0;

			int second_val;
			std::cin >> second_val;
			second_val--;

			in[i][0] = val;
			in[i][1] = second_val;
		} else if(s == "OR"){
			type[i] = 1;

			int second_val;
			std::cin >> second_val;
			second_val--;

			in[i][0] = val;
			in[i][1] = second_val;
		} else if(s == "XOR"){
			type[i] = 2;

			int second_val;
			std::cin >> second_val;
			second_val--;

			in[i][0] = val;
			in[i][1] = second_val;
		} else if(s == "NOT"){
			type[i] = 3;

			in[i][0] = val;
		} else {
			type[i] = 4;

			in[i][0] = val + 1;
		}
	}

	dfs0(0);

	dfs1(0);

	for(int i = 0; i < n; i++){
		if(type[i] == 4){
			std::cout << (result[0] ^ change[i]);
		}
	}
	std::cout << '\n';
}
