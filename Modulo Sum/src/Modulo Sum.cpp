#include <iostream>
#include <queue>

typedef long long ll;

const int MAXN = 1e6 + 1e2;
const int MAXMOD = 1e3 + 1e2;
ll size, modulo;
int achievable[MAXMOD];
int need_size[MAXMOD];

void disable(int pos){
	for(int j = 1; j < modulo; j++){
		if(achievable[(pos - j + modulo) % modulo]){
			need_size[j]--;
		}
	}
}

void update(int pos){
	for(int j = 1; j < modulo; j++){
		if(!achievable[(pos + j) % modulo]){
			need_size[j]++;
		}
	}
}

int main(){
	std::cin >> size >> modulo;

	for(int i = 1; i <= size; i++){
		int num;
		std::cin >> num;

		num %= modulo;

		if(need_size[num]){
			for(int j = 0; j < modulo; j++){
				int next = (num + j) % modulo;
				if(achievable[j] != i and achievable[j] and !achievable[next]){
					disable(next);
					achievable[next] = i;
					update(next);
				}
			}
		}

		if(!achievable[num]){
			disable(num);
			achievable[num] = i;
			update(num);
		}
	}

	std::cout << ((achievable[0]) ? "YES" : "NO") << '\n';
}
