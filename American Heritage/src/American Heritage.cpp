/*
ID: vlade.m1
PROG: heritage
LANG: C++
 */

#define mycomputer aeiunafweafsenawfenfdn

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("heritage.in");
	std::ofstream fout("heritage.out");
#endif

std::string inorder, preorder;

void print(int instart, int prestart, int length){
	for(int i = 0; i < length; i++){
		if(inorder[instart + i] == preorder[prestart]){
			print(instart, prestart + 1, i);
			print(instart + i + 1, prestart + i + 1, length - i - 1);
			fout << preorder[prestart];
			break;
		}
	}
}

int main() {
	fin >> inorder >> preorder;

	print(0, 0, inorder.length());

	fout << std::endl;
	return 0;
}
