#include <iostream>

typedef long long ll;

struct list {
	list* back = NULL;
	list* next = NULL;
	int val = 0;

	void insert(int);
	list erase();
};


list* head = new list;
list* last = head;

void list::insert(int val){
	list* copy = new list;
	list* loc = this;

	copy->val = val;
	copy->back = loc;
	copy->next = loc->next;
	loc->next = copy;
}

list list::erase(){
	list copy = *this;

	if(this->back == NULL){
		head = this->next;
	} else if(this->next == NULL){
		last = this->back;
	} else {
		this->back->next = this->next;
	}
	delete(this);

	return copy;
}

int main() {
	int n;
	std::cin >> n;

	for(int i = 0, val; i < n; i++){
		std::cin >> val;

		last->insert(val);
		while(last->next != NULL){
			last = last->next;
		}
	}

	list* copy;
	for(list* ptr = head->next; ptr != NULL; ptr = copy){
		std::cout << ptr->val << ' ';

		copy = ptr->next;

		ptr->erase();
	}
	return 0;
}
