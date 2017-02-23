#include <iostream>

int hash(char ch){
	if(ch >= 'a'){
		return ch - 'a' + 26;
	} else {
		return ch - 'A';
	}
}
int main() {
	std::ios::sync_with_stdio(false);

	int wordlen, carvinglen;
	std::cin >> wordlen >> carvinglen;

	std::string word, carving;
	std::cin >> word >> carving;

	carving += 'a';
	//to simplify the check at the end, doesn't change the result

	int res = 0, pos;
	int freq[52], freqword[52];

	for(int i = 0; i < 52; i++){
		freq[i] = freqword[i] = 0;
	}

	for(pos = 0; pos < word.length() and pos < carving.length(); pos++){
		freq[hash(carving[pos])]++;
		freqword[hash(word[pos])]++;
	}

	int wrong = 0;
	for(int i = 0; i < 52; i++){
		if(freq[i] < freqword[i]){
			wrong++;
		}
	}

	while(pos < carving.length()){
		if(wrong == 0){
			res++;
		}
		freq[hash(carving[pos])]++;

		if(freq[hash(carving[pos])] == freqword[hash(carving[pos])]){
			wrong--;
		}

		freq[hash(carving[pos - word.length()])]--;

		if(freq[hash(carving[pos - word.length()])] == freqword[hash(carving[pos - word.length()])] - 1){
			wrong++;
		}

		pos++;
	}

	std::cout << res;
	return 0;
}
