#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 10005;
int val[maxn];
std::vector<std::vector<int>> v[maxn];
int fen[maxn];
int pos[maxn];
int res[maxn];

int query(int pos){
	pos += 2;
	int res = 0;

	while(pos > 0){
		res += fen[pos];
		pos -= pos & -pos;
	}

	return res;
}

void update(int pos, int val){
	pos += 2;

	while(pos < maxn){
		fen[pos] += val;
		pos += pos & -pos;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, q;
	std::cin >> n >> q;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		pos[val[i]] = i;
	}

	for(int i = 0; i < q; i++){
		int l, r, x;
		std::cin >> l >> r >> x;
		l--, r--, x--;
		v[x].push_back({l, r, x - l, i});
	}

	for(int i = 1; i <= n; i++){
		int loc = pos[i];

		for(int j = 0; j < v[loc].size(); j++){
			int order = 0;
			order += query(v[loc][j][1]) - query(v[loc][j][0] - 1);

			if(order != v[loc][j][2]){
				res[v[loc][j][3]] = false;
			} else {
				res[v[loc][j][3]] = true;
			}
		}

		update(loc, 1);
	}

	for(int i = 0; i < q; i++){
		if(res[i]){
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}