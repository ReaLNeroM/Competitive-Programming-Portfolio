#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 100005;
int loc[maxn];
int val[maxn];
int used[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		loc[i] = i;
	}

	std::sort(loc, loc + n, [](int a, int b) {return val[a] < val[b];});

	int pos = -1;
	int res = 0;

	std::vector<std::vector<int>> v;

	for(int i = 0; i < n; i++){
		if(!used[i]){
			res++;
			std::vector<int> temp;
			pos = i;

			do {
				temp.push_back(pos + 1);
				used[pos] = true;
				pos = loc[pos];
				used[pos] = true;
			} while(pos != i);

			v.push_back(temp);
		}
	}

	std::cout << res << '\n';

	for(int i = 0; i < v.size(); i++){
		std::cout << v[i].size() << ' ';
		for(int j : v[i]){
			std::cout << j << ' ';
		}
		std::cout << '\n';
	}
}