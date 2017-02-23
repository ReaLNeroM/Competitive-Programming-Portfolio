/*
ID: vlade.m1
PROG: cowtour
LANG: C++
*/

#include <fstream>
#include <vector>
#include <cmath>
#include <functional>
#include <limits>

std::ifstream fin("cowtour.in");
std::ofstream fout("cowtour.out");

struct coord{
	int x, y;
	std::vector<bool> adj;
	int pasture;
};

std::vector<coord> c;
std::vector<std::vector<int> > p;
int pastures = 0;

void flood(int pos){
	if(c[pos].pasture != -1){
		return;
	}

	c[pos].pasture = pastures;
	p[pastures].push_back(pos);

	for(int i = 0; i < c[pos].adj.size(); i++){
		if(c[pos].adj[i]){
			flood(i);
		}
	}
}

double euclidean(coord x, coord y){
	return std::sqrt(std::abs(x.x - y.x) * std::abs(x.x - y.x) + std::abs(x.y - y.y) * std::abs(x.y - y.y));
}

int main() {
	int n;
	fin >> n;

	c.resize(n);
	for(int i = 0; i < n; i++){
		c[i].pasture = -1;
		fin >> c[i].x >> c[i].y;
	}

	double dist[n][n], farthest[n];
	for(int i = 0; i < n; i++){
		farthest[i] = 0;
		for(int j = 0; j < n; j++){
			char next;
			fin >> next;
			if(next == '1'){
				dist[i][j] = euclidean(c[i], c[j]);
			} else {
				dist[i][j] = 500000000;
			}
			c[i].adj.push_back((next == '1'));
		}
		dist[i][i] = 0;
	}

	std::vector<int> empty;
	for(int i = 0; i < n; i++){
		if(c[i].pasture == -1){
			p.push_back(empty);
			flood(i);
			pastures++;
		}
	}

	double pasturefarthest[p.size()];
	for(int i = 0; i < p.size(); i++){
		pasturefarthest[i] = 0;
		for(int j = 0; j < p[i].size(); j++){
			for(int k = 0; k < p[i].size(); k++){
				for(int l = 0; l < p[i].size(); l++){
					if(dist[p[i][k]][p[i][l]] > dist[p[i][k]][p[i][j]] + dist[p[i][j]][p[i][l]]){
						dist[p[i][k]][p[i][l]] = dist[p[i][k]][p[i][j]] + dist[p[i][j]][p[i][l]];
					}
				}
			}
		}
		for(int j = 0; j < p[i].size(); j++){
			for(int k = 0; k < p[i].size(); k++){
				farthest[p[i][j]] = std::max(farthest[p[i][j]], dist[p[i][j]][p[i][k]]);
			}
			pasturefarthest[i] = std::max(pasturefarthest[i], farthest[p[i][j]]);
		}
	}

	double smallest = 500000000;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(c[i].pasture == c[j].pasture){
				continue;
			}

			double diameter = std::max(pasturefarthest[c[i].pasture], pasturefarthest[c[j].pasture]);

			diameter = std::max(diameter, farthest[i] + euclidean(c[i], c[j]) + farthest[j]);

			smallest = std::min(smallest, diameter);
		}
	}

	if(smallest == 500000000){
		smallest = 0;
	}
	fout.precision(6);
	fout << std::fixed << smallest << std::endl;
	return 0;
}
