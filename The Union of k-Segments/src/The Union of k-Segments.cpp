#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	std::pair<int, bool> m[2 * n];

	for(int i = 0, f, s; i < n; i++){
		cin >> f >> s;

		m[i] = make_pair(f, 0);
		m[n + i] = make_pair(s, 1);
	}

	sort(m, m + 2 * n);

	std::vector<int> res[2];
	int used = 0, last = -1;
	for(int i = 0; i < 2 * n; i++){
		if(m[i].second){
			used--;
		} else {
			used++;
		}
		if(used >= k and last == -1){
			res[0].push_back(m[i].first);
			last = 0;
		} else if(used == k - 1 and m[i].second){
			res[1].push_back(m[i].first);
			last = -1;
		}
	}


	int apos = 0, bpos = 0;
	while(apos < res[0].size() and bpos < res[1].size()){
		if(res[0][apos] < res[1][bpos]){
			apos++;
		} else if(res[0][apos] > res[1][bpos]){
			bpos++;
		} else if(apos != bpos){
			res[0].erase(res[0].begin() + apos);
			res[1].erase(res[1].begin() + bpos);
		} else {
			apos++, bpos++;
		}
	}
	cout << res[0].size() << endl;
	for(int i = 0; i < res[0].size(); i++){
		cout << res[0][i] << ' ' << res[1][i] << '\n';
	}
	return 0;
}
