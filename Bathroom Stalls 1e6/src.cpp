#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		cerr << x << endl;
		
		ll n, k;
		cin >> n >> k;

		set<int> prev, nnext;

		cout << "Case #" << x + 1 << ": ";

		prev.insert(-0);
		prev.insert(-(n + 1));
		nnext.insert(0);
		nnext.insert(n + 1);

		priority_queue<pair<pair<ll, ll>, ll>> pq;
		int nnewp = 0, nnewn = n + 1;

		pq.push({{((nnewp + nnewn) / 2 - nnewp), (nnewn - (nnewp + nnewn) / 2)}, -(nnewp + nnewn) / 2});
		for(int i = 0; i < k; i++){
			int ind = -pq.top().second;
			pq.pop();
			nnewp = -*prev.lower_bound(-ind);
			nnewn = *nnext.lower_bound(ind);

			if(i == k - 1){
				cout << nnewn - (nnewp + nnewn) / 2 - 1 << ' ' << (nnewp + nnewn) / 2 - nnewp - 1 << '\n';
				break;
			}

			pq.push({{((nnewp + ind) / 2 - nnewp), (ind - (nnewp + ind) / 2)}, -(nnewp + ind) / 2});
			pq.push({{((ind + nnewn) / 2 - ind), (nnewn - (ind + nnewn) / 2)}, -(ind + nnewn) / 2});
			prev.insert(-ind);
			nnext.insert(ind);
		}
	}
}
