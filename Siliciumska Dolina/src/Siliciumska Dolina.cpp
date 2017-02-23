#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long long ll;

struct vline {
	int x, y[2];
	int ind1;
};

struct hline {
	int y, x[2];
	int ind1, ind2;
} copy;

bool cmp(vline x, vline y) {
	return (x.x < y.x);
}

class unionset{
	int rank = 1;
	unionset *parent = this;

	public:
	unionset* FindHead(){
		if(parent != parent->parent){
			parent = parent->FindHead();
		}

		return parent;
	}

	void Merge(unionset* second_node){
		unionset* head = FindHead();
		second_node = second_node->FindHead();
		if(head->rank > second_node->rank){
			second_node->parent = head;
		} else if(second_node->rank > head->rank){
			head->parent = second_node;
		} else{
			head->parent = second_node;
			head->rank++;
		}
	}
};

int main() {
	int lines;
	std::cin >> lines;

	vline l[lines];
	for (int i = 0; i < lines; i++) {
		std::cin >> l[i].x >> l[i].y[0] >> l[i].y[1];
		l[i].ind1 = i;
		if(l[i].y[0] > l[i].y[1]){
			std::swap(l[i].y[0], l[i].y[1]);
		}
	}
	std::sort(l, l + lines, cmp);

	int max = -1;
	std::vector<vline> v;
	std::vector<hline> h;

	for (int b = 1; b < (1 << (lines)); b++) {
		int taken = 0;
		v.clear();
		h.clear();
		for (int j = 0; j < lines; j++) {
			if ((1 << j) & b) {
				taken++;
				l[j].ind1 = v.size();
				v.push_back(l[j]);
			}
		}

		bool problem = false;

		bool used[taken][2];
		for (int i = 0; i < taken; i++) {
			for (int j = 0; j < 2; j++) {
				used[i][j] = false;
			}
		}

		unionset u[v.size()];
		for(int i = 0; i < taken; i++){
			for(int j = 0; j < 2; j++){
				if(!used[i][j]){
					for(int k = i + 1; k < taken; k++){
						for(int l = 0; l < 2; l++){
							if(!used[k][l] and v[i].y[j] == v[k].y[l]){
								copy.y = v[i].y[j];
								copy.x[0] = v[i].x;
								copy.x[1] = v[k].x;
								copy.ind1 = i;
								copy.ind2 = k;

								u[i].Merge(&u[k]);
								h.push_back(copy);

								used[i][j] = true;
								used[k][l] = true;

								k = taken;
								break;
							}
						}
					}

					if(!used[i][j]){
						problem = true;
					}
				}
			}
		}
		unionset* head = u[0].FindHead();
		for(int i = 0; i < v.size(); i++){
			if(u[i].FindHead() != head){
//				problem = true;
			}
		}

		for(int i = 0; i < v.size(); i++){
			for(int j = i + 1; j < v.size(); j++){
				if(v[i].x == v[j].x and !(v[j].y[0] > v[i].y[1] or v[j].y[1] < v[i].y[0])){
					problem = true;
				}
			}
			for(int j = 0; j < h.size(); j++){
				if(v[i].ind1 != h[j].ind1 and v[i].ind1 != h[j].ind2 and v[i].y[0] <= h[j].y and v[i].y[1] >= h[j].y and v[i].x >= h[j].x[0] and v[i].x <= h[j].x[1]){
					problem = true;
				}
			}
		}
		for(int i = 0; i < h.size(); i++){
			for(int j = i + 1; j < h.size(); j++){
				if(h[i].y == h[j].y and !(h[j].x[0] > h[i].x[1] or h[j].x[1] < h[i].x[0])){
					problem = true;
				}
			}
		}


		if (!problem) {
			max = std::max(max, 2 * taken);
		}
	}

	std::cout << max;
	return 0;
}
