#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

struct cmp {
	string str;
	int prev, next;

	bool operator<(const cmp &x) const {
		return str < x.str;
	}
};

bool cmpf(cmp x, string y) {
	return x.str < y;
}

int main() {
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;

	vector<cmp> v;
	cmp h;
	for (int i = 0; i < s.length(); i++) {
		h.str = "";
		h.prev = i;
		for (int j = i; j < s.length(); j++) {
			h.str += s[j];
			h.next = j;
			v.push_back(h);
		}
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		h.str = "";
		h.prev = i;
		for (int j = i; j >= 0; j--) {
			h.str += s[j];
			h.next = j;
			v.push_back(h);
		}
	}
	sort(v.begin(), v.end());

	int dp[t.length() + 1], pi[t.length() + 1], ni[t.length() + 1];
	dp[t.length()] = 0;
	pi[t.length()] = 0;
	ni[t.length()] = 0;

	string c;
	for (int i = t.length() - 1; i >= 0; i--) {
		c = "";
		dp[i] = t.length() + 1;
		for (int j = i; j < t.length(); j++) {
			c += t[j];

			vector<cmp>::iterator ite = lower_bound(v.begin(), v.end(), c, cmpf);
			if (ite != v.end() and ite->str == c and dp[i] > dp[j + 1] + 1){
				dp[i] = dp[j + 1] + 1;
				pi[i] = ite->prev;
				ni[i] = ite->next;
			}
		}
	}

	if (dp[0] <= t.length()) {
		cout << dp[0] << endl;
		int pos = 0;
		for (int i = 0; i < dp[0]; i++) {
			cout << pi[pos] + 1 << ' ' << ni[pos] + 1 << '\n';
			int size = pi[pos] - ni[pos];
			if (size < 0) {
				size *= -1;
			}
			size++;

			pos += size;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
