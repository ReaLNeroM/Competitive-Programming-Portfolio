#include <iostream>
#include <deque>

typedef long long ll;

#define mycomputer true

#ifdef mycomputer
#include <iostream>
#define fin std::cin
#define fout std::cout
#else
#include <fstream>
std::ifstream fin("censor.in");
std::ofstream fout("censor.out");
#endif

int main() {
	std::string str;
	fin >> str;

	std::deque <char> d;
	for (int i = 0; i < str.length(); i++) {
		d.push_back(str[i]);
	}

	fin >> str;
	std::deque <char> c;
	for (int i = 0; i < str.length(); i++) {
		c.push_back(str[i]);
	}

	int pos = 0;
	for (int i = 0; i < d.size(); i++) {
		if(d[i] != c[pos]){
			pos = 0;
		}
		if(d[i] == c[pos]){
			pos++;
			if(pos == c.size()){
				i++;
				d.erase(d.begin() + i - pos, d.begin() + i);
				i = -1;
				pos = 0;
			}
		}
	}

	for (int i = 0; i < d.size(); i++) {
		fout << d[i];
	}
	fout << std::endl;
	return 0;
}
