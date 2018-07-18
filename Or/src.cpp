#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 5e2 + 1e2;
const ll MAXBIT = 10;

int sparse_table[MAXBIT][MAXBIT][MAXN][MAXN];
int biggest_pow2[MAXN];
int val[MAXN][MAXN];
int res = MAXN * MAXN;

int query(int x1, int x2, int y1, int y2){
	int x_pow = biggest_pow2[x2 - x1 + 1];
	int y_pow = biggest_pow2[y2 - y1 + 1];
	int x_pow_size = (1 << x_pow);
	int y_pow_size = (1 << y_pow);

	int res = sparse_table[x_pow][y_pow][x1][y1] 
				| sparse_table[x_pow][y_pow][x2 - x_pow_size + 1][y1]
	            | sparse_table[x_pow][y_pow][x1][y2 - y_pow_size + 1]
	            | sparse_table[x_pow][y_pow][x2 - x_pow_size + 1][y2 - y_pow_size + 1];

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		freopen("or.in", "r", stdin);
		freopen("or.out", "w", stdout);
	#endif

	ll x, n;
	std::cin >> x >> n;

	for(int i = 0, bit = 1; bit < MAXN; i++, bit *= 2){
		for(int j = bit; j < MAXN and j < 2 * bit; j++){
			biggest_pow2[j] = i;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> val[i][j];
			sparse_table[0][0][i][j] = val[i][j];
		}
	}

	for(int bit_i = 0; bit_i < MAXBIT; bit_i++){
		for(int bit_j = 0; bit_j < MAXBIT; bit_j++){
			if(bit_i == 0 and bit_j == 0){
				continue;
			}

			for(int i = 0; i + (1 << bit_i) <= n; i++){
				for(int j = 0; j + (1 << bit_j) <= n; j++){
					if(bit_j != 0){
						sparse_table[bit_i][bit_j][i][j] = sparse_table[bit_i][bit_j - 1][i][j] 
													    	 | sparse_table[bit_i][bit_j - 1][i][j + (1 << (bit_j - 1))];
					} else {
						sparse_table[bit_i][bit_j][i][j] = sparse_table[bit_i - 1][bit_j][i][j]
													    	 | sparse_table[bit_i - 1][bit_j][i + (1 << (bit_i - 1))][j];
					}
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int curr_pos = -1;

			int or_achieved = 0;

			for(int k = 0; k < n; k++){
				curr_pos = std::max(curr_pos, k);

				or_achieved = query(i, j, k, curr_pos);
				while(curr_pos < n - 1 and ((or_achieved ^ x) | x) == x and or_achieved < x){
					curr_pos++;
					or_achieved = query(i, j, k, curr_pos);
				}

				if(or_achieved == x){
					res = std::min(res, (j - i + 1) * (curr_pos - k + 1));
				}
			}
		}
	}

	std::cout << res << '\n';
}
