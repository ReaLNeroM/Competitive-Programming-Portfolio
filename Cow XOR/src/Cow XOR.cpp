/*
ID: vlade.m1
PROG: cowxor
LANG: C++
 */
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1e2;
const int maxbits = 22;
static int val[maxn];
static int orig[maxn];
static bool seen[1 << maxbits];

int main(){
    freopen("cowxor.in", "r", stdin);
    freopen("cowxor.out", "w", stdout);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> val[i];
		orig[i] = val[i];
	}
	for(int i = 1; i < n; i++){
		val[i] ^= val[i - 1];
	}
	for(int i = 0; i < maxbits; i++){
		seen[1 << i] = true;
	}
	int best_start = n - 1;
	int best_value = -1;

	for(int i = 0; i < n; i++){
		int copy_num = val[i];
		for(int j = 0, bit = 1; j < maxbits - 1; j++, bit *= 2){
			if(bit & copy_num){
				seen[(copy_num * 2) | bit] = true;
				copy_num ^= bit;
			} else {
				seen[(copy_num * 2) | bit] = true;
			}
		}
		int made = 0;
		int val_made = 0;
		for(int j = maxbits - 2; j >= 0; j--){
			if((1 << j) & val[i]){
				val_made |= (1 << j);
			}
			int try_num = made;
			try_num |= (1 << j);
			if(seen[(val_made ^ try_num) * 2 + (1 << j)]){
				made = try_num;
			}
		}
		if(made > best_value){
			best_value = made;
			best_start = i;
		}
	}
	int best_end = n - 1;
	int xor_value = 0;
	for(int i = best_start; i >= 0; i--){
		xor_value ^= orig[i];
		if(xor_value == best_value){
			best_end = i;
			break;
		}
	}

	cout << best_value << ' ' << best_end + 1 << ' ' << best_start + 1<< endl;
}

