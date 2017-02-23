#include <iostream>
#include <algorithm>

typedef long long ll;

int n, e, c;
int pos[15];
int fleft[15];
int chairs[100];
int next[11][11][1 << 15];
int dp[11][11][1 << 15];

int bad(int index) {
	if (index > 0 and index < n - 1) {
		if (chairs[index - 1] > chairs[index] and chairs[index + 1] > chairs[index]) {
			return true;
		} else if (chairs[index - 1] < chairs[index] and chairs[index + 1] < chairs[index]) {
			return true;
		}
	}

	return false;
}
int find(int prprev, int prev, int bitset) {
	if (dp[prprev][prev][bitset] == -1) {
		int used = 0;
		for (int i = 1; i <= bitset; i *= 2) {
			if (bitset & i) {
				used++;
			}
		}

		if (used > 1) {
			chairs[pos[used - 2]] = prprev;
		}
		chairs[pos[used - 1]] = prev;

		int res = n;
		if (used == e) {
			res = 0;
			if(pos[used - 1] < n - 1){
				res += bad(pos[used - 1]);
				if(pos[used] < n - 2){
					res += bad(pos[used - 1] + 1);
				}
			}
		} else {
			for (int i = 0; i < c; i++) {
				if (((1 << i) & bitset) == 0) {
					chairs[pos[used]] = fleft[i];

					int attempt = bad(pos[used - 1]);
					if (pos[used - 1] + 1 < pos[used]) {
						attempt += bad(pos[used - 1] + 1);
					}
					if (pos[used - 1] + 1 < pos[used] - 1) {
						attempt += bad(pos[used] - 1);
					}

					attempt += find(prev, fleft[i], bitset | (1 << i));

					if (res > attempt) {
						res = attempt;
						next[prprev][prev][bitset] = ((bitset | (1 << i)) * 11 + fleft[i]) * 11 + prev;
					}
				}
			}
		}

		dp[prprev][prev][bitset] = res;
	}

	return dp[prprev][prev][bitset];
}

int main() {
	std::cin >> n;

	e = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> chairs[i];
		if (chairs[i] == 0) {
			pos[e] = i;
			e++;
		} else {
			chairs[i] -= 180;
		}
	}

	std::cin >> c;
	for (int i = 0; i < c; i++) {
		std::cin >> fleft[i];
		fleft[i] -= 180;
	}
	std::sort(fleft, fleft + c);

	if (e != 0) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				for (int k = 0; k < (1 << 15); k++) {
					dp[i][j][k] = -1;
					next[i][j][k] = -1;
				}
			}
		int res = n;
		int forw = 0;

		for (int i = 0, attempt; i < c; i++) {
			attempt = 0;
			chairs[pos[0]] = fleft[i];
			if(pos[0] >= 2){
				attempt += bad(pos[0] - 1);
			}

			attempt += find(0, fleft[i], 1 << i);
			if (res > attempt) {
				res = attempt;
				forw = ((1 << i) * 11 + fleft[i]) * 11;
			}
		}

		for (int i = 0; i < e; i++) {
			int prprev = forw % 11;
			forw /= 11;
			int prev = forw % 11;
			forw /= 11;
			int bitset = forw;

			chairs[pos[i]] = prev;
			forw = next[prprev][prev][bitset];
		}
	}

	for(int i = 0; i < n; i++){
		std::cout << 180 + chairs[i] << ' ';
	}
	return 0;
}
