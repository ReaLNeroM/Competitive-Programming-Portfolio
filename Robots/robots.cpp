#include "grader.h"
#include <bits/stdc++.h>

typedef long long ll;

std::vector<int> a, b;
std::vector<std::pair<int, int>> t;

bool good(int sweeps){
	std::priority_queue<int> pq;

	int curr = 0;

	for(int i = 0; i < a.size(); i++){
		while(curr < t.size() and t[curr].first < a[i]){
			pq.push(t[curr].second);
			curr++;
		}

		for(int j = 0; j < sweeps and !pq.empty(); j++){
			pq.pop();
		}
	}

	for(int i = curr; i < t.size(); i++){
		pq.push(t[i].second);
	}

	for(int i = 0; i < b.size(); i++){
		for(int j = 0; j < sweeps and !pq.empty(); j++){
			if(pq.top() < b[i]){
				pq.pop();
			} else {
				i = b.size();
				break;
			}
		}
	}

	return (pq.empty());
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
	a.resize(A);
	for(int i = 0; i < A; i++){
		a[i] = X[i];
	}
	sort(a.begin(), a.end());

	b.resize(B);
	for(int i = 0; i < B; i++){
		b[i] = Y[i];
	}
	sort(b.begin(), b.end(), std::greater<int>());

	t.resize(T);
	for(int i = 0; i < T; i++){
		t[i] = {W[i], S[i]};
	}
	sort(t.begin(), t.end());

	int l = 0, r = T;
	int best = -1;

	while(l <= r){
		int mid = (l + r) / 2;

		if(good(mid)){
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return best;
}
