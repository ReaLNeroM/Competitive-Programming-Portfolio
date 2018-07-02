#include <bits/stdc++.h>

typedef long long ll;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

const int n = 3;
int val[n][n];
std::map<int, int> s;

int encode(int val[][n]){
	int number = 0;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			number *= 10;
			number += val[i][j];
		}
	}

	return number;
}

int main(){
	std::ios::sync_with_stdio(false);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			std::cin >> c;

			if(c == 'X'){
				val[i][j] = 0;
			} else {
				val[i][j] = c - '0';
			}
		}
	}

	std::queue<int> q;
	q.push(encode(val));
	s[encode(val)] = 0;

	while(!q.empty()){
		int fr = q.front();
		q.pop();

		int number = 100000000;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				val[i][j] = fr / number % 10;
				number /= 10;
			}
		}

		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(val[i][j] == 0){
					for(int k = 0; k < 4; k++){
						int ni = i + ay[k];
						int nj = j + ax[k];

						if(0 <= ni and ni < 3 and 0 <= nj and nj < 3){
							std::swap(val[i][j], val[ni][nj]);

							if(s.find(encode(val)) == s.end()){
								q.push(encode(val));
								s[encode(val)] = s[fr] + 1;
							}

							std::swap(val[i][j], val[ni][nj]);
						}
					}
				}
			}
		}
	}

	std::cout << s[123456780] << '\n';
}
