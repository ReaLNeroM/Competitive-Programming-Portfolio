#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
const int maxlogn = 20;

struct node {
	node *adj[2], *parent, *child;
	int lazy_direction;
	int num_adj[2];
};

node* nodes[maxlogn][maxn];
int input[maxn];
int n;

bool flip(){
	int x = std::rand() % 2;

	return x;
}

void build(){
	for(int level = 0; level < maxlogn; level++){
		node* last = NULL;
		int last_index = 0;
		for(int i = 0; i < n; i++){
			nodes[level][i] = new node;
			nodes[level][i]->adj[0] = nodes[level][i]->adj[1] = NULL;
			nodes[level][i]->child = NULL;
			nodes[level][i]->parent = NULL;
			nodes[level][i]->lazy_direction = 0;
			nodes[level][i]->num_adj[0] = nodes[level][i]->num_adj[1] = 1;

			if(i != 0){
				nodes[level][i]->adj[0] = nodes[level][i - 1];
				nodes[level][i - 1]->adj[1] = nodes[level][i];
			}

			if(level != 0 and nodes[level - 1][i] != NULL and (i == 0 or flip())){
				if(last != NULL){
					nodes[level][i]->adj[0] = last;
					last->adj[1] = nodes[level][i];
					nodes[level][i]->num_adj[0] = last->num_adj[1] = i - last_index;
				}
				nodes[level][i]->child = nodes[level - 1][i];
				nodes[level - 1][i]->parent = nodes[level][i];

				last = nodes[level][i];
				last_index = i;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> input[i];
		input[i]--;
	}

	std::vector<int> res(n);

	for(int i = 0; i < n; i++){
		int loc = find_loc()
	}
}