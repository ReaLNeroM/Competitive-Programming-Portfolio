#include <iostream>

typedef long long ll;

std::string limit;
std::string check = "1";

std::string minstr(std::string a, std::string b){
	if(a.length() == b.length()){
		if(a > b){
			return b;
		} else {
			return a;
		}
	} else if(a.length() > b.length()){
		return b;
	} else {
		return a;
	}
}

std::string finish(int pos, int needed){
	std::string curr = "";
	for(int i = 0; i < limit.length() - needed - pos; i++){
		curr += '0';
	}
	for(int i = 0; i < needed; i++){
		curr += '7';
	}

	return curr;
}

std::string dfs(std::string str, int pos, int left){
	if(left == 0 and minstr(str, check) == check){
		return str;
	} else if(left == 0){
		return finish(pos, left); // wrong
	} else if(minstr(str, check) == check){
		return finish(pos, left);
	} else{
		std::string check = str;
		if(str[pos] <= '7'){
			check += '7';
			dfs(check, pos + 1, left - 1);
		}
		if()
	}


}
int main() {
	int needed;
	std::cin >> limit >> needed;

	check += finish(0, needed);
//	std::cout << minstr(dfs("", 0, needed), check);
	return 0;
}
