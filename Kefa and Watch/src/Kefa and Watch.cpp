#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<iomanip>
using namespace std;

const long long A = 100000000000000LL, N = 228228;
const long long os[2] = {11, 13};
const long long MOD[2] = {1000000007, 1073676287};

std::string a;
long long t[2][2][N * 4], st[2][N], dp[2][N], type, l, r, d, i, j, n, m[2];

long long Get(int k, int l, int r) {
	l--, r--;
	if (!l) return dp[k][r];
	else return ((dp[k][r] - dp[k][l - 1]) % MOD[k] + MOD[k]) % MOD[k];
}

void push(int k, int v, int l, int r) {
	if (!t[k][1][v]) return;
	int mid = (l + r) / 2;
	t[k][0][v * 2] = (t[k][1][v] * Get(k, l, mid)) % MOD[k];
	t[k][0][v * 2 + 1] = (t[k][1][v] * Get(k, mid + 1, r)) % MOD[k];
	t[k][1][v * 2] = t[k][1][v * 2 + 1] = t[k][1][v];
	t[k][1][v] = 0;
}

long long get(int k, int v, int l, int r, int _l, int _r) {
	if (_l > _r) return 0;
	if (l == _l && r == _r) return t[k][0][v];
	push(k, v, l, r);
	int mid = (l + r) / 2;
	return (get(k, v * 2, l, mid, _l, min(mid, _r)) + get(k, v * 2 + 1, mid + 1, r, max(mid + 1, _l), _r)) % MOD[k];
}

void modi(int k, int v, int l, int r, int _l, int _r, long long g) {
	if (_l > _r) return;
	if (l == _l && r == _r) {
		t[k][0][v] = (g * Get(k, l, r)) % MOD[k], t[k][1][v] = g;
		return;
	}
	int mid = (l + r) / 2;
	push(k, v, l, r);
	modi(k, v * 2, l, mid, _l, min(_r, mid), g), modi(k, v * 2 + 1, mid + 1, r, max(mid + 1, _l), _r, g);
	t[k][0][v] = t[k][0][v * 2] + t[k][0][v * 2 + 1];
}

int main() {
	std::cin >> n >> m[0] >> m[1];
	std::cin >> a;
	for (d = 0; d < 2; d++) {
		st[d][0] = dp[d][0] = 1;
		for (i = 1; i < n; i++)
			st[d][i] = st[d][i - 1] * os[d], st[d][i] %= MOD[d], dp[d][i] = dp[d][i - 1] + st[d][i], dp[d][i] %= MOD[d];
		for (i = 0; i < n; i++)
			modi(d, 1, 1, n, i + 1, i + 1, a[i] - '0' + 1);
	}
	m[0] += m[1];
	while (m[0]--) {
		std::cin >> type >> l >> r >> d;
		if (type == 1) {
			for (i = 0; i < 2; i++) {
				modi(i, 1, 1, n, l, r, d + 1);
			}
		} else {
			if (l == r || (((get(0, 1, 1, n, l, r - d) * st[0][d]) % MOD[0] == get(0, 1, 1, n, l + d, r)) && ((get(1, 1, 1, n, l, r - d) * st[1][d]) % MOD[1] == get(1, 1, 1, n, l + d, r)))){
				std::cout << "YES";
			} else {
				std::cout << "NO";
			}
		}
	}
}
