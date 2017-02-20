#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
char v[] = {'R', 'B', 'Y', 'G'};
int dead[4];
string s, orig;

void deduce(){
	for(int i = 0; i <= s.size() - 4; i++){
		if(s[i] != '!' and s[i + 1] != '!' and s[i + 2] != '!' and s[i + 3] == '!'){
			int found[4];
			for(int j = 0; j < 4; j++){
				found[j] = 0;
			}

			for(int k = i; k <= i + 2; k++){
				for(int l = 0; l < 4; l++){
					if(s[k] == v[l]){
						found[l]++;
					}
				}
			}

			for(int l = 0; l < 4; l++){
				if(found[l] == 0){
					s[i + 3] = v[l];
					dead[l]++;
					break;
				}
			}
		}
	}
}

bool verify(){
	for(int i = 0; i <= s.size() - 4; i++){
		int found[4];
		for(int j = 0; j < 4; j++){
			found[j] = 0;
		}

		for(int k = i; k <= i + 3; k++){
			for(int l = 0; l < 4; l++){
				if(s[k] == v[l]){
					found[l]++;
				}
			}
		}

		for(int l = 0; l < 4; l++){
			if(found[l] == 0){
				return false;
			}
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> orig;

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				s = orig;
				if(s[0] == '!'){
					s[0] = v[i];
					dead[i]++;
				}
				if(s[1] == '!'){
					s[1] = v[j];
					dead[j]++;
				}
				if(s[2] == '!'){
					s[2] = v[k];
					dead[k]++;
				}

				deduce();
				if(verify()){
					i = 4, j = 4, k = 4;
				} else {
					for(int l = 0; l < 4; l++){
						dead[l] = 0;
					}
				}
			}
		}
	}


	for(int i = 0; i < 4; i++){
		cout << dead[i] << ' ';
	}
}

