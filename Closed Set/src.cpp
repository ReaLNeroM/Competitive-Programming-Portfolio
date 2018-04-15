#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
typedef long long ll;

class ClosedSet{
	static const ll maxn = 30;
	static const ll mod = 100000007;
	static const ll maxbinomial = 100;
	ll pow2[maxn];
	ll ways_to_make[maxn];
	ll gcd[maxn][maxn];
	ll binomial[maxbinomial][maxbinomial];

	void dfs(ll bitset, ll pos, ll open_able){
		if(pos == 0){
			ways_to_make[__builtin_popcount(bitset)]++;
			return;
		}

		dfs(bitset, pos - 1, open_able);

		if(!(pow2[pos] & bitset) and open_able > 0){
			bitset |= pow2[pos];
			open_able--;

			for(ll j = 1, bit = 1; bit < bitset; j++, bit *= 2){
				if(bit & bitset and (bitset & pow2[gcd[j][pos]]) == 0){
					bitset |= pow2[gcd[j][pos]];
					open_able--;
				}
			}

			if(open_able >= 0){
				dfs(bitset, pos - 1, open_able);
			}
		}
	}
public:
	int closedSet(std::vector<int> A, int N, int K, int L){
		std::fill(ways_to_make, ways_to_make + maxn, 0);

		for(ll i = 1; i < maxn; i++){
			pow2[i] = (1 << (i - 1));
		}

		for(ll i = 1; i < maxn; i++){
			for(ll j = 1; j < maxn; j++){
				gcd[i][j] = std::__gcd(i, j);
			}
		}

		ll given = 0;
		for(ll i = 0; i < N; i++){
			given |= pow2[A[i]];
		}
		for(ll i = 0; i < A.size(); i++){
			for(ll j = 0; j < A.size(); j++){
				if((pow2[gcd[A[i]][A[j]]] & given) == 0){
					given |= pow2[gcd[A[i]][A[j]]];
					N++, K--;
				}
			}
		}

		if(K < 0){
			return 0;
		}

		dfs(given, L, K);

		for(ll i = 0; i < maxbinomial; i++){
			for(ll j = 0; j < maxbinomial; j++){
				if(i == 0 or j == 0 or i == j){
					binomial[i][j] = 1;
				} else {
					binomial[i][j] = binomial[i - 1][j - 1] + binomial[i - 1][j];
					binomial[i][j] %= mod;
				}
			}
		}
		ll res = 0;
		for(ll i = N; i <= L; i++){
			ll free = K - (i - N);
			ll spaces = i;

			res += binomial[spaces + free - 1][free] * ways_to_make[i];
			res %= mod;
		}

		return res;
	}
};
