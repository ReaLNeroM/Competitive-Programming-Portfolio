#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;
int l[maxn], r[maxn];
int p[maxn], q[maxn];
std::vector<int> train[maxn];
std::vector<std::vector<int>> recipe[maxn];
int res[maxn];

int tree[maxn];

int query(int pos){
	pos++;

	int res = 0;
	while(pos > 0){
		res += tree[pos];
		pos -= pos & -pos;
	}

	return res;
}

void update(int pos, int upd = 1){
	pos++;

	while(pos < maxn){
		tree[pos] += upd;
		pos += pos & -pos;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, qq;
	std::cin >> n >> m >> qq;

	for(int i = 0; i < m; i++){
		std::cin >> l[i] >> r[i];
		l[i]--, r[i]--;
		train[l[i]].push_back(r[i]);
		update(r[i]);
	}

	for(int i = 0; i < qq; i++){
		std::cin >> p[i] >> q[i];
		p[i]--, q[i]--;
		recipe[p[i]].push_back({q[i], i});
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < recipe[i].size(); j++){
			res[recipe[i][j][1]] = query(recipe[i][j][0]);
		}
		for(int j = 0; j < train[i].size(); j++){
			update(train[i][j], -1);
		}
	}

	for(int i = 0; i < qq; i++){
		std::cout << res[i] << '\n';
	}
}
