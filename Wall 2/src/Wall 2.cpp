#include <bits/stdc++.h>
#include "grader.h"

using namespace std;
typedef long long ll;

const int maxn = 2000005;
const int maxh = 10000005;
int sl[8 * maxn];
int sr[8 * maxn];
bool last[8 * maxn];
int ch, l, r, h;

void upd(int a, int b){
	if(last[a] == 1){
		sl[b] = max(sl[b], sl[a]);
		if(sl[b] > sr[b]){
			sr[b] = sl[b];
		}
	} else {
		sr[b] = min(sr[b], sr[a]);
		if(sl[b] > sr[b]){
			sl[b] = sr[b];
		}
	}
	if(last[a] == 0){
		sl[b] = max(sl[b], sl[a]);
		if(sl[b] > sr[b]){
			sr[b] = sl[b];
		}
	} else {
		sr[b] = min(sr[b], sr[a]);
		if(sl[b] > sr[b]){
			sl[b] = sr[b];
		}
	}
}

void laz(int pos){
	upd(pos, 2 * pos + 1);
	upd(pos, 2 * pos + 2);
	sl[pos] = -1;
	sr[pos] = maxh;
	last[pos] = false;
}

void change(int pos, int cl, int cr){
	if(l <= cl and cr <= r){
		if(ch == 0){
			sl[pos] = max(sl[pos], h);
			if(sl[pos] > sr[pos]){
				sr[pos] = sl[pos];
			}
		} else {
			sr[pos] = min(sr[pos], h);
			if(sr[pos] < sl[pos]){
				sl[pos] = sr[pos];
			}
		}
		last[pos] = ch;
		return;
	} else if(cr < l or r < cl){
		return;
	}

	laz(pos);

	int mid = (cl + cr) / 2;
	change(2 * pos + 1, cl, mid);
	change(2 * pos + 2, mid + 1, cr);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
	for(int i = 0; i < 8 * maxn; i++){
		sl[i] = 0;
		sr[i] = 0;
		last[i] = 0;
	}

	for(int i = 0; i < k; i++){
		ch = op[i] - 1;
		l = left[i];
		r = right[i];
		h = height[i];

		change(0, 0, n - 1);
	}

	queue<int> q, l, r;
	q.push(0), l.push(0), r.push(n - 1);
	while(!q.empty()){
		int frq = q.front(), frl = l.front(), frr = r.front();
		q.pop(), l.pop(), r.pop();

		if(frl == frr){
			if(last[frq] == 0){
				finalHeight[frl] = sl[frq];
			} else {
				finalHeight[frl] = sr[frq];
			}
		} else {
			laz(frq);
			q.push(2 * frq + 1), l.push(frl), r.push((frl + frr) / 2);
			q.push(2 * frq + 2), l.push((frl + frr) / 2 + 1), r.push(frr);
		}
	}


	return;
}
