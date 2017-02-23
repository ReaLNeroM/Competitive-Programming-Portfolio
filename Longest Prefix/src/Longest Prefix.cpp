/*
ID: vlade.m1
PROG: prefix
LANG: C++
 */

#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("prefix.in");
std::ofstream fout("prefix.out");


std::vector<std::string> primitive;
std::vector<int> visited;
std::string str;
int max = 0;

int visit(int pos){
	if(pos >= str.size()){
		return pos;
	}
	if(visited[pos] == 0){
		visited[pos] = pos;
		for(int i = 0; i < primitive.size(); i++){
			if(primitive[i].length() <= str.length() - pos and std::equal(primitive[i].begin(), primitive[i].end(), str.begin() + pos)){
				visited[pos] = std::max(visited[pos], visit(pos + primitive[i].size()));
			}
		}
	}

	return visited[pos];
}
int main() {
	std::string inp = "1";
	fin >> inp;

	do{
		primitive.push_back(inp);
		fin >> inp;
	} while(inp != ".");

	while(fin >> inp){
		str += inp;
		visited.resize(str.length(), 0);
	}

	fout << visit(0) << std::endl;
	return 0;
}
