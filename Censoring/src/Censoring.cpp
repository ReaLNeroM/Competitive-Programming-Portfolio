#include <fstream>
#include <list>

int main() {
	std::list<char> l;
	std::ifstream fin;
	std::ofstream fout;
	fin.open("censor.in");
	fout.open("censor.out");

	std::string full, cen;
	fin >> full >> cen;


	for (int i = 0; i < full.length(); i++) {
		l.push_back(full[i]);
	}

	std::list<char>::iterator il = l.begin();
	while (il != l.end()) {
		std::list<char>::iterator copy = il;
		int curr = 0;

		while (*copy == cen[curr]) {
			copy++, curr++;
			if (curr == cen.length()) {
				l.erase(il, copy);
				il = l.begin();
				break;
			}
		}

		il++;
	}

	il = l.begin();
	while (il != l.end()) {
		fout << *il;
		il++;
	}

	fout << std::endl;
	return 0;
}
