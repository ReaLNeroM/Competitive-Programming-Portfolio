#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int seg[maxn];
int ffind[maxn];
std::map<int, int> m;

void build(int cl, int cr, int ind = 0){
	if(cl == cr){
		seg[ind] = val[cl];
		ffind[ind] = cl;
		return;
	}

	int mid = (cl + cr) / 2;

	build(cl, mid, 2 * ind + 1);
	build(mid + 1, cr, 2 * ind + 2);

	seg[ind] = std::min(seg[2 * ind + 1], seg[2 * ind + 2]);
	if(seg[2 * ind + 1] == seg[ind]){
		ffind[ind] = ffind[2 * ind + 1];
	} else {
		ffind[ind] = ffind[2 * ind + 2];
	}
}

void update(int qpos, int cl, int cr, int ind = 0){
	if(qpos < cl or cr < qpos){
		return;
	} else if(qpos == cl and qpos == cr){
		seg[ind] = 1e9;
		ffind[ind] = cl;
		return;
	}

	int mid = (cl + cr) / 2;

	update(qpos, cl, mid, 2 * ind + 1);
	update(qpos, mid + 1, cr, 2 * ind + 2);

	seg[ind] = std::min(seg[2 * ind + 1], seg[2 * ind + 2]);
	if(seg[2 * ind + 1] == seg[ind]){
		ffind[ind] = ffind[2 * ind + 1];
	} else {
		ffind[ind] = ffind[2 * ind + 2];
	}
}

std::pair<int, int> query(int ql, int qr, int cl, int cr, int ind = 0){
	if(cr < ql or qr < cl){
		return {1e9, -1};
	} else if(ql <= cl and cr <= qr){
		return {seg[ind], ffind[ind]};
	}

	int mid = (cl + cr) / 2;

	auto get = query(ql, qr, cl, mid, 2 * ind + 1);
	auto sec = query(ql, qr, mid + 1, cr, 2 * ind + 2);

	int min = std::min(get.first, sec.first);

	if(get.first == min){
		return {min, get.second};
	} else {
		return {min, sec.second};
	}
}

int fen[maxn];

void updatef(int ind, int change){
	ind += 2;
	while(ind < maxn){
		fen[ind] += change;
		ind += ind & -ind;
	}
}

int queryf(int ind){
	int res = 0;
	while(ind > 0){
		res += fen[ind];
		ind -= ind & -ind;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		m[val[i]] = 1;
	}

	int curr = 1;
	for(auto ite = m.begin(); ite != m.end(); ite++){
		ite->second = curr;
		curr++;
	}

	std::vector<int> v;
	for(int i = 0; i < n; i++){
		val[i] = m[val[i]];
		v.push_back(val[i]);
	}

	std::sort(v.begin(), v.end());
	build(0, n - 1, 0);

	ll sum = 0;

	int pos = 0;

	for(int i = 0; i < n; i++){
		//find v[i]
		auto get = query(pos, n - 1, 0, n - 1, 0);
		if(get.first == v[i]){
			// sum += get.second - pos;
			// sum -= (queryf(get.second) - queryf(pos - 1));
		} else {
			get = query(0, pos - 1, 0, n - 1, 0);
			// sum += n - pos;
			// sum += get.second;
			// sum -= (queryf(n) - queryf(pos - 1));
			// sum -= (queryf(get.second));
		}

		// std::cout << get.first << ' ' << get.second << std::endl;
		update(get.second, 0, n - 1, 0);
		pos = get.second;
		// updatef(get.second, -1);
	}
}
