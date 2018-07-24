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
    // TODO: Implement Subtask 3 solution here.
    // You may leave this function unmodified if you are not attempting this
    // subtask.
    return 0;
}

void allValues(int N, int W, int *P) {
    if (W == 2*N) {
        // TODO: Implement Subtask 4 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    } else {
        // TODO: Implement Subtask 5 solution here.
        // You may leave this block unmodified if you are not attempting this
        // subtask.
    }
}
