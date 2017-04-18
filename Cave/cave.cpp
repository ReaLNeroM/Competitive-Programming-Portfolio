#include "grader.h"
#include <bits/stdc++.h>

const int maxn = 5005;
int used[maxn];
int orient[maxn];
int connect[maxn];

void exploreCave(int N) {
	for(int i = 0; i < N; i++){
		used[i] = false;
		orient[i] = false;
		connect[i] = -1;
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(connect[j] == -1){
				orient[j] = 0;
			}
		}
		int result = tryCombination(orient);

		int the_switch = 0;
		if(result == -1 or result > i){
			int l = 0, r = N;

			while(l <= r){
				int mid = (l + r) / 2;

				for(int j = 0; j < N; j++){
					if(connect[j] == -1){
						orient[j] = (j < mid);
					}
				}

				int gotten = tryCombination(orient);

				if(gotten == -1 or gotten > i){
					l = mid + 1;
				} else {
					the_switch = mid - 1;
					r = mid - 1;
				}
			}

			orient[the_switch] = false;
		} else {
			int l = 0, r = N;

			while(l <= r){
				int mid = (l + r) / 2;

				for(int j = 0; j < N; j++){
					if(connect[j] == -1){
						orient[j] = !(j < mid);
					}
				}

				int gotten = tryCombination(orient);

				if(gotten == -1 or gotten > i){
					l = mid + 1;
				} else {
					the_switch = mid - 1;
					r = mid - 1;
				}
			}

			orient[the_switch] = true;
		}

		connect[the_switch] = i;
	}

	answer(orient, connect);
}
