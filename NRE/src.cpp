#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e6 + 1e2;
int v[maxn];
std::vector<int> q[maxn];
int seg[maxn];
bool laz[maxn];
int n, queries;

void build(int ind = 0, int cl = 0, int cr = n - 1){
	if(cr == cl){
		if(v[cl]){
			seg[ind] = 1;
		} else {
			seg[ind] = -1;
		}

		return;
	}

	int mid = (cl + cr) / 2;

	build(2 * ind + 1, cl     , mid);
	build(2 * ind + 2, mid + 1, cr );

	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

void update(int ql, int qr, int ind = 0, int cl = 0, int cr = n - 1){
	if(cr < ql or qr < cl){
		return;
	} else if(ql <= cl and cr <= qr){
		seg[ind] = 0;
		laz[ind] = true;
		return;
	}

	int mid = (cl + cr) / 2;

	update(ql, qr, 2 * ind + 1, cl     , mid);
	update(ql, qr, 2 * ind + 2, mid + 1, cr );

	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int query(int ql, int qr, int ind = 0, int cl = 0, int cr = n - 1){
	if(cr < ql or qr < cl or laz[ind]){
		return 0;
	} else if(ql <= cl and cr <= qr){
		return seg[ind];
	}

	int mid = (cl + cr) / 2;

	return query(ql, qr, 2 * ind + 1, cl     , mid) +
		   query(ql, qr, 2 * ind + 2, mid + 1, cr );
}

bool cmp(std::vector<int>& f, std::vector<int>& s){
	if(f[1] != s[1]){
		return f[1] < s[1];
	} else if(f[1] == s[1]){
		return s[0] < f[0];
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> v[i];
	}
	
	int res = 0;
	for(int i = 0; i < n; i++){
		if(v[i]){
			res++;
		}
	}

	std::cin >> queries;

	for(int i = 0; i < queries; i++){
		q[i] = {0, 0};
		std::cin >> q[i][0] >> q[i][1];
		q[i][0]--, q[i][1]--;
	}

	std::sort(q, q + queries, cmp);

	build(0, 0, n - 1);

	for(int i = 0; i < queries; i++){
		int get = -query(q[i][0], q[i][1]);

		if(get < 0){
			res += get;
			update(q[i][0], q[i][1]);
		}
	}

	std::cout << res << '\n';
}