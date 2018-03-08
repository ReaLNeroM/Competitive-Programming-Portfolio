#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 100;
const int max_logn = 20;
const int INF = 1e9;
int n;
int val[maxn];
int doggie[maxn];
int doggieval[maxn][2];
int sparse[maxn][max_logn];

int log2(int x){
	for(int i = 0; i < max_logn; i++){
		if((1 << i) <= x and (1 << (i + 1)) > x){
			return i;
		}
	}
}

int query(int ql, int qr){
	int maxpow2 = log2(qr - ql + 1);
	return std::max(sparse[ql][maxpow2], sparse[qr - (1 << maxpow2) + 1][maxpow2]);
}

bool cmp(const int& ind_a, const int& ind_b) {
	int (&a)[2] = doggieval[ind_a];
	int (&b)[2] = doggieval[ind_b];

	if(a[0] == b[0] and a[1] == b[1]){
		return false;
	} else if(a[1] < b[0] or b[1] < a[0]){
		return (query(a[0], a[1]) < query(b[0], b[1]));
	} else if(b[0] <= a[0] and a[1] <= b[1]){
		return true;
	} else if(a[0] <= b[0] and b[1] <= a[1]){
		return false;
	} else if(a[0] < b[0]){
		return (query(a[0], b[0] - 1) < query(a[1] + 1, b[1]));
	} else if(b[0] < a[0]){
		return (query(b[1] + 1, a[1]) < query(b[0], a[0] - 1));
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		sparse[i][0] = val[i];
	}

	for(int j = 1, subsize = 1; 2 * subsize <= n; j++, subsize *= 2){
		for(int i = 0; i + 2 * subsize <= n; i++){
			sparse[i][j] = std::max(sparse[i][j - 1], sparse[i + subsize][j - 1]);
		}
	}

	int doggies; //oh hai doggies
	std::cin >> doggies;

	for(int i = 0; i < doggies; i++){
		std::cin >> doggieval[i][0] >> doggieval[i][1];
		doggieval[i][0]--, doggieval[i][1]--;
		doggie[i] = i;
	}

	std::sort(doggie, doggie + doggies, cmp);

	for(int i = 0; i < n; i++){
		std::cout << doggie[i] + 1 << ' ';
	}

	std::cout << '\n';
}
