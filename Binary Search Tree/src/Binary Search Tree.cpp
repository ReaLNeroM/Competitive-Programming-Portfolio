#include <iostream>

struct tree {
	struct node{
		node* left = nullptr, *right = nullptr, *parent = nullptr;
		int val = -1;
	} headval;

	node* search(int val, node* start){
		if(start->val != -1){
			if(start->val > val) {
				return search(val, start->right);
			} else if(start->val < val){
				return search(val, start->left);
			} else if(start->val == val){
				return start;
			}
		}

		return start;
	}
	void insert(int val){
		node* location = search(val, &headval);
		if(location->val == -1){
			location = new node;

			if(location->parent != nullptr){
				if(location->parent->val > location->val){
					location->parent->right = location;
				} else{
					location->parent->left = location;
				}
			}
			location->left = new node;
			location->left->parent = location;
			location->right = new node;
			location->right->parent = location;

			location->val = val;
			headval = *location;
		}
	}
};

int main() {
	tree bst;
	char c;
	int pos;
	do{
		std::cin >> c >> pos;

		switch (c){
			case 'S':
				std::cout << bst.search(pos, &bst.headval)->val << std::endl;
				break;
			case 'I':
				bst.insert(pos);
				break;
/*			case 'R':
				bst.remove(pos);
				break;
			case 'P':
				std::cout << bst.prev(pos) << std::endl;
				break;
			case 'N':
				std::cout << bst.next(pos) << std::endl;
				break;
			case 'O':
				inorder();
				std::cout << std::endl;
				break;*/
		}
	} while(c != '0');
	return 0;
}
