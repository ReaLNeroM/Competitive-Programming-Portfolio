#include "xylophone.h"
#include <bits/stdc++.h>

static int A[5005];

void solve(int N) {
	A[1] = 0;
	A[2] = query(1, 2);

	int above_pos = 2;
	int below_pos = 1;

	for(int i = 3; i <= N; i++){
		int a = query(above_pos, i);
		int b = query(below_pos, i);

		if(above_pos > below_pos){
			if(b == A[above_pos] - A[below_pos]){
				A[i] = A[above_pos] - a;
				below_pos = i;
			} else if(a == b){
				A[i] = A[above_pos] - a;
				below_pos = i;
			} else {
				A[i] = A[above_pos] + a;
				above_pos = i;
			}
		} else {
			if(a == A[above_pos] - A[below_pos]){
				A[i] = A[below_pos] + b;
				above_pos = i;
			} else if(a == b){
				A[i] = A[below_pos] + b;
				above_pos = i;
			} else {
				A[i] = A[below_pos] - b;
				below_pos = i;
			}
		}
	}


	int smallest_value = *std::min_element(A + 1, A + N + 1);
	for(int i = 1; i <= N; i++){
		A[i] -= smallest_value - 1;
	}

	int smallest = std::min_element(A + 1, A + N + 1) - A;
	int biggest = std::max_element(A + 1, A + N + 1) - A;
	if(smallest > biggest){
		for(int i = 1; i <= N; i++){
			A[i] = N - A[i] + 1;
		}
	}

	for(int i = 1; i <= N; i++) {
		answer(i, A[i]);
	}
}
