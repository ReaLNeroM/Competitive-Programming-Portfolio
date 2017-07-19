#include <bits/stdc++.h>

typedef long long ll;

int app[10];
int temp[10];

int main(){
	std::ios::sync_with_stdio(false);
	
	std::string a, b;
	std::cin >> a >> b;
	
	for(int i = 0; i < a.size(); i++){
		app[a[i] - '0']++;
	}
	
	for(int i = 0; i < b.size(); i++){
		app[b[i] - '0']--;
	}
	std::copy(app, app + 10, temp);
	
	std::string res = "";
	
	for(int size = 1; size <= a.size(); size++){
		std::copy(temp, temp + 10, app);
		
		int temp_size = size;
		bool good = true;
		
		while(temp_size){
			if(app[temp_size % 10] == 0){
				good = false;
				break;
			}
			
			app[temp_size % 10]--;
			temp_size /= 10;
		}
		
		int sum = 0;
		for(int i = 0; i < 10; i++){
			sum += app[i];
		}
		sum += b.size();
		
		if(!good or sum != size){
			continue;
		}
		
		int done = 0;
	
		std::string x = "";
		std::string y = b;
		if(y[0] == '0'){
			y = "A";
		}
	
		int to_add = -1;
		
		for(int i = 1; i < 10; i++){
			if(app[i]){
				to_add = i;
				x += (char) ('0' + i);
				app[i]--;
				break;
			}
		}
		
		for(int i = 0; i < b[0] - '0'; i++){
			for(int j = 0; j < app[i]; j++){
				if(x == "" and i == 0){
					x = "A";
				}
				x += (char) ('0' + i);
				y += (char) ('0' + i);
			}
			
			if(i == to_add){
				y += (char) ('0' + i);
			}
		}
		
		bool odma_dodaj_b = true;
		
		for(int j = 1; j < b.size(); j++){
			if(b[j] > b[0]){
				odma_dodaj_b = false;		
			} else if(b[j] < b[0]){
				break;
			}
		}
		
		if(odma_dodaj_b){
			x += b;

			for(int j = 0; j < app[b[0] - '0']; j++){
				x += b[0];
				y += b[0];
			}
			if(b[0] - '0' == to_add){
				y += b[0];
			}
		} else {
			for(int j = 0; j < app[b[0] - '0']; j++){
				x += b[0];
				y += b[0];
			}
			if(b[0] - '0' == to_add){
				y += b[0];
			}

			x += b;
		}
		
		for(int i = b[0] - '0' + 1; i < 10; i++){
			for(int j = 0; j < app[i]; j++){
				x += (char) ('0' + i);
				y += (char) ('0' + i);
			}
			if(i == to_add){
				y += (char) ('0' + i);
			}
		}
		
		res = std::min(x, y);
		
		break;
	}

	std::cout << res;
}