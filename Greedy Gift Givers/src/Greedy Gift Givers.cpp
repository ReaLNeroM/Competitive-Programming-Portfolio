/*
 ID: vlade.m1
 PROG: friday
 LANG: C++
 */
#include <fstream>
#include <map>

int main() {
	std::ifstream inp;
	std::ofstream out;
	inp.open("gift1.in");
	out.open("gift1.out");
	int korisnici;
	inp >> korisnici;
	std::map<std::string, int> luge;
	std::string iminja[korisnici];
	for (int i = 0; i < korisnici; i++) {
		inp >> iminja[i];
		luge[iminja[i]] = 0;
	}

	for (int i = 0; i < korisnici; i++) {
		std::string ime;
		int pari, lugesodava;
		inp >> ime >> pari >> lugesodava;

		if(lugesodava == 0){
			continue;
		}
		luge[ime] += pari % lugesodava, luge[ime] -= pari, pari -= pari % lugesodava;
		if(pari == 0){
			continue;
		}
		pari /= lugesodava;

		for (int j = 0; j < lugesodava; j++) {
			inp >> ime;
			luge[ime] += pari;
		}
	}

	for (int i = 0; i < korisnici; i++) {
		out << iminja[i] << " " << luge[iminja[i]] << std::endl;
	}
	return 0;
}

