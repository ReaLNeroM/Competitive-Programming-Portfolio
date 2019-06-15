#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 305;
int operationIndex[maxn];
int validOp[maxn];
int goBack[maxn];
static char combine[maxn][maxn][maxn];
int n;
std::string str;

int main(){
	std::ios::sync_with_stdio(false);

	int testCases;
	std::cin >> testCases;

	validOp['1'] = true;
	validOp['0'] = true;
	validOp['X'] = true;
	validOp['x'] = true;
	goBack[0] = '0';
	goBack[1] = 'x';
	goBack[2] = 'X';
	goBack[3] = '1';

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			if(validOp[i] and validOp[j]){
				int vala = 0;
				if(i == '1'){
					vala = 3;
				} else if(i == 'X'){
					vala = 2;
				} else if(i == 'x'){
					vala = 1;
				} else if(i == '0'){
					vala = 0;
				}

				int valb = 0;
				if(j == '1'){
					valb = 3;
				} else if(j == 'X'){
					valb = 2;
				} else if(j == 'x'){
					valb = 1;
				} else if(j == '0'){
					valb = 0;
				}

				combine[i][j]['^'] = goBack[vala ^ valb];
				combine[i][j]['|'] = goBack[vala | valb];
				combine[i][j]['&'] = goBack[vala & valb];
			}
		}
	}

	for(int testCase = 1; testCase <= testCases; testCase++){
		std::cin >> str;
		n = str.size();

		int res = 1;

		std::vector<std::pair<char, int>> s;
		for(int i = 0; i < n; i++){
			s.push_back({str[i], i});

			char opChar = s[s.size() - 3].first;
			if(s.size() >= 5 and s[s.size() - 5].first == '(' and 
								validOp[s[s.size() - 4].first] and
								(opChar == '^' or opChar == '|' or opChar == '&') and
								validOp[s[s.size() - 2].first] and
							 	s[s.size() - 1].first == ')'){
				int ress = combine[s[s.size() - 4].first][s[s.size() - 2].first][opChar];
				s.pop_back();
				s.pop_back();
				s.pop_back();
				s.pop_back();
				s.pop_back();
				s.push_back({ress, -1});
			} else if(str[i] == 'x' or str[i] == 'X' or str[i] == '1' or str[i] == '0'){
				s[s.size() - 1].second = str[i];
			}
		}

		if(s.size() == 1 and (s[0].first == '1' or s[0].first == '0')){
			res = 0;
		}

		std::cout << "Case #" << testCase << ": " << res << '\n';
	}
}
