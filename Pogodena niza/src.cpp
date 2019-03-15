#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int failing = 0;

	int last_c = -1;
	int a_seen = 0;
	int b_seen = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'A'){
			a_seen++;
		} else if(s[i] == 'B'){
			b_seen++;
		} else if(s[i] == 'C'){
			if(last_c != -1 and a_seen <= b_seen){
				failing++;
			}
			a_seen = 0;
			b_seen = 0;
			last_c = i;
		}
	}

	if(failing == 0){
		std::cout << "POGODENA\n";
	} else {
		std::cout << failing;
	}
}