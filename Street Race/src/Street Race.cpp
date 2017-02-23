/*
 ID: vlade.m1
 PROG: race3
 LANG: C++
*/

//#define mycomputer true

#ifdef mycomputer
#include <iostream>
#define fin std::cin
#define fout std::cout
#else
#include <fstream>
std::ifstream fin("race3.in");
std::ofstream fout("race3.out");
#endif

#include <vector>
#include <queue>

typedef long long ll;

const int maxv = 51;

int main() {
	std::vector<int> adj[maxv];

	int inp, vertices = 0;
	while(fin >> inp){
		if(inp == -1){
			break;
		} else if (inp == -2){
			vertices++;
		} else {
			adj[vertices].push_back(inp);
		}
	}

	std::vector<int> must, split;
	for(int i = 1; i < vertices - 1; i++){
		bool used[vertices];
		for(int j = 0; j < vertices; j++){
			used[j] = false;
		}
		used[i] = true;

		std::queue<int> q;
		q.push(0);
		used[0] = true;

		while(!q.empty()){
			int fr = q.front();
			q.pop();

			for(int j = 0; j < adj[fr].size(); j++){
				if(!used[adj[fr][j]]){
					used[adj[fr][j]] = true;
					q.push(adj[fr][j]);
				}
			}
		}

		if(!used[vertices - 1]){
			must.push_back(i);
		}

		int color[vertices]; // 1 - first day, 2 - second day
		for(int j = 0; j < vertices; j++){
			color[j] = 0;
		}

		q.push(i);
		color[i] = 1;

		while(!q.empty()){
			int fr = q.front();
			q.pop();

			for(int j = 0; j < adj[fr].size(); j++){
				if(!color[adj[fr][j]]){
					color[adj[fr][j]] = 2;
					q.push(adj[fr][j]);
				}
			}
		}

		bool problem = false;
		if(color[0]){
			problem = true;
		}

		q.push(0);
		color[0] = 1;
		while(!q.empty()){
			int fr = q.front();
			q.pop();

			for(int j = 0; j < adj[fr].size(); j++){
				if(color[adj[fr][j]] == 2){
					problem = true;
				} else if(color[adj[fr][j]] == 0){
					color[adj[fr][j]] = 1;
					q.push(adj[fr][j]);
				}
			}
		}

		if(!problem){
			split.push_back(i);
		}
	}

	fout << must.size();
	if(must.size() >= 1){
		fout << ' ';
		for(int i = 0; i < must.size(); i++){
			fout << must[i];
			if(i != must.size() - 1){
				fout << ' ';
			}
		}
	}
	fout << std::endl;

	fout << split.size();
	if(split.size() >= 1){
		fout << ' ';
		for(int i = 0; i < split.size(); i++){
			fout << split[i];
			if(i != split.size() - 1){
				fout << ' ';
			}
		}
	}
	fout << std::endl;
	return 0;
}
