/*
ID: vlade.m1
PROG: agrinet
LANG: C++
*/

#include <fstream>
#include <algorithm>

std::ifstream fin("agrinet.in");
std::ofstream fout("agrinet.out");

class vertex{
	int rank = 1;
	vertex* head = this;
public:
	vertex* findhead(){
		if(head != head->head){
			head = head->findhead();
		}
		return head;
	}
	void merge(vertex* second){
		findhead();
		second = second->findhead();

		if(head->rank > second->rank){
			second->head = head;
		} else if(second->rank > head->rank){
			head->head = second;
		} else{
			head->head = second;
			second->rank++;
		}
	}
};
struct edge{
	int first, second, cost;

	bool operator<(const edge &x) const{
		return (cost < x.cost);
	}
} copy;

int main() {
	int n;
	fin >> n;

	vertex v[n];

	edge e[n * n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			e[i * n + j].first = i;
			e[i * n + j].second = j;
			fin >> e[i * n + j].cost;
		}
	}

	int sum = 0;
	std::sort(e, e + n * n);
	for(int i = 0; i < n * n; i++){
		if(v[e[i].first].findhead() != v[e[i].second].findhead()){
			sum += e[i].cost;
			v[e[i].first].merge(&v[e[i].second]);
		}
	}

	fout << sum << std::endl;
	return 0;
}
