#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 100005;
const int maxseg = 8 * maxn;
int val[maxn];
std::vector<std::vector<int>> seg[maxseg];

void build(int pos, int l, int r){
	if(l == r){
		seg[pos].push_back({val[l], 1});
	} else {
		int a = 0, b = 0;
		int mergel = 2 * pos + 1;
		int merger = 2 * pos + 2;

		build(mergel, l, (l + r) / 2);
		build(merger, (l + r) / 2 + 1, r);

		while(a != seg[mergel].size() and b != seg[merger].size()){
			if(seg[mergel][a][0] <= seg[merger][b][0]){
				seg[pos].push_back({seg[mergel][a][0], a + b + 1});
				a++;
			} else {
				seg[pos].push_back({seg[merger][b][0], a + b + 1});
				b++;
			}
		}
		while(a != seg[mergel].size()){
			seg[pos].push_back({seg[mergel][a][0], a + b + 1});
			a++;
		}
		while(b != seg[merger].size()){
			seg[pos].push_back({seg[merger][b][0], a + b + 1});
			b++;
		}
	}
	
}

int query(int pos, int cl, int cr, int ql, int qr, int qval){
	if(ql <= cl and cr <= qr){
		int l = 0, r = seg[pos].size() - 1;

		int best = 0;
		while(l <= r){
			int mid = (l + r) / 2;

			if(seg[pos][mid][0] <= qval){
				best = seg[pos][mid][1];
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		return best;
	} else if(cr < ql or qr < cl){
		return 0;
	}

	int mid = (cl + cr) / 2;

	return   query(2 * pos + 1,      cl, mid, ql, qr, qval)
		   + query(2 * pos + 2, mid + 1,  cr, ql, qr, qval);
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, q;
	scanf("%d %d", &n, &q);

	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
	}

	build(0, 0, n - 1);

	std::sort(val, val + n);

	for(int i = 0; i < q; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		a--, b--;

		int l = 0, r = n - 1;
		int res = 0;

		while(l <= r){
			int mid = (l + r) / 2;

			if(query(0, 0, n - 1, a, b, val[mid]) < c){
				l = mid + 1;
			} else {
				res = mid;
				r = mid - 1;
			}
		}

		printf("%d\n", val[res]);
	}
}