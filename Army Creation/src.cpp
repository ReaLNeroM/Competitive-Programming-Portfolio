#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int maxseg = 1e7;
int val[maxn];
std::queue<int> q[maxn];
int seg[maxseg];
int l[maxseg];
int r[maxseg];
int location[maxn];
int next = 1;

int update(int pos, int cl, int cr, int qpos, int change){
	if(cl == qpos and qpos == cr){
		int curr = next;
		next++;
		seg[curr] = seg[pos] + change;

		return curr;
	} else if(qpos < cl or cr < qpos){
		return pos;
	}

	int curr = next;
	next++;

	int mid = (cl + cr) / 2;

	if(qpos <= mid){
		l[curr] = update(l[pos], cl, mid, qpos, change);
		r[curr] = r[pos];
		seg[curr] = seg[l[curr]] + seg[r[curr]];
	} else {
		l[curr] = l[pos];
		r[curr] = update(r[pos], mid + 1, cr, qpos, change);
		seg[curr] = seg[l[curr]] + seg[r[curr]];
	}

	return curr;
}

int query(int pos, int cl, int cr, int ql, int qr){
	if(ql <= cl and cr <= qr){
		return seg[pos];
	} else if(cr < ql or qr < cl){
		return 0;
	}

	int mid = (cl + cr) / 2;
	return query(l[pos],      cl, mid, ql, qr) +
		   query(r[pos], mid + 1,  cr, ql, qr);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	location[0] = update(0, 0, n - 1, 0, 1);
	q[val[0]].push(0);
	for(int i = 1; i < n; i++){
		q[val[i]].push(i);

		location[i] = update(location[i - 1], 0, n - 1, i, 1);

		if(q[val[i]].size() == k + 1){
			location[i] = update(location[i], 0, n - 1, q[val[i]].front(), -1);
			q[val[i]].pop();
		}
	}

	int q;
	std::cin >> q;

	int last_answer = 0;
	for(int i = 0; i < q; i++){
		int x, y;
		std::cin >> x >> y;

		x = (x + last_answer) % n;
		y = (y + last_answer) % n;

		if(x > y){
			std::swap(x, y);
		}

		last_answer = query(location[y], 0, n - 1, x, y);
		std::cout << last_answer << '\n';
	}
}