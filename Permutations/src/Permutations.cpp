#include <iostream>

void perm(int level, int maxlevel, int v[]){
	if(maxlevel == level){
		for(int i = 0; i < maxlevel; i++){
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		return;
	}

	for(int i = 0; i < maxlevel; i++){
		if(v[i] == -1){
			v[i] = level;
			perm(level + 1, maxlevel, v);
			v[i] = -1;
		}
	}

}
int main() {
	int n;
	std::cin >> n;

	int v[n];
	for(int i = 0; i < n; i++){
		v[i] = -1;
	}
	perm(0, n, v);
	return 0;
}
