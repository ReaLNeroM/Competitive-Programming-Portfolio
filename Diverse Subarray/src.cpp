#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
const ll maxbit = (1 << 17);
const ll INF = 1000000000000000010;

int val[maxn];
int taken[maxn];
std::vector<int> v[maxn];

int seg[8 * maxn];
int laz[8 * maxn];
int lastValue[maxn];
int n, m;

void propagate(int ind){
	if(laz[ind] and 2 * ind + 2 < 8 * maxn){
		laz[2 * ind + 1] = laz[ind];
		laz[2 * ind + 2] = laz[ind];
		seg[2 * ind + 1] += laz[ind];
		seg[2 * ind + 2] += laz[ind];
		laz[ind] = 0;
	}
}

int query(int pos, int ind = 0, int cl = 0, int cr = n - 1){
	if(pos < cl){
		return 0;
	}
	if(cr <= pos){
		return seg[ind];
	}
	propagate(ind);

	int mid = (cl + cr) / 2;

	return std::max(query(pos, 2 * ind + 1, cl, mid),
					query(pos, 2 * ind + 2, mid + 1, cr));
}

void update(int pos, int newValue, int ind = 0, int cl = 0, int cr = n - 1){
	if(cr < pos){
		return;
	}
	if(pos <= cl){
		laz[ind] += newValue - lastValue[pos];
		seg[ind] += laz[ind];
		return;
	}
	
	propagate(ind);

	int mid = (cl + cr) / 2;

	update(pos, newValue, 2 * ind + 1, cl, mid);
	update(pos, newValue, 2 * ind + 2, mid + 1, cr);

	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){

		std::cout << "Case #" << testcase << ": ";
		std::cin >> n >> m;

		for(int i = 0; i < n; i++){
			std::cin >> val[i];
			lastValue[i] = 0;
		}

		for(int i = 0; i < 8 * n; i++){
			seg[i] = laz[i] = 0;
		}

		int res = 0;

		for(int i = 0; i < n; i++){
			int curr = 0;

			v[val[i]].push_back(i);
			if(v[val[i]].size() == m + 1){
				update(v[val[i]][0], -m);
				lastValue[v[val[i]][0]] = -m;
			} else if(v[val[i]].size() > m + 1){
				update(v[val[i]][v[val[i]].size() - m - 1], -1);
				lastValue[v[val[i]][v[val[i]].size() - m - 1]] = -1;
				update(v[val[i]][v[val[i]].size() - m]    , -m);
				lastValue[v[val[i]][v[val[i]].size() - m]] = -m;
			}

			update(i, 1);
			lastValue[i] = 1;

			res = std::max(res, query(i));
		}

		std::cout << res;
		std::cout << '\n';
	}
}
