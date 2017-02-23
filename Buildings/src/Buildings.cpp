#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

int size;
static int t[200005];
static int c[200005];

void build(){
	for(int i = size - 1; i > 0; i--){
		if(t[2 * i] > t[2 * i + 1]){
			t[i] = t[2 * i];
			c[i] = c[2 * i];
		} else if(t[2 * i] < t[2 * i + 1]){
			t[i] = t[2 * i + 1];
			c[i] = c[2 * i + 1];
		} else {
			t[i] = t[2 * i];
			c[i] = c[2 * i] + c[2 * i + 1];
		}
	}
}

int query(int l, int r, int val){
	int res = 0, max = val;
	for(l += size, r += size; l <= r; l /= 2, r /= 2){
		if(l % 2 == 1){
			if(t[l] > max){
				max = t[l];
				res = c[l];
			} else if(t[l] == max){
				res += c[l];
			}
			l++;
		}
		if(r % 2 == 0){
			if(t[r] > max){
				max = t[r];
				res = c[r];
			} else if(t[r] == max){
				res += c[r];
			}
			r--;
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);

	int cases;
	cin >> cases;
	for(int test = 0; test < cases; test++){
		int n, l;
		cin >> n >> l;

		int p[n], h[n];
		for(int i = 0; i < n; i++){
			cin >> p[i] >> h[i];
		}
		reverse(p, p + n);
		reverse(h, h + n);

		size = n;
		map<int, int> m;

		int best[n + 1], shield[n + 1];
		for(int i = n - 1; i >= 0; i--){
			p[i] = p[0] - p[i];

			m[p[i]] = i;

			t[size + i] = h[i];
			c[size + i] = 1;

			best[i] = shield[i] = 0;
		}

		build();

		best[n] = shield[n] = 0;
		best[n - 1] = shield[n - 1] = 0;
		for(int i = n - 2; i >= 0; i--){
			best[i] = best[i + 1];
			shield[i] = shield[i + 1];

			map<int, int>::iterator ite = m.lower_bound(p[i] + l);
			int lr;
			if(ite == m.end()){
				lr = n - 1;
			} else {
				lr = ite->second;
			}

			if(p[lr] > p[i] + l){
				lr--;
			}
			int coll = (lr - i + 1);
			int shields = 1;
			coll += best[lr + 1];
			shields += shield[lr + 1];

			if(query(i, lr, h[i] + 1) == 0 and query(i, lr, h[i]) >= 2){
				if(coll > best[i] or (coll == best[i] and shields > shield[i])){
					best[i] = coll;
					shield[i] = shields;
				}
			}
		}

		cout << best[0] << ' ' << shield[0] << endl;
	}
	return 0;
}
