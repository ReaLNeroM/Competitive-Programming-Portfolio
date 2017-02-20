#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
/*
ID: vlade.m1
PROG: cryptcow
LANG: C++
*/

string s;
string solved = "Begin the Escape execution at the Break of Dawn";
vector<int> pc, po, pw;
int able = false;
int copies = 0;
int c_seen = 0;

void dfs(int pos, string gen, int first_given = 0, int last_given = 1){
	if(pos >= 3){
		return;
	}
	if(pos == c_seen){
		if(gen == solved){
			able = true;
		}
		return;
	}
	int first = first_given;
	for(; first < gen.size(); first++){
		if(gen[first] == 'C'){
			break;
		} else if(gen[first] != solved[first]){
			return;
		}
	}
	int last = last_given;
	for(; gen.size() - last >= 0; last++){
		if(gen[gen.size() - last] == 'W'){
			break;
		} else if(gen[gen.size() - last] != solved[solved.size() - last]){
			return;
		}
	}

	string copy_s;
	string a = "";
	for(int i = first; i < gen.size(); i++){
		if(gen[i] == 'C'){
			for(int j = i + 1; j < gen.size(); j++){
				if(gen[j] == 'O'){
					for(int k = j + 1; k < gen.size(); k++){
						if(gen[k] == 'W'){
							copy_s = "";
							for(int l = 0; l < i; l++){
								copy_s += gen[l];
							}
							for(int l = j + 1; l < k; l++){
								copy_s += gen[l];
							}
							for(int l = i + 1; l < j; l++){
								copy_s += gen[l];
							}
							for(int l = k + 1; l < gen.size(); l++){
								copy_s += gen[l];
							}
							dfs(pos + 1, copy_s, first, last);
							if(able){
								return;
							}
						}
					}
				}
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//    freopen("cryptcow.in", "r", stdin);
//    freopen("cryptcow.out", "w", stdout);
	getline(cin, s);

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'C'){
			c_seen++;
		}
	}

	string extracted = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] != 'C' and s[i] != 'O' and s[i] != 'W'){
			extracted += s[i];
		}
	}
	sort(extracted.begin(), extracted.end());
	string solved_sorted = solved;
	sort(solved_sorted.begin(), solved_sorted.end());

	if(extracted == solved_sorted){
		dfs(0, s);
	}

	if(able == 0){
		c_seen = 0;
	} else if(able == 2){
		able = 0;
		c_seen = 0;
	}
	cout << able << ' ' << c_seen << endl;
}

