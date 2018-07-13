#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;

int n;
int val[maxn];

int __my_gcd(int a, int b){
	if(b == 0){
		return a;
	}

	return __my_gcd(b, a % b);
}

int gcd(int a, int b){
	int res = val[a];
	for(int i = a + 1; i <= b; i++){
		res = __my_gcd(res, val[i]);
	}

	return res;
}

int query(int l, int r, int l2, int r2){
	if(0 <= l and r < n and 0 <= l2 and r2 < n){
		return (gcd(l, r) == gcd(l2, r2));
	}

	return 0;
}

int sub_solve(int pos, int size, int *l, int *r){
	if(size == 1){
		l[pos] = r[pos] = -1;
		return pos;
	}

	for(int i = pos; i < pos + size; i++){
		if(query(pos, i, i, pos + size - 1)){
			int new_a = sub_solve(pos, i - pos - 1, l, r);
			int new_b = sub_solve(i + 1, size - i - 1, l, r);

			l[i] = new_a;
			r[i] = new_b;

			return i;
		}
	}
}

void solve(int size, int *l, int *r){
	sub_solve(0, size, l, r);
}

int main(){
	std::ios::sync_with_stdio(false);

	int max_queries;
	std::cin >> max_queries;

	int tests;
	std::cin >> tests;

	for(int test = 0; test < tests; test++){
		int times;
		std::cin >> n >> times;

		for(int x2 = 0; x2 < times; x2++){
			int l[n];
			int r[n];

			for(int i = 0; i < n; i++){
				l[i] = -1;
				r[i] = -1;
				std::cin >> val[i];
			}

			solve(n, l, r);

			for(int i = 0; i < n; i++){
				std::cout << l[i] << ' ';
			}
			
			for(int i = 0; i < n; i++){
				std::cout << r[i] << ' ';
			}

			std::cout << '\n';
		}
	}
}
