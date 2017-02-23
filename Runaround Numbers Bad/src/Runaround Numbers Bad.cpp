/*
ID: vlade.m1
PROG: runround
LANG: C++
 */
#include <fstream>

std::ifstream fin("runround.in");
std::ofstream fout("runround.out");

bool check(std::string &str){
	bool used[str.length()], occurrences[10];
	for(int i = 0; i < str.length(); i++){
		used[i] = false;
	}

	for(int i = 0; i < 10; i++){
		occurrences[i] = false;
	}

	int pos = 0, visited = 0;
	for(int i = 0; i < str.length(); i++){
		if(used[pos] or occurrences[str[i] - '0'] or occurrences[0] != 0){
			break;
		}
		visited++;
		used[pos] = true;
		occurrences[str[i] - '0'] = true;
		pos = (pos + str[pos] - '0') % str.length();
	}

	return (visited == str.length() and pos == 0);
}

std::string smallest, biggerthan;

int main() {
	std::string str;
	fin >> str;

	int carry;
	do{
		carry = 1;
		for(int i = str.length() - 1; i >= 0; i--){
			if(str[i] + carry > '9'){
				str[i] = '0';
			} else if (carry == 1) {
				str[i]++;
				carry = 0;
				break;
			}
		}

		if(str[0] == '0'){
			str.insert(str.begin(), '1');
		}
	} while(!check(str));

	fout << str << std::endl;
	return 0;
}
