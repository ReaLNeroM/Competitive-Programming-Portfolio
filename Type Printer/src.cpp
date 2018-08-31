#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3e4 + 1e2;
std::string val[maxn];
std::map<std::vector<int>, int> important;

std::pair<int, int> dfs(int pos, int a, int b){
	std::pair<int, int> response = {1e9, 0};

	std::vector<std::pair<int, int>> v(27);

	if(val[a].size() == pos){
		v[26] = {1, 1};
	}

	for(int i = 0; i < 26; i++){
		char s = 'a' + i;

		int l = a, r = b;
		int smallest = b + 1;
		int biggest = a - 1;
		while(l <= r){
			int mid = (l + r) / 2;

			if(val[mid].size() == pos){
				l = mid + 1;
			} else if(val[mid][pos] == s){
				smallest = std::min(smallest, mid);
				r = mid - 1;
			} else if(val[mid][pos] < s){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		l = a, r = b;
		while(l <= r){
			int mid = (l + r) / 2;

			if(val[mid].size() == pos){
				l = mid + 1;
			} else if(val[mid][pos] == s){
				biggest = std::max(biggest, mid);
				l = mid + 1;
			} else if(val[mid][pos] < s){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		if(smallest > biggest){
			v[i] = {0, 0};
		} else {
			v[i] = dfs(pos + 1, smallest, biggest);
			v[i].first += 1;
			v[i].second += 2;
		}
	}

	int sum = 0;
	for(int i = 0; i < 27; i++){
		sum += v[i].second;
	}
	response.second = sum;

	important[{a, b, pos}] = -1;
	for(int i = 0; i < 26; i++){
		if(response.first > sum - v[i].second + v[i].first){
			response.first = sum - v[i].second + v[i].first;
			important[{a, b, pos}] = i;
		}
	}

	return response;
}

void back(int pos, int a, int b, bool care){
	int cacheForLater = important[{a, b, pos}];
	std::pair<int, int> asklater = {-1, -1};

	if(val[a].size() == pos){
		std::cout << "P\n";
	}

	for(int i = 0; i < 26; i++){
		char s = 'a' + i;

		int l = a, r = b;
		int smallest = b + 1;
		int biggest = a - 1;
		while(l <= r){
			int mid = (l + r) / 2;

			if(val[mid].size() == pos){
				l = mid + 1;
			} else if(val[mid][pos] == s){
				smallest = std::min(smallest, mid);
				r = mid - 1;
			} else if(val[mid][pos] < s){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		l = a, r = b;
		while(l <= r){
			int mid = (l + r) / 2;

			if(val[mid].size() == pos){
				l = mid + 1;
			} else if(val[mid][pos] == s){
				biggest = std::max(biggest, mid);
				l = mid + 1;
			} else if(val[mid][pos] < s){
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		if(smallest > biggest){
			continue;
		} else if(cacheForLater != i or !care){
			std::cout << s << '\n';
			back(pos + 1, smallest, biggest, false);
			std::cout << '-' << '\n';
		} else {
			asklater = {smallest, biggest};
		}
	}

	if(asklater != std::pair<int, int>{-1, -1}){
		std::cout << (char) ('a' + cacheForLater) << '\n';
		back(pos + 1, asklater.first, asklater.second, true);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::sort(val, val + n);

	std::cout << dfs(0, 0, n - 1).first << '\n';
	back(0, 0, n - 1, true);
}
