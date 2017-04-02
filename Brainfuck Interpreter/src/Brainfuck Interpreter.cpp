#include <iostream>

using namespace std;

const int maxn = 1e5 + 1;
unsigned char v[maxn];

int main(){
	for(int i = 0; i < maxn; i++){
		v[i] = 0;
	}

	int pos = maxn / 2;

	char c;
	while(cin >> c){
		if(c == '+'){
			v[pos]++;
		} else if(c == '-'){
			v[pos]--;
		} else if(c == '<'){
			pos--;
		} else if(c == '>'){
			pos++;
		} else if(c == '['){

		} else if(c == ']'){

		} else if(c == '.'){
			cout << c;
		} else if(c == ','){
			cin >> v[pos];
		}
	}
}