#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
std::vector<int> v[maxn];
std::vector<int> range[maxn];
std::multimap<int, int> m;
int singer[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		v[i].resize(3);
		std::cin >> v[i][0] >> v[i][1];
		v[i][2] = i;
	}

	std::sort(v, v + n);

	int actors;
	std::cin >> actors;

	for(int i = 0; i < actors; i++){
		range[i].resize(4);
		std::cin >> range[i][0] >> range[i][1] >> range[i][2];
		range[i][3] = i;
	}

	std::sort(range, range + actors);

	int to_add = 0;
	for(int i = 0; i < n; i++){
		std::map<int, int>::iterator find;

		while(to_add < actors and range[to_add][0] <= v[i][0]){
			m.insert({range[to_add][1], to_add});
			to_add++;
		}

		find = m.lower_bound(v[i][1]);

		if(find != m.end()){
			singer[v[i][2]] = range[find->second][3];
			range[find->second][2]--;
			if(range[find->second][2] == 0){
				m.erase(find);
			}
		} else {
			std::cout << "NO\n";
			return 0;
		}
	}

	std::cout << "YES\n";
	for(int i = 0; i < n; i++){
		std::cout << singer[i] + 1 << ' ';
	}
}