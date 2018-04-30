#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int INF = 1e9;
int val[maxn][2];

std::multiset<std::pair<int, int>> s;
std::map<int, int> entries;
std::multiset<int> pq;

void update(int a, int b){
	auto ite = pq.find(a);
	if(ite != pq.end()){
		pq.erase(ite);
	}

	pq.insert(b);
}

int main(){
	std::ios::sync_with_stdio(false);

	int tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		int signs;
		std::cin >> signs;

		s.clear();
		entries.clear();
		pq.clear();

		for(int i = 0; i < signs; i++){
			int a, b, c;
			std::cin >> a >> b >> c;

			val[i][0] = a + b;
			val[i][1] = a - c;

			std::cerr << val[i][0] << ' ' << val[i][1] << '\n';

			if(val[i][0] == val[i][1]){
				entries[val[i][0]]++;
				update(entries[val[i][0]] - 1, entries[val[i][0]]);
			} else {
				s.insert({val[i][0], val[i][1]});
				entries[val[i][0]]++;
				update(entries[val[i][0]] - 1, entries[val[i][0]]);
				
				s.insert({val[i][1], val[i][0]});
				entries[val[i][1]]++;
				update(entries[val[i][1]] - 1, entries[val[i][1]]);
			}
		}
		std::cerr << '\n';

		int res = 0;

		for(auto ite = s.begin(); ite != s.end(); ){
			int point1 = ite->first;
			int attempt = entries[ite->first];

			std::vector<std::pair<int, int>> deleted;

			while(ite != s.end() and ite->first == point1){
				std::pair<int, int> to_delete = *ite;

				s.erase(ite);
				entries[to_delete.first]--;
				update(entries[to_delete.first] + 1, entries[to_delete.first]);
				deleted.push_back(to_delete);

				std::swap(to_delete.first, to_delete.second);

				s.erase(s.find(to_delete));
				entries[to_delete.first]--;
				update(entries[to_delete.first] + 1, entries[to_delete.first]);
				deleted.push_back(to_delete);

				ite = s.lower_bound({point1, -INF});
			}

			attempt += *pq.rbegin();

			for(int i = 0; i < deleted.size(); i++){
				s.insert(deleted[i]);
				entries[deleted[i].first]++;
				update(entries[deleted[i].first] - 1, entries[deleted[i].first]);
			}

			res = std::max(res, attempt);
			ite = s.lower_bound({point1 + 1, -INF});
		}

		std::cout << "Case #" << test << ": " << res << '\n';
	}
}
