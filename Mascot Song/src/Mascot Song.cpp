#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int val[3 * n], blocks = 1;
	for(int i = 0; i < n; i++){
		cin >> val[i];
		val[n + n + i] = val[n + i] = val[i];
		if(i != 0 and val[i - 1] >= val[i]){
			blocks++;
		}
	}

	int q, start = 0;
	cin >> q;
	for(int i = 0; i < q; i++){
		int type;
		cin >> type;

		if(type == 1){
			int ind, change;
			cin >> ind >> change;

			ind--;
			ind = (start + ind) % n;
			ind += n;

			if(ind - n == start){
				if(val[ind] < val[ind + 1] and change >= val[ind + 1]){
					blocks++;
				} else if(val[ind] >= val[ind + 1] and change < val[ind + 1]){
					blocks--;
				}
			} else if((start != 0 and ind - n == start - 1) or (start == 0 and ind - n == n - 1)){
				if(val[ind - 1] < val[ind] and change <= val[ind - 1]){
					blocks++;
				} else if(val[ind - 1] >= val[ind] and val[ind - 1] < change){
					blocks--;
				}
			} else {
				int oldc = (val[ind - 1] >= val[ind] and val[ind] >= val[ind + 1]) + !(val[ind - 1] < val[ind] and val[ind] < val[ind + 1]);
				int newc = (val[ind - 1] >= change and change >= val[ind + 1]) + !(val[ind - 1] < change and change < val[ind + 1]);

				if(oldc > newc){
					blocks -= oldc - newc;
				} else {
					blocks += newc - oldc;
				}
			}
			val[ind - n] = val[ind] = val[ind + n] = change;
		} else {
			int cycle;
			cin >> cycle;

			if(val[n + start - 1] < val[n + start]){
				blocks--;
			}
			start += cycle;
			start %= n;

			if(val[n + start - 1] < val[n + start]){
				blocks++;
			}
		}

		cout << blocks << '\n';
	}

	return 0;
}
