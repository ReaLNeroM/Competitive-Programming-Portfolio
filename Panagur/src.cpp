#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
const int maxk = 50;
std::set<std::vector<int>> m;
std::multiset<int> optimals;
std::set<int> above[maxk], below[maxk];
std::pair<int, int> left[maxk], right[maxk];
int found[maxk];
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n, k, q;
	std::cin >> n >> k >> q;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		val[i]--;
		below[val[i]].insert(-i);
		above[val[i]].insert(i);
	}

	std::deque<std::vector<int>> index(k);
	for(int i = 0; i < k; i++){
		index[i] = {-1, i};
	}

	int fulfilled = 0;
	int l = 0;

	for(int i = 0; i < n; i++){
		if(index[val[i]][0] == -1){
			fulfilled++;
		}

		index[val[i]][0] = std::max(index[val[i]][0], i);

		while(l < i and index[val[l]][0] != l){
			l++;
		}

		if(fulfilled == k){
			if(m.empty() or (*(--m.end()))[1] != l){
				optimals.insert(i - l + 1);
				m.insert({i, l});
			}
		}
	}

	for(int query = 0; query < q; query++){
		int type;
		std::cin >> type;

		if(type == 1){
			int ind, value;
			std::cin >> ind >> value;
			ind--, value--;

			auto ite = m.lower_bound({ind, 0});
			while(ite != m.end() and (*ite)[1] <= ind){
				auto sec = optimals.find((*ite)[0] - (*ite)[1] + 1);
				optimals.erase(sec);

				auto sec_ite = ite;
				ite++;
				m.erase(sec_ite);
			}

			below[val[ind]].erase(-ind);
			above[val[ind]].erase(ind);
			val[ind] = value;
			below[val[ind]].insert(-ind);
			above[val[ind]].insert(ind);

			std::fill(left, left + k, std::pair<int, int>{n, n});
			std::fill(right, right + k, std::pair<int, int>{n, n});
			int left_size = 0, right_size = 0;

			for(int i = 0; i < k; i++){
				auto ite = below[i].lower_bound(-ind);
				auto sec = above[i].lower_bound(ind);

				if(ite != below[i].end()){
					left[i] = {-(*ite), i};
					left_size++;
				}
				if(sec != above[i].end()){
					right[i] = {*sec, i};
					right_size++;
				}
			}

			std::sort(left, left + k);
			std::sort(right, right + k);

			std::fill(found, found + k, -1);
			int fulfilled = 0;
			int r_position = 0;

			for(int i = 0; i < left_size; i++){
				if(found[left[i].second] == -1){
					fulfilled++;
				}

				found[left[i].second] = std::max(found[left[i].second], left[i].first);
			}

			for(int i = 0; i < left_size; i++){
				while(fulfilled < k and r_position + 1 < right_size){
					r_position++;

					if(found[right[r_position].second] == -1){
						fulfilled++;
					}
					found[right[r_position].second] = std::max(found[right[r_position].second], right[r_position].first);
				}
				while(fulfilled == k and found[left[i].second] != left[i].first){
					i++;
				}

				if(fulfilled == k){
					m.insert({right[r_position].first, left[i].first});
					optimals.insert(right[r_position].first - left[i].first + 1);
				}

				if(found[left[i].second] == left[i].first){
					found[left[i].second] = -1;
					fulfilled--;
				}
			}
		} else {
			if(optimals.empty()){
				std::cout << -1 << '\n';
			} else {
				std::cout << *optimals.begin() << '\n';
			}
		}
	}
}
