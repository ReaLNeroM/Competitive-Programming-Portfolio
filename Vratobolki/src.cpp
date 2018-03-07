#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	bool same = true;

	for(int i = 0; i + 1 < n; i++){
		if(s[i] != s[i + 1]){
			same = false;
		}
	}

	if(same){
		std::cout << "0 0\n";
		return 0;
	}

	ll res = 1e18;
	for(int side = 0; side < 2; side++){
		ll attempt = 0;

		std::deque<int> left, right;
		std::deque<int> placeleft;
		std::deque<int> ind;

		int l = std::count(s.begin(), s.end(), 'L');

		int l_pos = 0, r_pos = l - 1;
		for(int i = l; i < n; i++){
			while(l_pos < l and s[l_pos] == 'L'){
				l_pos++;
			}
			while(r_pos >= 0 and s[r_pos] == 'L'){
				r_pos--;
			}

			int l_cost = n - i + l_pos;
			int r_cost = i - r_pos;
			if(l_cost < r_cost){
				attemt += l_cost;
				left.push_front(i);
				placeleft.push_front(l_pos);
				ind.push_front(0);
				l_pos++;
			} else {
				attemt += r_cost;
				right.push_back(i);
				r_pos++;
			}
		}

		for(int start = 0; start + l < n; start++){
			res = std::min(res, attempt);

			if(s[start] == 'L'){
				left.push_front(start);
				placeleft.push_front()
			}

			attempt += left.size();
			attempt -= right.size();
			if(s[start + l] == 'L'){
				right.pop_front();
			}

			while(!left.empty()){
				int get = left.back();
				int place = placeleft;
				if(place > n - place){
					right.push_back(get);
					left.pop_front();
					attempt -= place - (n - place);
				} else {
					break;
				}
			}
		}

		res = std::min(res, attempt);
		
		for(char& i : s){
			if(i == 'L'){
				i = 'R';
			} else if(i == 'R'){
				i = 'L';
			}
		}
	}

	std::cout << 1 << ' ' << res << '\n';
}