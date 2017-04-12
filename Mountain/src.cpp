#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int INF = 1000000005;
std::map<int, int> m;
int r[maxn];
int compressed = 0;
std::vector<std::vector<int> > queries;
int rails;

int seg[8 * maxn];
int laz[8 * maxn];

int prev = 0;

void propagate(int ind, int cl, int cr){
	if(cl >= cr){
		return;
	}

	if(laz[ind] != -INF){
		seg[2 * ind + 1] += prev;
		seg[2 * ind + 2] += prev;
		laz[2 * ind + 1] += prev;
		laz[2 * ind + 2] += prev;
		
		laz[ind] = -INF;
	}
}

void update(int ql, int qr, int val, int ind = 0, int cl = 0, int cr = compressed - 1){
	propagate(ind, cl, cr);

	if(cr < ql){
		return;
	} else if(qr < cl){
		seg[ind] += prev;
		laz[ind] += prev;
		return;
	} else if(ql <= cl and cr <= qr){
		int curr_prev = prev;

		prev += (r[cr] - r[cl] + 1) * val - (seg[ind] - curr_prev);

		seg[ind] = curr_prev + (r[cr] - r[cl] + 1) * val;

		inc[ind] = val;
		return;
	}

	int mid = (cl + cr) / 2;

	update(ql, qr, val, 2 * ind + 1, cl     , mid);
	update(ql, qr, val, 2 * ind + 2, mid + 1, cr );

	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	laz[ind] = -INF;
}

int query(int height, int ind = 0, int cl = 0, int cr = compressed - 1){

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
			a--;

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

	m[0] = 0;
	m[rails - 1] = 0;
	m[rails] = 0;
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
			update_max(m[queries[i][0]]);
			update_max(m[queries[i][1]]);
		} else {
			std::cout << query(queries[i][0] + 1) << '\n';
		}
	}
}
