#include <iostream>

int sticks, sides;
int length[30];
int taken[30];

int dfs(int depth = 0, int last = 0, int sum = 0){
	if(depth == sides){
		for(int i = 0; i < sides; i++){
			if(sum - taken[i] <= taken[i]){
				return 0;
			}
		}

		return 1;
	}
	int res = 0;
	for(int i = last; i <= sticks - sides + depth; i++){
		taken[depth] = length[i];
		res += dfs(depth + 1, i + 1, sum + taken[depth]);
	}

	return res;
}

int main() {
	std::cin >> sticks >> sides;

	for(int i = 0; i < sticks; i++){
		std::cin >> length[i];
	}

	std::cout << dfs();
	return 0;
}
