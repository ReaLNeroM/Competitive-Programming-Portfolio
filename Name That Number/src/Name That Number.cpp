/*
	ID: vlade.m1
	PROG: namenum
	LANG: C++
 */

#include <fstream>
#include <vector>

struct cont{
	char a, b, c;
};

std::vector<std::string> namer(cont n[],int size) {
	std::ifstream dict;
	dict.open("dict.txt");
	std::string name;
	std::vector<std::string> usable;
	for(int y = 0; y < 4617; y++){
		dict >> name;

		if (name.length() != size){
			continue;
		}
		for(int j = 0; j < size; j++){
			if(name[j] != n[j].a and name[j] != n[j].b and name[j] != n[j].c){
				break;
			}
			if (j == size - 1){
				usable.push_back(name);
			}
		}
	}
	if(usable.empty()){
		usable.push_back("NONE");
	}
	return usable;
}

int main() {
	std::ifstream fin;
	std::ofstream out;
	fin.open("namenum.in");
	out.open("namenum.out");

	std::string num;
	fin >> num;
	cont n[num.length()];

	for (int i = 0; i < num.length(); i++) {
		if(num[i] == '7'){
			n[i].a = 'P', n[i].b = 'R', n[i].c = n[i].b + 1;
		} else if(num[i] == '8'){
			n[i].a = 'T', n[i].b = n[i].a + 1, n[i].c = n[i].b + 1;
		} else if(num[i] == '9'){
			n[i].a = 'W', n[i].b = n[i].a + 1, n[i].c = n[i].b + 1;
		} else{
			n[i].a = 65 + 3 * (num[i] - 50), n[i].b = n[i].a + 1, n[i].c = n[i].b + 1;
		}
	}

	std::vector<std::string> usable = namer(n, num.length());

	for(int i = 0; i < usable.size(); i++){
		out << usable[i] << std::endl;
	}

	return 0;
}
