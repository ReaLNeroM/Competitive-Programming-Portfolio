#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;
std::vector<int> val[maxn];
int eliminated[maxn];
int n;

void remove_element(int index){
	eliminated[index] = true;
	for(int k = 0; k < n; k++){
		val[k][0] -= val[index][1];
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int start;
	std::cin >> n >> start;

	int accum = 0;
	for(int i = 0; i < n; i++){
		val[i].resize(2);
		std::cin >> val[i][0] >> val[i][1];
		val[i][0] -= start;
		accum += val[i][1];
	}

	if(start + accum < 0){
		std::cout << "NO\n";
		return 0;
	}

	std::fill(eliminated, eliminated + n, false);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!eliminated[j] and val[j][1] >= 0 and val[j][0] <= 0){
				remove_element(j);
			}
		}
	}


	for(int i = 0; i < n; i++){
		int bestFound = -1;
		int bestFoundAngle = -1;
		for(int j = 0; j < n; j++){
			int currAngle = val[j][0] + val[j][1];

			if(!eliminated[j] and val[j][0] <= 0 and (bestFound == -1 or currAngle > bestFoundAngle)){
				bestFound = j;
				bestFoundAngle = val[bestFound][0] + val[bestFound][1];
			}
		}

		if(bestFound == -1){
			break;
		}

		remove_element(bestFound);
	}

	if(!std::find(eliminated, eliminated + n, false)){
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}
