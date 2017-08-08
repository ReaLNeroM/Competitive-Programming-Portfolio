#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int rem[maxn];
std::map<int, int> m;
std::set<int> s;

int main(){
	std::ios::sync_with_stdio(false);

	int n, k;
	std::cin >> n >> k;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < k; i++){
		std::cin >> rem[i];
		m[rem[i]] = 1;
	}

	int curr = 2;

	int sum = 0;

	for(int i = 0; i < n; i++){
		sum += val[i];
		int togo = rem[0] - sum;

		if(s.find(togo) == s.end()){
			int currtogo = togo;
			int found = 0;

			for(int j = 0; j < n; j++){
				currtogo += val[j];
				auto ite = m.find(currtogo);
				if(ite != m.end()){
					int get = ite->second;
					if(get != curr){
						found++;
						m[currtogo] = curr;
					}
				}
			}

			if(found == k){
				s.insert(togo);
			}
		}

		curr++;
	}

	std::cout << s.size();
}