#include <string>
#include <vector>
#include <cmath>

typedef long long ll;

class Sequence {
	const ll mod = 1000007;

	struct matrix {
		ll v[51][51];
		matrix(){
			for(ll i = 0; i <= 50; i++){
				for(ll j = 0; j <= 50; j++){
					v[i][j] = 0;
				}
			}
		}
	};

	matrix mult(const matrix &x, const matrix &y){
		matrix value;
		
		for(ll i = 0; i <= 50; i++){
			for(ll j = 0; j <= 50; j++){
				for(ll k = 0; k <= 50; k++){
					value.v[i][j] += x.v[i][k] * y.v[k][j];
					value.v[i][j] %= mod;
				}
			}
		}
		return value;
	}

	ll k;
public:
	int findElement(int gk, std::vector<int> coefficients, std::vector<int> elements, int p){
		k = gk;
		ll power = 1;
		for(ll i = 0; i < p; i++){
			power *= 10LL;
		}

		matrix start, result;

		for(ll i = 0; i < k; i++){
			if(i == 0){
				for(ll j = 0; j < k; j++){
					start.v[i][j] = coefficients[j];
				}
			} else {
				start.v[i][i - 1] = 1;
			}
			result.v[i][0] = elements[k - i - 1];
		}

		power -= k;
		for(ll curr_pow = 1; curr_pow <= power; curr_pow *= 2){
			if(curr_pow & power){
				result = mult(start, result);
			}
			start = mult(start, start);
		}

		return result.v[0][0];
	}
};
	