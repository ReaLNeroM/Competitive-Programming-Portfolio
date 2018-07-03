#include <bits/stdc++.h>

typedef long long ll;

struct node {
	int val;
	node *l, *r;
};

node* head;

const int maxn = 1e6 + 1e2;
int type[maxn];
int posy[maxn];
int posx[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::string s;
		std::cin >> s >> posy[i] >> posx[i];

		if(s == "add"){
			type[i] = 0;
		} else if(s == "remove"){
			type[i] = 1;
		} else {
			type[i] = 2;
		}
	}
}