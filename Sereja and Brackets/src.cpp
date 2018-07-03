#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;

struct query {
	int end, index;
	int coefficient;
	int query_pos;

	bool operator<(const query& x){
		return end < x.end;
	}
};

int n;
int res[maxn];
int val[maxn];
query q[maxn];
int tree[maxn];

void update(int pos, int change){
	pos++;

	while(pos < maxn){
		tree[pos] += change;
		pos += pos & -pos;
	}
}

int query(int pos){
	pos++;

	int res = 0;

	while(pos > 0){
		res += tree[pos];
		pos -= pos & -pos;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;
	n = s.size();

	std::fill(val, val + n, n + 2);
	std::stack<int> brackets_stack;
	int last_open = -1;
	for(int i = 0; i < n; i++){
		if(s[i] == ')'){
			if(!brackets_stack.empty()){
				val[brackets_stack.top()] = i;
				brackets_stack.pop();
			}
		} else {
			brackets_stack.push(i);
		}
	}

	int queries;
	std::cin >> queries;

	for(int i = 0; i < queries; i++){
		int l, r;
		std::cin >> l >> r;
		l -= 2;
		r--;

		q[2 * i].end = l;
		q[2 * i].index = i;
		q[2 * i].query_pos = r;
		q[2 * i].coefficient = -1;

		q[2 * i + 1].end = r;
		q[2 * i + 1].index = i;
		q[2 * i + 1].query_pos = r;
		q[2 * i + 1].coefficient = 1;
	}

	std::sort(q, q + 2 * queries);

	int curr_added = -1;
	for(int i = 0; i < 2 * queries; i++){
		while(curr_added < q[i].end){
			curr_added++;
			update(val[curr_added], 1);
		}

		res[q[i].index] += q[i].coefficient * query(q[i].query_pos);
	}

	for(int i = 0; i < queries; i++){
		std::cout << 2 * res[i] << '\n';
	}
}
