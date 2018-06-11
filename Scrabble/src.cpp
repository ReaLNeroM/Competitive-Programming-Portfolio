#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

std::string wordlist_file = "wordlist.txt";
const char bucket_chars[] = {'e', 't', 'a'};
const int alpha = 26;
const int buckets = 3;

class Dictionary {
	int dict_size = 0;

	std::vector<char> key;
	std::vector<std::vector<int>> v;

public:
	Dictionary(int buckets, const char bucket_chars[]){
		int size = sizeof(bucket_chars) / sizeof(bucket_chars[0]);
		key.resize(size);

		for(int i = 0; i < size; i++){
			key[i] = bucket_chars[i];
		}
	}

	void add(std::string str){
		dict_size++;

	}

	std::string query(int b[]){
		
	}
};


std::string convert(std::string str){
	for(char& i : str){
		if('A' <= i and i <= 'Z'){
			i += 'a' - 'A'; // 97 - 65
		} else if(i < 'a' or 'z' < i){
			std::cerr << "ERROR: ILLEGAL CHARACTER" << '\n';
			exit(-1);
		}
	}

	return str;
}

int main(){
	std::ifstream word_stream;

	word_stream.open(wordlist_file.c_str());

	if(!word_stream.good()){
		std::cerr << "ERROR: WORDLIST NOT FOUND OR EMPTY" << '\n';
		return -1;
	}

	Dictionary dict(buckets, bucket_chars);
	std::string str;
	while(word_stream >> str){
		dict.add(convert(str));
	}

	int q;
	std::cin >> q;

	for(int i = 0; i < q; i++){
		std::string s;
		std::cin >> s;

		s = convert(s);

		int count[alpha];
		std::fill(count, count + alpha, 0);
		for(const char& i : s)
			count[i - 'a']++;

		std::cout << dict.query(count) << '\n';
	}
}
