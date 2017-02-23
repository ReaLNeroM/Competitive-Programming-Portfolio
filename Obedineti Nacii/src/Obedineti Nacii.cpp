#include <iostream>

class Union{
	Union* parent = this;

	public:
		long long size = 1;
		bool printed = false;
		Union* head(){
			if(this == parent){
				return this;
			} else{
				return parent = parent->head();
			}
		}

		void merge(Union* second){
			Union* h = head(), *s_h = second->head();
			s_h->size += h->size;
			h->parent = s_h;
		}
};

int main(){
	long long vertices, edges;
	std::cin >> vertices >> edges;

	Union v[vertices];

	for(long long i = 0, loc1, loc2; i < edges; i++){
		std::cin >> loc1 >> loc2;
		loc1--, loc2--;

		if(v[loc1].head() != v[loc2].head()){
			v[loc1].merge(&v[loc2]);
		}
	}

	long long minsize = vertices, maxsize = 0, sum = 0;
	for(int i = 0; i < vertices; i++){
		if(v[i].head()->printed == false){
			minsize = std::min(minsize, v[i].head()->size);
			maxsize = std::max(maxsize, v[i].head()->size);
			sum++;
			v[i].head()->printed = true;
		}
	}

	std::cout << sum << std::endl << minsize << ' ' << maxsize;
}
