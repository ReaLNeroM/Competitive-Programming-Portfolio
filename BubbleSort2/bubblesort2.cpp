#include "bubblesort2.h"
#include <bits/stdc++.h>

const int maxn = 1e6 + 1e2;
int fenwick[maxn];
std::set<int> value_positions[maxn];
int seg[4 * maxn];
int laz[4 * maxn];
int compressed_index;

void update_fenwick(int pos, int val){
	pos++;

	while(pos < maxn){
		fenwick[pos] += val;
		pos += pos & -pos;
	}
}

int query_fenwick(int pos){
	pos++;
	int res = 0;

	while(pos > 0){
		res += fenwick[pos];
		pos -= pos & -pos;
	}

	return res;
}

void propagate(int ind){
	seg[2 * ind + 1] += laz[ind];
	seg[2 * ind + 2] += laz[ind];
	laz[2 * ind + 1] += laz[ind];
	laz[2 * ind + 2] += laz[ind];
	laz[ind] = 0;
}

void update_tree(int ql, int qr, int change, int ind = 0, int cl = 0, int cr = maxn - 1){
	if(ql <= cl and cr <= qr){
		seg[ind] += change;
		laz[ind] += change;
		return;
	}

	propagate(ind);

	int mid = (cl + cr) / 2;

	if(ql <= mid)
		update_tree(ql, qr, change, 2 * ind + 1, cl, mid);
	if(mid < qr)
		update_tree(ql, qr, change, 2 * ind + 2, mid + 1, cr);

	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void set_equal(int pos, int value, int ind = 0, int cl = 0, int cr = maxn - 1){
	if(cl == cr){
		seg[ind] = value;
		laz[ind] = 0;
		return;
	}

	propagate(ind);

	int mid = (cl + cr) / 2;

	if(pos <= mid)
		set_equal(pos, value, 2 * ind + 1, cl, mid);
	else
		set_equal(pos, value, 2 * ind + 2, mid + 1, cr);


	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void update_value(int pos){
	if(!value_positions[pos].empty()){
		set_equal(pos, *value_positions[pos].rbegin() - (query_fenwick(pos) - 1));
	} else {
		set_equal(pos, 0);
	}
}

std::vector<int> count_scans(std::vector<int> A,std::vector<int> X,std::vector<int> V){
	std::map<int, int> compressor;
	for(int i = 0; i < A.size(); i++){
		compressor[A[i]] = 0;
	}
	for(int i = 0; i < V.size(); i++){
		compressor[V[i]] = 0;
	}

	compressed_index = 1;
	for(auto ite = compressor.begin(); ite != compressor.end(); ite++, compressed_index++){
		ite->second = compressed_index;
	}

	for(int i = 0; i < A.size(); i++){
		A[i] = compressor[A[i]];
	}
	for(int i = 0; i < V.size(); i++){
		V[i] = compressor[V[i]];
	}

	int Q = X.size();
	std::vector<int> answer(Q);

	for(int i = 0; i < A.size(); i++){
		value_positions[A[i]].insert(i);
		update_fenwick(A[i], 1);
	}

	for(int i = 0; i < compressed_index; i++){
		if(!value_positions[i].empty()){
			update_value(i);
		}
	}

	for (int j=0;j<Q;j++) {
		update_tree(A[X[j]] + 1, maxn - 1, 1);
		update_fenwick(A[X[j]], -1);
		update_tree(V[j] + 1, maxn - 1, -1);
		update_fenwick(V[j], 1);

		value_positions[A[X[j]]].erase(X[j]);
		update_value(A[X[j]]);
		A[X[j]] = V[j];
		value_positions[A[X[j]]].insert(X[j]);
		update_value(A[X[j]]);

		answer[j] = seg[0];
	}

	return answer;
}
