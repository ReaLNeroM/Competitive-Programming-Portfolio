#include <iostream>
#include <vector>
#include <queue>

struct vertex{
	int dood = 0;
};

std::vector<vertex> v;
std::queue<int> q;

int main(){
	int n, edges;
	std::cin >> n >> edges;

	v.resize(n);

	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;
		second--;
		v[second].dood++;
	}

	int sum = 0;
	for(int i = 0; i < n; i++){
		if(v[i].dood == 0){
			sum++;
		}
	}

	sum += (sum == 0);
	std::cout << sum;
}
