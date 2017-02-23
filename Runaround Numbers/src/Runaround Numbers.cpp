/*
ID: vlade.m1
PROG: runround
LANG: C++
 */
#include <fstream>

std::ifstream fin("runround.in");
std::ofstream fout("runround.out");

bool check(std::string &str){
	bool used[str.length()];
	for(int i = 0; i < str.length(); i++){
		used[i] = false;
	}

	int pos = 0, visited = 0;
	for(int i = 0; i < str.length(); i++){
		if(used[pos]){
			break;
		}
		visited++;
		used[pos] = true;
		pos = (pos + str[pos] - '0') % str.length();
	}

	return (visited == str.length() and pos == 0);
}

std::string smallest, biggerthan;

void gen(int used[], int pos, std::string &str){
	if(pos == biggerthan.length()){
		if(check(str) and str > biggerthan and smallest > str){
			smallest = str;
		}

		return;
	}
	for(int i = 1; i < 10; i++){
		if(!used[i]){
			str += '0' + i;
			used[i] = true;
			gen(used, pos + 1, str);
			if(pos == 0){
				fout << "YES";
			}
 			used[i] = false;
			str.erase(str.begin() + str.length() - 1);
		}
	}
}

int main() {
	fin >> biggerthan;

	int used[10];

	for(int i = 0; i < 10; i++){
		used[i] = 0;
	}

	std::string start = "";

	for(int i = 0; i < biggerthan.length(); i++){
		smallest.push_back('9');
	}

	gen(used, 0, start);

	fout << smallest << std::endl;
	return 0;
}
