#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 30005;
const int maxseg = 10000000;
const int max_val = 1e9 + 1e2;

int val[maxn];
int location[maxn];
int seg[maxseg];
int l[maxseg];
int r[maxseg];
std::map<int, std::vector<int>> m;
std::map<int, int> ind;
int next = 1;

int update(int pos, int cl, int cr, int qpos, int qchange){
	if(cl == qpos and qpos == cr){
		int curr = next;
		next++;

		seg[curr] = seg[pos] + qchange;

		return curr;
	} else if(qpos < cl or cr < qpos){
		return pos;
	}

	int curr = next;
	next++;

	int mid = (cl + cr) / 2;

	if(qpos <= mid){
		l[curr] = update(l[pos],      cl, mid, qpos, qchange);
		r[curr] = r[pos];
	} else {
		l[curr] = l[pos];
		r[curr] = update(r[pos], mid + 1,  cr, qpos, qchange);
	}

	seg[curr] = seg[l[curr]] + seg[r[curr]];

	return curr;
}

int query(int pos, int cl, int cr, int ql, int qr){
	if(ql <= cl and cr <= qr){
		return seg[pos];
	} else if(cr < ql or qr < cl){
		return 0;
	}

	int mid = (cl + cr) / 2;

	return   query(l[pos],      cl, mid, ql, qr)
		   + query(r[pos], mid + 1,  cr, ql, qr);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];

		m[val[i]].push_back(i);
	}

	seg[0] = l[0] = r[0] = 0;
	int last = 0;
	for(auto ite = m.rbegin(); ite != m.rend(); ite++){
		for(int i = 0; i < ite->second.size(); i++){
			last = update(last, 0, n - 1, ite->second[i], 1);
		}

		ind[ite->first] = last;
	}

	int q;
	std::cin >> q;

	int last_answer = 0;
	for(int i = 0; i < q; i++){
		int a, b, c;
		std::cin >> a >> b >> c;

		a ^= last_answer;
		b ^= last_answer;
		c ^= last_answer;

		a--, b--;

		auto ite = ind.upper_bound(c);

		if(ite != ind.end()){
			last_answer = query(ite->second, 0, n - 1, a, b);
		} else {
			last_answer = 0;
		}

		std::cout << last_answer << '\n';
	}
}