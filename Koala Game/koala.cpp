#include "koala.h"
#include <bits/stdc++.h>

int minValue(int N, int W) {
	int final[N];
	int response[N];
	std::fill(final, final + N, 0);
	final[0] = 1;

	playRound(final, response);
	for(int i = 0; i < N; i++){
		if(response[i] <= final[i]){
			return i;
		}
	}
}

int maxValue(int N, int W) {
	std::vector<int> possible;
	for(int i = 0; i < N; i++){
		possible.push_back(i);
	}

	int final[N];
	int response[N];
	int tagged[N];
	std::fill(tagged, tagged + N, 0);

	while(possible.size() > 1){
		std::fill(final, final + N, 0);

		int left_for_me = W;
		int left_places = possible.size();
		for(int j : possible){
			final[j] = left_for_me / left_places;
		}

		playRound(final, response);

		possible.clear();
		for(int j = 0; j < N; j++){
			if(!tagged[j] and response[j] >= final[j]){
				possible.push_back(j);
			} else {
				tagged[j] = true;
			}
		}
	}

	return possible[0];
}

int greaterValue(int N, int W) {
	int final[N];
	std::fill(final, final + N, 0);
	int l = 1, r = std::min(8, W / 2);

	int prev_response[N];

	while(l <= r){
		int mid = (l + r) / 2;
		final[0] = mid;
		final[1] = mid;

		int response[N];

		playRound(final, response);

		std::copy(response, response + N, prev_response);

		if(response[0] > mid and response[1] <= mid){
			return 0;
		} else if(response[0] <= mid and response[1] > mid){
			return 1;
		} else if(response[0] > mid and response[1] > mid){
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return -1;
}

void allValues(int N, int W, int *P) {
    if (W == 2*N) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
    	int smallest = minValue(N, W);
    	int indices[N + 1];
    	std::fill(indices, indices + N + 1, -1);

    	std::fill(P, P + N, 0);
    	indices[1] = smallest;
    	P[smallest] = 1;

    	for(int i = 2; i <= N; i++){
	    	int found = 1;
	    	int final[N];
	    	int response[N];
	    	std::fill(final, final + N, 0);

	    	for(int j = 1; j < i; j++){
	    		int b = j;
	    		int c = 2;
	    		int d = i;

	    		int a = 0;
	    		a = (c * b + d - 1) / d;

	    		final[indices[j]] = a;
	    	}

	    	for(int j = 0; j < N; j++){
	    		if(P[j] == 0){
	    			final[j] = 1;
	    			break;
	    		}
	    	}
	    	playRound(final, response);

	    	for(int j = 0; j < N; j++){
	    		if(P[j] == 0 and response[j] <= final[j]){
	    			P[j] = i;
	    			indices[i - 1] = j;
	    			break;
	    		}
	    	}
    	}
    }
}
