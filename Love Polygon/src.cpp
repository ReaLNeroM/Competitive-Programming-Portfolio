#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 1e2;
int in[maxn]; //indegree
int out[maxn];
bool tag[maxn]; //visited
bool tag2[maxn];//part of an odd cycle AND not contributed to a free node
std::map<std::string, int> m;
std::vector<int> innodes[maxn];
int res = 0;

int id(std::string &x){
	int &return_value = m[x];

	if(return_value == 0){
		return_value = (int) m.size();
	}

	return return_value - 1;
}
void fill(int pos, int value){
	std::queue<int> q;

	if(tag2[pos] != value){
		tag2[pos] = value;
		q.push(pos);
	}

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		int next = out[fr];

		if(tag2[next] != value){
			tag2[next] = value;
			q.push(next);
		}

		for(int i : innodes[fr]){
			if(tag2[i] != value){
				tag2[i] = value;
				q.push(i);
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::string s_a, s_b;
		std::cin >> s_a >> s_b;

		int a = id(s_a), b = id(s_b);

		out[a] = b;
		in[b]++;
		innodes[b].push_back(a);
	}

	int free_nodes = 0;

	for(int i = 0; i < n; i++){
		if(in[i] == 1 and out[i] == i){
			tag[i] = true;
			free_nodes++;
		}
	}

	for(int i = 0; i < n; i++){
		if(in[i] == 0 and !tag[i]){
			int pos = i;
			int full_length = 0;

			while(!tag[pos]){
				tag[pos] = true;
				full_length++;

				pos = out[pos];
			}

			int pos2 = i;
			int pre_cycle = 0;

			while(pos2 != pos){
				pre_cycle++;

				pos2 = out[pos2];
			}

			int cycle_length = full_length - pre_cycle;

			if(cycle_length % 2 == 1){
				fill(pos, 1);
			}

			res += pre_cycle / 2;
			if(pre_cycle % 2 != 0){
				if(tag2[pos] == 1){
					fill(pos, 0);
					res += 1;
				} else {
					free_nodes++;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(tag2[i]){
			free_nodes++;
			fill(i, 0);
		}
	}

	for(int i = 0; i < n; i++){
		if(!tag[i]){
			//lone cycle, just see how long it is

			int pos = i;
			int length = 0;

			while(!tag[pos]){
				tag[pos] = true;
				length++;

				pos = out[pos];
			}

			res += length / 2;
			if(length % 2 == 1){
				free_nodes++;
			}
		}
	}

	res += free_nodes; // always even

	std::cout << res << '\n';
}
