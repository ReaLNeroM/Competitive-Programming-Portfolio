#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1e2;

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		int n;
		cin >> n;
		map<int, int> m;

		for(int i = 0; i < n; i++){
			int ind;
			cin >> ind;
			ind--;
			m[i] = ind;
		}

		queue<int> q, qs;

		for(int i = n - 1; i >= 0; i--){
			q.push(i);
			qs.push(0);
		}

		int steps = 0;
		while(!q.empty()){
			int fr = q.front(), frs = qs.front();
			q.pop(), qs.pop();

			if(m.find(fr) == m.end()){
				continue;
			}
			if(m.upper_bound(fr) != m.end() and m[fr] > m.upper_bound(fr)->second){
				q.push(fr);
				qs.push(frs + 1);
				steps = max(steps, frs + 1);
				m.erase(m.upper_bound(fr));
			}
		}

		cout << steps << '\n';
	}
}
