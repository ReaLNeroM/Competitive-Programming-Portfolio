#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 10;
const ll maxbit = (1 << 17);
const ll INF = 1000000000000000010;
int xback[maxn];
int yback[maxn];
int xon[maxn];
int yon[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){

		memset(yon, 0, sizeof(yon));
		memset(xon, 0, sizeof(xon));
		memset(yback, 0, sizeof(yback));
		memset(xback, 0, sizeof(xback));
		int p, q;
		std::cin >> p >> q;

		int xmin = 0, ymin = 0;
		int xmax = q, ymax = q;

		for(int i = 0; i < p; i++){
			int xloc, yloc;
			char dir;
			std::cin >> xloc >> yloc >> dir;

			if(dir == 'N'){
				yon[yloc + 1]++;
			} else if(dir == 'S'){
				yback[yloc - 1]++;
			} else if(dir == 'W'){
				xback[xloc - 1]++;
			} else if(dir == 'E'){
				xon[xloc + 1]++;
			}
		}

		for(int i = 0; i < q; i++){
			xon[i + 1] += xon[i];
			yon[i + 1] += yon[i];
		}
		for(int i = q; i > 0; i--){
			xback[i - 1] += xback[i];
			yback[i - 1] += yback[i];
		}
		int xbest = 0, ybest = 0;

		for(int i = 0; i <= q; i++){
			if(xon[i] + xback[i] > xon[xbest] + xback[xbest]){
				xbest = i;
			}
			if(yon[i] + yback[i] > yon[ybest] + yback[ybest]){
				ybest = i;
			}
		}

		std::cout << "Case #" << testcase << ": " << xbest << ' ' << ybest;

		std::cout << '\n';
	}
}

