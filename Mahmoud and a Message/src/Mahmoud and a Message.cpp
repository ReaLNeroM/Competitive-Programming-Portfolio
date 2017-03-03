#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e3 + 1e2;
int val[maxn];
int best[maxn];
int app[26];
int largest = 0;
const ll mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;

	string s;
	cin >> s;

	for(int i = 0; i < n; i++){
		cin >> app[i];
	}

	val[n] = 1;
	best[n] = 0;

	for(int i = n - 1; i >= 0; i--){
		int found[26];
		for(int j = 0; j < 26; j++){
			found[j] = 0;
		}

		for(int j = i; j < n; j++){
			found[s[j] - 'a']++;
			for(int k = 0; k < 26; k++){
				if(found[k] != 0 and app[k] < j - i + 1){
					j = n;
					break;
				}
			}
			if(j == n){
				break;
			}
			val[i] += val[j + 1];
			val[i] %= mod;
			best[i] = best[j + 1] + 1;
			largest = max(largest, j - i + 1);
		}
	}

	cout << val[0] << endl;
	cout << largest << endl;
	cout << best[0] << endl;
}
