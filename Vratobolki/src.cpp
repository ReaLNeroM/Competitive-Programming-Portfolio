#include <bits/stdc++.h>

typedef long long ll;

int n;

bool within(int a, int l, int r){
	return l <= a and a <= r;
}

int dist(int a, int b){
	if(a > b){
		std::swap(a, b);
	}

	return std::min(b - a, a + n - b);
}

int main(){
	std::ios::sync_with_stdio(false);

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

		int l = std::count(s.begin(), s.end(), 'L');

		int l_pos = 0, r_pos = l - 1;
		for(int i = l; i < n; i++){
			while(l_pos < r_pos and s[l_pos] == 'L'){
				left.push_back(l_pos);
				l_pos++;
			}
			while(l_pos < r_pos and s[r_pos] == 'L'){
				right.push_front(r_pos);
				r_pos--;
			}

			if(s[i] == 'L'){
				int l_cost = n - i + l_pos;
				int r_cost = i - r_pos;
				if(l_cost < r_cost){
					attempt += l_cost;
					left.push_front(i);
					l_pos++;
				} else {
					attempt += r_cost;
					right.push_back(i);
					r_pos--;
				}
			}
		}

		for(int start = 0; start + l < n; start++){
			res = std::min(res, attempt);

			attempt += left.size();
			attempt -= right.size();
			l_pos++, r_pos++;
			while6  (!left.empty() and !right.empty() and within(*left.rbegin(), start, start + l)
												   and within(*right.begin(), start, start + l)
												   and *left.rbegin() - (l_pos - 1) + r_pos + 1 - *right.begin() > 
													   (*left.rbegin(), r_pos + 1) + dist(*right.begin(), l_pos - 1)){
				attempt -= dist(*left.rbegin(), l_pos - 1) 
						 + dist(*right.begin(), r_pos + 1) 
						 - dist(*left.rbegin(), r_pos + 1) 
						 - dist(*right.begin(), l_pos - 1);
				std::swap(*left.rbegin(), *right.begin());
			}

			while(!left.empty() and dist(*left.begin(), l_pos - 1) > dist(*left.begin(), r_pos)){
				right.push_back(*left.begin());
				left.pop_front();
				attempt -= dist(*left.begin(), l_pos - 1) - dist(*left.begin(), r_pos);
				r_pos--;
				l_pos--;
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
