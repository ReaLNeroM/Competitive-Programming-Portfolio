#include <bits/stdc++.h>

typedef long long ll;

struct treap {
	int val, prior, size;
	treap *l, *r;
};

typedef treap* ptreap;

ptreap head = NULL;

int size(ptreap p){
	if(p){
		return p->size;
	}

	return 0;
}

int update_size(ptreap p){
	if(p){
		p->size = 1 + size(p->l) + size(p->r);
	}
}

void merge(ptreap& pos, ptreap l, ptreap r){
	if(!l or !r){
		if(!l){
			pos = r;
		} else {
			pos = l;
		}
	} else if(l->prior > r->prior){
		pos = l;
		merge(pos->r, l->r, r);
	} else {
		pos = r;
		merge(pos->l, l, r->l);
	}

	update_size(pos);
}

void split(ptreap pos, ptreap& l, ptreap& r, int val){
	if(!pos){
		l = r = NULL;
	} else if(val <= pos->val){
		split(pos->l, l, pos->l, val);
		r = pos;
	} else {
		split(pos->r, pos->r, r, val);
		l = pos;
	}

	update_size(pos);
}

bool find(ptreap pos, int val){
	if(!pos){
		return false;
	} else if(val == pos->val){
		return true;
	} else if(val < pos->val){
		return find(pos->l, val);
	} else {
		return find(pos->r, val);
	}
}

void insert(ptreap& pos, ptreap add){
	if(!pos){
		pos = add;
	} else if(add->prior > pos->prior){
		split(pos, add->l, add->r, add->val);
		pos = add;
	} else if(add->val < pos->val){
		insert(pos->l, add);
	} else {
		insert(pos->r, add);
	}

	update_size(pos);
}

void erase(ptreap& pos, int val){
	if(!pos){
		return;
	} else if(val == pos->val){
		ptreap temp = pos;
		merge(pos, pos->l, pos->r);
		delete temp;
	} else if(val < pos->val){
		erase(pos->l, val);
	} else {
		erase(pos->r, val);
	}

	update_size(pos);
}

int kth(ptreap pos, int val){
	if(size(pos->l) == val){
		return pos->val;
	} else if(size(pos->l) > val){
		return kth(pos->l, val);
	} else {
		return kth(pos->r, val - size(pos->l) - 1);
	}
}

int count(ptreap pos, int val){
	if(!pos){
		return 0;
	} else if(val <= pos->val){
		return count(pos->l, val);
	} else {
		return count(pos->r, val) + size(pos->l) + 1;
	}
}

ptreap init(int val, int prior){
	ptreap curr = new treap;
	curr->val = val;
	curr->prior = prior;
	curr->size = 1;
	curr->l = NULL;
	curr->r = NULL;

	return curr;
}

int main(){
	int q;
	std::cin >> q;

	std::srand(132573);

	for(int i = 0; i < q; i++){
		char c;
		int v;
		std::cin >> c >> v;

		if(c == 'I' and !find(head, v)){
			ptreap curr = init(v, rand());
			insert(head, curr);
		} else if(c == 'D' and find(head, v)){
			erase(head, v);
		} else if(c == 'F'){
			std::cout << (find(head, v) != NULL) << '\n';
		} else if(c == 'K'){
			if(v >= size(head) + 1){
				std::cout << "invalid\n";
			} else {
				std::cout << kth(head, v - 1) << '\n';
			}
		} else if(c == 'C'){
			std::cout << count(head, v) << '\n';
		}
	}
}
