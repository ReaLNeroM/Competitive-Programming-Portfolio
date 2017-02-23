/*
ID: vlade.m1
PROG: contact
LANG: C++
 */
#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("contact.in");
std::ofstream fout("contact.out");

struct results{
	int occurrences, num, digits;

	bool operator<(const results &x) const{
		if(occurrences == x.occurrences){
			if(digits == x.digits){
				return (num < x.num);
			}
			return (digits < x.digits);
		}

		return (occurrences > x.occurrences);
	}
} copy;

int main() {
	int min, max, needed;
	fin >> min >> max >> needed;

	std::string str = "", strcopy;
	while(fin >> strcopy){
		str += strcopy;
	}

	int freq[max + 1][1 << (max + 1)];
	bool used[max + 1][1 << (max + 1)];

	for(int i = 0; i <= max; i++){
		for(int j = 0; j <= 1 << max; j++){
			freq[i][j] = 0;
			used[i][j] = false;
		}
	}
	int process;
	for(int i = 0; i < str.length(); i++){
		process = 0;
		for(int j = i; j >= 0 and i - j < max; j--){
			process *= 2, process += (str[j] == '1');
			if(i - j + 1 >= min){
				freq[i - j + 1][process]++;
			}
		}
	}

	std::vector<results> v;

	for(int i = 0; i < str.length(); i++){
		process = 0;
		for(int j = i; j >= 0 and i - j < max; j--){
			process *= 2, process += (str[j] == '1');
			if(i - j + 1 >= min and !used[i - j + 1][process]){
				copy.digits = i - j + 1;
				copy.num = 0;
				for(int p = 1, iterations = 0; iterations < copy.digits; p *= 2, iterations++){
					copy.num *= 2;
					copy.num += (((process & p) == 0) ? 0 : 1);
				}
				copy.occurrences = freq[i - j + 1][process];

				v.push_back(copy);
				used[i - j + 1][process] = true;
			}
		}
	}

	std::sort(v.begin(), v.end());

	int entered = 0;
	for(int i = 0; i < v.size() and entered < needed;){
		int incr = 0;
		fout << v[i].occurrences << std::endl;
		entered++;
		do{
			incr++;
			int p = 1 << (v[i].digits - 1);

			for(int iterations = 0; iterations < v[i].digits; p /= 2, iterations++){
				fout << (((v[i].num & p) == 0) ? '0' : '1');
			}
			if(v[i].occurrences == v[i + 1].occurrences){
				if(incr == 6){
					fout << std::endl;
					incr = 0;
				} else{
					fout << " ";
				}
			}
			i++;
		} while(i < v.size() and v[i].occurrences == v[i - 1].occurrences);

		fout << std::endl;
	}
	return 0;
}
