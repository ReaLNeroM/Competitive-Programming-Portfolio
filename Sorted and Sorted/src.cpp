#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 4005;
int v[maxn][2];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < 2 * n; i++){
		char c;
		std::cin >> c >> v[i][1];
		v[i][0] = (c == 'W');
	}

	int res = 0;

	for(int i = 0; i < 2 * n; i++){
		for(int j = i + 1; j < 2 * n; j++){
			if(v[i][0] == v[j][0] and v[i][1] > v[j][1]){
				res++;
			}
		}
	}
	
	int highest[] = {0, 0};
	for(int i = 0; i < 2 * n; i++){
		if(highest[v[i][0]] > v[i][1]){
			int find = v[i][1] + 1;

			int pos = i;
			while(pos != 0 and (pos == 2 * n - 1 or (v[pos + 1][0] != v[pos][0] or v[pos + 1][1] != find))){
				std::swap(v[pos], v[pos - 1]);
				// res--;
				pos--;
			}
			i--;
		} else {
			highest[v[i][0]] = std::max(highest[v[i][0]], v[i][1]);
		}

	}

	std::cout << res << '\n';
}
