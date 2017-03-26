#include <bits/stdc++.h>
using namespace std;

int res = 0;

void dfs(int pos, int col){
	if(pos == 6){
		res++;
		return;
	}

	dfs(pos + 1, col);
	dfs(pos + 1, col + 1);
}

int main() {
	dfs(0, 0);

	cout << res;
	return 0;
}
