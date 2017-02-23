#include <iostream>
#include <queue>

typedef long long ll;

int main() {
	int numbers;
	std::cin >> numbers;

	int n[numbers];
	std::priority_queue<int> q, found;

	for(int i = 0; i < numbers; i++){
		for(int j = 0, inp; j < numbers; j++){
			std::cin >> inp;
			q.push(inp);
		}
	}

	for(int i = 0; i < numbers; i++){
		n[i] = q.top();
		q.pop();

		for(int j = 0; j < i; j++){
			int copya = n[j], copyb = n[i];

			int remainder;
			while(true){
				remainder = copya % copyb;
				if(remainder == 0){
					break;
				}
				copya = copyb;
				copyb = remainder;
			}
			found.push(copyb);
			found.push(copyb);
		}

		while(!found.empty() and q.top() == found.top()){
			q.pop(), found.pop();
		}
	}

	for(int i = 0; i < numbers; i++){
		std::cout << n[i] << ' ';
	}
	return 0;
}
