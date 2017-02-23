#include <iostream>

using namespace std;
typedef long long ll;

const int maxval = 1000000; // 10^6;

int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	static int occur[maxval];
	for(int i = 0; i < maxval; i++){
		occur[i] = 0;
	}

	int val[n];
	for(int i = 0; i < n; i++){
		cin >> val[i];
		val[i]--;
	}

	int right = n - 1;
	int used = 0;

	for(int i = 0; i < n and (used < k or occur[val[i]]) > 0; i++){
		if(!occur[val[i]]){
			used++;
		}
		occur[val[i]]++;
		if(used == k){
			right = i;
		}
	}

	int mleft = 0, mrigh = right;
	for(int left = 0; left < n;){
		do{
			occur[val[left]]--;
			if(occur[val[left]] == 0){
				used--;
			}
			left++;
		} while(used == k);
		while(right < n - 1 and (used < k or occur[val[right + 1]] > 0)){
			right++;

			if(occur[val[right]] == 0){
				used++;
			}
			occur[val[right]]++;
		}

		if(right - left > mrigh - mleft){
			mleft = left;
			mrigh = right;
		}
	}

	cout << mleft + 1 << ' ' << mrigh + 1;
	return 0;
}
