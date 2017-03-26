#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
int sum[maxn];
pair<int, int> val[maxn];

int main(){
	int n, d;
	cin >> n >> d;

	set<int> s;
	for(int i = 0; i < n; i++){
		s.insert(i);
	}
	for(int i = 0; i < n; i++){
		cin >> val[i].first;
		sum[i] = 10000;
		val[i].second = i;
	}
	sort(val, val + n);

	for(int i = 0; i < n; i++){
		auto ite = s.lower_bound(val[i].second);
		while(ite != s.end() and *ite < val[i].second + d){
			sum[*ite] = val[i].first;
			auto site = ite;
			ite++;
			s.erase(site);
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		res += sum[i];
	}

	cout << res << endl;
}