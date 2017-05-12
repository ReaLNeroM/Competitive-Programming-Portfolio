#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
int size[2];
int force[2][maxn];
ll placeused[2][maxn];
ll sideused[maxn];
ll lpos[maxn];
ll rpos[maxn];
ll sum = 0;
ll res = 0;

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> size[0] >> size[1] >> sum;
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < size[i]; j++){
			std::cin >> force[i][j];
			if(i == 1){
				force[i][j] *= -1;
			}
		}
	}
	
	ll curr_sum = 0;

	for(int i = 0; i < size[0] + size[1]; i++){
		lpos[i] = pos[0];
		rpos[i] = pos[1];

		if(pos[0] == size[0] or (curr_sum + force[0][pos[0]] > sum)){
			curr_sum += force[1][pos[1]];
			orderused[i] = 1;
			placeused[pos[1]] = i;
			pos[1]++;
		} else {
			curr_sum += force[0][pos[0]];
			orderused[i] = 0;
			placeused[pos[0]] = i;
			pos[0]++;
		}
	}

	int q;
	std::cin >> q;

	for(int i = 0; i < q; i++){
		 scanf(" %c %lld %lld", &side_character, )
	}
}