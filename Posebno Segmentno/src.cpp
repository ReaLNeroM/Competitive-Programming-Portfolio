#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
std::vector<int> laz[8 * maxn];

void propagate(int ind, int cl, int cr){
	if(cl != cr and !laz[ind].empty()){
		if(laz[2 * ind + 1].empty()){
			laz[2 * ind + 1] = laz[ind];
		} else {
			if(laz[ind][2] != 0){//FIXIT
				laz[2 * ind + 1] = laz[ind];
			} else if(laz[ind][1] != 0){
				if(laz[2 * ind + 1][1] == 0){
					laz[2 * ind + 1] = {laz[2 * ind + 1][0] * laz[ind][1] + laz[ind][0],                   1 * laz[ind][1], laz[2 * ind + 1][2]};
				} else {
					laz[2 * ind + 1] = {laz[2 * ind + 1][0] * laz[ind][1] + laz[ind][0], laz[2 * ind + 1][1] * laz[ind][1], laz[2 * ind + 1][2]};
				}
			} else if(laz[ind][0] != 0){
				laz[2 * ind + 1][0] += laz[ind][0];
			}
		}

		if(laz[2 * ind + 2].empty()){
			laz[2 * ind + 2] = laz[ind];
		} else {
			if(laz[ind][2] != 0){//FIXIT
				laz[2 * ind + 2] = laz[ind];
			} else if(laz[ind][1] != 0){
				if(laz[2 * ind + 2][1] == 0){
					laz[2 * ind + 2] = {laz[2 * ind + 2][0] * laz[ind][1] + laz[ind][0],                   1 * laz[ind][1], laz[2 * ind + 2][2]};
				} else {
					laz[2 * ind + 2] = {laz[2 * ind + 2][0] * laz[ind][1] + laz[ind][0], laz[2 * ind + 2][1] * laz[ind][1], laz[2 * ind + 2][2]};
				}
			} else if(laz[ind][0] != 0){
				laz[2 * ind + 2][0] += laz[ind][0];
			}
		}
		laz[ind].clear();
	}
}

void update(int type, int value, int ql, int qr, int ind = 0, int cl = 0, int cr = maxn - 1){
	propagate(ind, cl, cr);

	if(ql <= cl and cr <= qr){
		if(type == 0){
			if(laz[ind].empty()){
				laz[ind] = {value, 0, 0};
			} else {
				laz[ind][0] += value;
			}
		} else if(type == 1){
			if(laz[ind].empty()){
				laz[ind] = {0, value, 0};
			} else {
				laz[ind][1] *= value;
				laz[ind][0] *= value;
			}
		} else if(type == 2){
			laz[ind] = {0, 0, value};
		}
		return;
	} else if(cr < ql or qr < cl){
		return;
	}

	int mid = (cl + cr) / 2;

	update(type, value, ql, qr, 2 * ind + 1, cl     , mid);
	update(type, value, ql, qr, 2 * ind + 2, mid + 1, cr );
}

int query(int pos, int ind = 0, int cl = 0, int cr = maxn - 1){
	propagate(ind, cl, cr);

	if(cl == cr){
		if(laz[ind].empty()){
			return 0;
		} else {
			return laz[ind][2] * laz[ind][1] + laz[ind][0];
		}
	}

	int mid = (cl + cr) / 2;
	if(pos <= mid){
		return query(pos, 2 * ind + 1, cl     , mid);
	} else {
		return query(pos, 2 * ind + 2, mid + 1, cr );
	}
}

int main(){
	char type;
	int pos;
	while(std::cin >> type >> pos, type != '0'){
		pos--;

		int value;
		if(type != 'Q'){
			std::cin >> value;
		}

		if(type == 'A'){
			update(0, value, pos, maxn - 1);
		} else if(type == 'M' and query(pos) != 0){ //value * 0 is still 0
			update(1, value, pos, maxn - 1);
		} else if(type == 'S'){
			update(2, value, pos, maxn - 1);
		} else if(type == 'Q'){
			std::cout << query(pos) << '\n';
		}
	}
}
