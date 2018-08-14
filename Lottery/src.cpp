#include <bits/stdc++.h>

const int maxn = 1e4 + 100;
const int maxk = 1e2 + 10;
const int mod = 1e9 + 7;
int val[maxn];
int res[maxn];
int query[maxk];
int sortedquery[maxk];
static int m[maxn][maxk];

int main(){
	std::ios::sync_with_stdio(false);
	
	int n, l;
	std::cin >> n >> l;
	
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	int q;
	std::cin >> q;

	for(int i = 0; i < q; i++){
		std::cin >> query[i];
		sortedquery[i] = query[i];
	}

	std::sort(sortedquery, sortedquery + q);

	for(int diff = 1; diff + l <= n; diff++){
		int differences = 0;
		for(int j = 0; j < l; j++){
			differences += (val[j] != val[j + diff]);
		}

		for(int j = l; j + diff <= n; j++){
			int li = 0, r = q - 1;
			int best = q;

			while(li <= r){
				int mid = (li + r) / 2;

				if(differences <= sortedquery[mid]){
					best = mid;
					r = mid - 1;
				} else {
					li = mid + 1;
				}
			}
			
			m[j - l][best]++;
			m[j + diff - l][best]++;

			differences -= (val[j - l] != val[j + diff - l]);
			differences += (val[j] != val[j + diff]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < q; j++){
			m[i][j + 1] += m[i][j];
		}
	}
	
	for(int i = 0; i < q; i++){
		for(int j = 0; j + l <= n; j++){
			int li = 0, r = q - 1;
			while(li <= r){
				int mid = (li + r) / 2;
				
				if(sortedquery[mid] == query[i]){
					std::cout << m[j][mid] << ' ';
					break;
				} else if(sortedquery[mid] > query[i]){
					r = mid - 1;
				} else {
					li = mid + 1;
				}
			}
		}

		std::cout << '\n';
	}
}
