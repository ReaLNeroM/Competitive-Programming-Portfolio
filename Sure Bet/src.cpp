#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
double v[2][maxn];

int main(){
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n; i++){
		std::cin >> v[0][i] >> v[1][i];
	}
	
	std::sort(&(v[0][0]), &(v[0][0]) + n, std::greater<double>());
	std::sort(&(v[1][0]), &(v[1][0]) + n, std::greater<double>());
	
	double res = 0;
	double a = 0.0, b = 0.0;
	int l = 0, r = 0;
	
	while(l != n or r != n){
		if(l != n and (r == n or a <= b)){
			a += v[0][l];
			l++;
		} else if(r != n){
			b += v[1][r];
			r++;
		}
		
		res = std::max(res, std::min(a - (l + r), b - (l + r)));
	}
	
	std::cout.precision(4);
	std::cout << std::fixed << res << std::endl;
}