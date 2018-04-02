#include <iostream>
#include <deque>
#include <queue>

const int maxn = 150;
int in[maxn];
int out[maxn];
int tagged[maxn];
std::deque<int> bi_e[maxn];
int vertices, edges;

int get_nonzero_components(){
	std::fill(tagged, tagged + vertices, false);

	int nonzero_components = 0;

	for(int i = 0; i < vertices; i++){
		if(!tagged[i] and !bi_e[i].empty()){
			nonzero_components++;

			std::queue<int> q;

			q.push(i);
			tagged[i] = true;
			
			while(!q.empty()){
				int fr = q.front();
				q.pop();

				for(int next : bi_e[fr]){
					if(!tagged[next]){
						q.push(next);
						tagged[next] = true;
					}
				}
			}
		}
	}

	return nonzero_components;
}

int main() {
	int t;
	std::cin >> t;

	for(int test_case = 1; test_case <= t; test_case++){
		std::cin >> vertices >> edges;

		std::fill(in, in + vertices, 0);
		std::fill(out, out + vertices, 0);
		std::fill(tagged, tagged + vertices, 0);
		for(int i = 0; i < vertices; i++){
			bi_e[i].clear();
		}

		for(int i = 0, first, second; i < edges; i++){
			std::cin >> first >> second;

			bi_e[first - 1].push_back(second - 1);
			bi_e[second - 1].push_back(first - 1);

			out[first - 1]++;
			in[second - 1]++;
		}

		int nonzero_components = get_nonzero_components();

		bool one_check = false;

		bool one_problem_encountered = false;
		int one_more_in = 0;
		int one_more_out = 0;

		for(int i = 0; i < vertices; i++){
			if(in[i] == out[i] + 1){
				one_more_in++;
			} else if(in[i] == out[i] - 1){
				one_more_out++;
			} else if(in[i] != out[i]){
				one_problem_encountered = true;
			}
		}

		if(one_more_in <= 1 and one_more_out <= 1 and !one_problem_encountered and nonzero_components == 1){
			one_check = true;
		}

		int bi_check = false;

		int bi_odd_degree = 0;
		for(int i = 0; i < vertices; i++){
			if(bi_e[i].size() % 2 == 1){
				bi_odd_degree++;
			}
		}

		if((bi_odd_degree == 0 or bi_odd_degree == 2) and nonzero_components == 1){
			bi_check = true;
		}

		if(one_check){
			std::cout << "YES\n";
		} else if(bi_check){
			std::cout << "TRAFFIC STOPPING NEEDED\n";
		} else {
			std::cout << "WAKE UP EARLIER\n";
		}
	}

	return 0;
}
