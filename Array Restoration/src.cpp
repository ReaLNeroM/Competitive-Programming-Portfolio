#include <bits/stdc++.h>

const int maxn = 2e5 + 1e2;
int n, q;
int val[maxn];
std::vector<int> s[maxn];
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

void update(int pos, int upd){
	pos++;

	while(pos < maxn){
		tree[pos] += upd;
		pos += pos & -pos;
	}
}

bool validate(){
	for(int i = 0; i < maxn; i++){
		s[i].clear();
		tree[i] = 0;
	}

	for(int i = 0; i < n; i++){
		s[val[i]].push_back(i);
		update(i, 1);
	}
	
	bool valid = true;

	for(int i = q; i >= 1; i--){
		if(s[i].empty()){
			continue;
		}

		for(int ind : s[i]){
			update(ind, -1);
		}

		if(query(s[i][s[i].size() - 1]) - query(s[i][0] - 1) != 0){
			valid = false;
			break;
		}
	}

	return valid and (*std::max_element(val, val + n) == q);
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> q;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	bool canUseValueQ = (std::count(val, val + n, q) == 0);

	for(int i = 0; i < n; i++){
		if(val[i] == 0){
			if(canUseValueQ){
				val[i] = q;
				canUseValueQ = false;
			} else {
				val[i] = 1;
			}
		}
	}

	if(validate()){
		std::cout << "YES\n";

		for(int i = 0; i < n; i++){
			std::cout << val[i] << ' ';
		}
		
		std::cout << '\n';
	} else {
		std::cout << "NO\n";
	}

}
