#include <bits/stdc++.h>

typedef long long ll;

std::vector<std::pair<int, int>> res;

std::string best_a, best_b;
int best_score = 1e9;
int best_cut = -1;

int count_regions(std::string& s){
	int regions = 1;

	for(int i = 1; i < s.size(); i++){
		if(s[i - 1] != s[i]){
			regions++;
		}
	}

	return regions;
}

int score(std::string& a, std::string& b){
	int a_r = count_regions(a);
	int b_r = count_regions(b);

	return std::max(a_r, b_r) - ((int) (a[0] != b[0] or a_r != b_r));
}

void even_out_regions(std::string& a, std::string& b, int a_regions, int b_regions, bool swap){
	int a_pos = 0;
	for(int take = 1; a_pos < a.size(); take++){
		while(a_pos < a.size() - 1 and a[a_pos] == a[a_pos + 1]){
			a_pos++;
		}

		int primary = b_regions + take - (a[a_pos] == b[0]);
		int other = a_regions - take;
		if(std::abs(other - primary) <= 1){
			std::string temp_a = a.substr(a_pos + 1, a.size() - a_pos);
			std::string temp_b = a.substr(0, a_pos + 1) + b;

			int temp_score = score(temp_a, temp_b) + 1;
			if(best_score >= temp_score){
				best_a = temp_a;
				best_b = temp_b;
				best_score = temp_score;
				best_cut = a_pos + 1;
			}
		}

		a_pos++;
	}

	if(best_cut != -1){
		if(swap){
			res.push_back({0, best_cut});
		} else {
			res.push_back({best_cut, 0});
		}
	}
}

void make_alternating(std::string& a, std::string& b, bool swap){
	int a_pos = 0;
	while(a_pos < a.size() - 1 and a[a_pos] == a[a_pos + 1]){
		a_pos++;
	}

	b = a.substr(0, a_pos + 1) + b;
	a = a.substr(a_pos + 1, a.size() - a_pos);

	if(swap){
		res.push_back({0, a_pos + 1});
	} else {
		res.push_back({a_pos + 1, 0});
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::string a, b;
	std::cin >> a >> b;

	int a_regions = count_regions(a);
	int b_regions = count_regions(b);

	best_a = a;
	best_b = b;

	if(a_regions >= b_regions + 2){
		even_out_regions(a, b, a_regions, b_regions, false);
	} else if(b_regions >= a_regions + 2){
		even_out_regions(b, a, b_regions, a_regions, true);
		std::swap(best_a, best_b);
	}

	a = best_a;
	b = best_b;

	a_regions = count_regions(a);
	b_regions = count_regions(b);

	if(a[0] == b[0]){
		if(a_regions >= b_regions){
			make_alternating(a, b, false);
		} else {
			make_alternating(b, a, true);
		}
	}

	a_regions = count_regions(a);
	b_regions = count_regions(b);

	int a_size = 0;
	int b_size = 0;
	int a_pos = 0;
	int b_pos = 0;

	for(int i = 0; i + 1 < a_regions or i + 1 < b_regions; i++){
		while(a_pos < a.size() - 1 and a[a_pos] == a[a_pos + 1]){
			a_pos++;
			a_size++;
		}
		while(b_pos < b.size() - 1 and b[b_pos] == b[b_pos + 1]){
			b_pos++;
			b_size++;
		}

		a_pos++;
		b_pos++;
		a_size++;
		b_size++;
		res.push_back({a_size, b_size});
		std::swap(a_size, b_size);
	}

	std::cout << res.size() << '\n';
	for(auto i : res){
		std::cout << i.first << ' ' << i.second << '\n';
	}
}
