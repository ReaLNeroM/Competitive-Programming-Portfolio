#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 50005;
bool asked[maxn];
int n, s, x;

std::vector<int> query(int ind){
	std::cout << "? " << ind << std::endl;
	std::vector<int> v(2);
	std::cin >> v[0] >> v[1];

	return v;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> s >> x;

	auto best = query(s);

	std::srand(345436);

	for(int i = 0; i < 1000 and i < n; i++){
		bool found = false;

		while(!found){
			int ask = (rand() * rand()) % n + 1;
			if(!asked[ask]){
				found = true;

				auto get = query(ask);

				if(get[0] <= x and best[0] < get[0]){
					best = get;
				}

				asked[ask] = true;
			}
		}
	}

	int bestres = best[0];

	for(int j = 0; j < 995 and best[1] >= 0; j++){
		auto get = query(best[1]);

		if(get[0] >= x and (bestres < x or bestres > get[0])){
			bestres = get[0];
		}

		best = get;
	}

	if(bestres < x){
		bestres = -1;
	}

	std::cout << "! " << bestres << '\n';
}