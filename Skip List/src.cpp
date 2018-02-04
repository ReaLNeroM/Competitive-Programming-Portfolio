#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int levels = std::ceil(std::log2(maxn));

struct node {
	node *parent, *child;
	node* adj[2];
	int laz_adj[2];
	int width[2];
	node(){
		adj[0] = adj[1] = NULL;
		laz_adj[0] = laz_adj[1] = NULL;
		width[0] = width[1] = 1;
	}
}

struct skip_list {
	node* root;
	std::vector<node*> values;
	skip_list(){
		root = new node;

		node* curr = root;

		for(int i = 1; i < levels; i++){
			node* child = new node;
			curr.child = child;
			child.parent = curr;

			curr = child;
		}
	}
	void build(int n, int input[]){
		values.resize(n, NULL);

		node* pos = root;
		for(int i = 1; i < levels; i++){
			pos = pos->child;
		}
		for(int i = 0; i < n; i++){
			//adj[0] i taka natam
		}
		for(int i = levels - 2; i >= 1; i--){
			pos = pos->parent;
			//praj stvari
		}

		for(int i = 0; i < n; i++){
			
		}
	}
	int find_loc(int value){
		node* curr = values[value];
		bool flag = false;
		std::deque<node*> d;
		do {
			d.push_front(curr);
			if(curr->parent != NULL){
				curr = curr->parent;
			} else if(!flag){
				flag = curr->laz_adj[0];
				curr = curr->adj[0];
			} else if(flag){
				flag = curr->laz_adj[1];
				curr = curr->adj[1];
			}
		} while(curr != root);
		d.push_front(curr);

		int pos = 0; //sum up the width
		curr = d[0];
		for(int i = 1; i < d.size(); i++){
			node* next = d[i];
			if(next->child == next){
				curr = next->child;
			} else if(next->adj[0] == next){
				curr = next->adj[0];
				pos += next->width[0];
			} else if(next->adj[1] == next){
				curr = next->adj[1];
				pos += next->width[1];
			}
		}

		return pos;
	}
	void reverse(){

	}
}

int input[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> input[i];
	}

	skip_list T;

	T.build(n, input);

	std::vector<int> res;

	for(int i = 0; i < n; i++){
		int location = T.find_loc(i);
		if(i != location){
			T.reverse(i, location);
		}
		res.push_back(location);
	}

	for(int i = 0; i < n; i++){
		std::cout << res[i] << ' ';
	}
	std::cout << '\n';
}