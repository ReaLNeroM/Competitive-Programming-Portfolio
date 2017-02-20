#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];

string conv[][3] = {
	{"and", "i", "ve"},
	{"auto", "avto", "oto"},
	{"break", "mrsh", "git"},
	{"case", "slucaj", "durum"},
	{"char", "bukva", "harf"},
	{"class", "paket", "paket"},
	{"continue", "trcaj", "kos"},
	{"delete", "brisi", "sil"},
	{"do", "pravi", "yap"},
	{"double", "dupla", "ikiser"},
	{"", "", ""},
	{"if", "ako", "eger"},
	{"while", "dodeka", "ancak"},
//	{"", "", ""},
};

int conv_size = 3;
int old = 0;
int new_num = 1;
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string str;
	while(getline(cin, str), str != "{}"){
		string made = "";
		for(int i = 0; i < str.size(); i++){
			int j;
			for(j = 0; j < conv_size; j++){
				if((i == 0 or !isalpha(str[i - 1])) and
						(i + conv[j][old].size() == str.size() or !isalpha(str[i + conv[j][old].size()])) and
						str.compare(i, conv[j][old].size(), conv[j][old], 0, conv[j][old].size()) == 0){
					made += conv[j][new_num];
					i += conv[j][old].size() - 1;
					break;
				}
			}
			if(j == conv_size){
				made += str[i];
			}
		}
		cout << made << endl;
	}
}
