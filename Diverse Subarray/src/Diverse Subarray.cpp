#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;

int val[maxn];
std::vector<int> v[maxn];

int seg[16 * maxn];
int laz[16 * maxn];
int lastValue[maxn];
int n, m;

void propagate(int ind){
	if(laz[ind] and 2 * ind + 2 < 16 * maxn){
		laz[2 * ind + 1] += laz[ind];
		laz[2 * ind + 2] += laz[ind];
		seg[2 * ind + 1] += laz[ind];
		seg[2 * ind + 2] += laz[ind];
		laz[ind] = 0;
	}
}

void update(int pos, int newValue, int ind = 0, int cl = 0, int cr = n - 1){
	if(cr <= pos){
		seg[ind] += newValue - lastValue[pos];
		laz[ind] += newValue - lastValue[pos];
		return;
	}
	if(pos < cl){
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
		std::cin >> n >> m;

		for(int i = 0; i < n; i++){
			std::cin >> val[i];
			lastValue[i] = 0;
		}

		memset(seg, 0, sizeof(seg));
		memset(laz, 0, sizeof(laz));

		int res = 0;

		for(int i = 0; i < n; i++){
			v[val[i]].push_back(i);

			if(v[val[i]].size() == m + 1){
				update   (v[val[i]][0] , -m);
				lastValue[v[val[i]][0]] = -m;
			} else if(v[val[i]].size() > m + 1){
				update   (v[val[i]][(int) v[val[i]].size() - m - 2] , -1);
				lastValue[v[val[i]][(int) v[val[i]].size() - m - 2]] = -1;
				update   (v[val[i]][(int) v[val[i]].size() - m - 1] , -m);
				lastValue[v[val[i]][(int) v[val[i]].size() - m - 1]] = -m;
			}

			update(i, 1);
			lastValue[i] = 1;

			res = std::max(res, seg[0]);
		}

		for(int i = 0; i < n; i++){
			v[val[i]].clear();
		}

		std::cout << "Case #" << testcase << ": ";
		std::cout << res;
		std::cout << '\n';
	}
}
