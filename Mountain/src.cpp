#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int seg[8 * maxn];
int segcl[8 * maxn];
int segcr[8 * maxn];
int laz[8 * maxn];
int inc[8 * maxn];
bool is_update[8 * maxn];

std::map<int, int> m;
int r[maxn];
int compressed = 0;
std::vector<std::vector<int> > queries;
int rails;

void propagate(int ind, int cl, int cr){
	if(cl >= cr){
		return;
	}

	int mid = (cl + cr) / 2;

	laz[2 * ind + 1] += laz[ind];
	laz[2 * ind + 2] += laz[ind];
	seg[2 * ind + 1] += laz[ind];
	seg[2 * ind + 2] += laz[ind];
	segcl[2 * ind + 1] += laz[ind];
	segcl[2 * ind + 2] += laz[ind];
	segcr[2 * ind + 1] += laz[ind];
	segcr[2 * ind + 2] += laz[ind];

	if(is_update[ind]){
		segcl[2 * ind + 1] = segcl[ind];
		segcr[2 * ind + 1] = segcl[2 * ind + 1] + (r[mid] - r[cl]) * inc[ind];

		inc[2 * ind + 1] = inc[ind];
		seg[2 * ind + 1] = std::max(segcl[2 * ind + 1], segcr[2 * ind + 1]);
		is_update[2 * ind + 1] = true;

		segcl[2 * ind + 2] = segcl[ind] + (r[mid + 1] - r[cl]) * inc[ind];
		segcr[2 * ind + 2] = segcl[2 * ind + 2] + (r[cr] - r[mid + 1]) * inc[ind];

		inc[2 * ind + 1] = inc[ind];
		seg[2 * ind + 2] = std::max(segcl[2 * ind + 2], segcr[2 * ind + 2]);
		is_update[2 * ind + 2] = true;

		is_update[ind] = false;
	}

	laz[ind] = 0;
}

void update(int ql, int qr, int c, int ind = 0, int cl = 0, int cr = compressed - 1){
	propagate(ind);

	if(cr < ql){
		return;
	} else if(qr < cl){

	} else if(ql <= cl and cr <= qr){

	}

	int mid = (cl + cr) / 2;

	update(ql, qr, c, 2 * ind + 1, cl     , mid);
	update(ql, qr, c, 2 * ind + 2, mid + 1, cr );

	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
	segcl[ind] = segcl[2 * ind + 1];
	segcr[ind] = segcr[2 * ind + 2];
}

int query(int height){
	
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> rails;

	char c;
	while(std::cin >> c, c != 'E'){
		std::vector<int> v;
		if(c == 'I'){
			int a, b, d;
			std::cin >> a >> b >> d;
			a--, b--;

			v.push_back(a);
			v.push_back(b);
			v.push_back(d);
			m[a] = 0, m[b] = 0;
		} else if(c == 'Q'){
			int h;
			std::cin >> h;
			v.push_back(h);
		}

		queries.push_back(v);
	}

	auto ite = m.begin();
	while(ite != m.end()){
		ite->second = compressed;
		r[ite->second] = ite->first;
		compressed++;
		ite++;
	}

	for(int i = 0; i < queries.size(); i++){
		if(queries[i].size() == 3){
			update(m[queries[i][0]], m[queries[i][1]], queries[i][2]);
		} else {
			std::cout << query(queries[i][0] + 1) << '\n';
		}
	}
}
