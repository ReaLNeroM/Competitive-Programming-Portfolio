#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
std::vector<int> val[maxn];
std::vector<int> send[maxn];
int in[maxn];
bool start[maxn];
int p[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    int numbers, base, digits;
    std::cin >> numbers >> base >> digits;
    
    for(int i = 0; i < numbers; i++){
    	val[i].resize(digits + 5);
    	for(int j = 0; j < digits; j++){
    		std::cin >> val[i][j];
    	}
    	start[val[0][0]] = true;
    }

    std::fill(p, p + base, -1);

    for(int i = 0; i < numbers - 1; i++){
    	for(int j = 0; j <= digits; j++){
    		if(j == digits){
    			std::cout << -1 << '\n';
    			return 0;
    		}
    		if(val[i][j] != val[i + 1][j]){
    			send[val[i][j]].push_back(val[i + 1][j]);
    			in[val[i + 1][j]]++;
    			break;
    		}
    	}
    }

    int lowest = 0;
    for(int i = 0; i < base; i++){
    	if(!start[i] and in[i] == 0 and p[i] == -1){
    		std::queue<int> q;
    		q.push(i);

    		while(!q.empty()){
    			int fr = q.front();
    			p[fr] = lowest;
    			lowest++;
    			q.pop();

    			for(auto i : send[fr]){
    				in[i]--;
    				if(in[i] == 0){
    					q.push(i);
    				}
    			}
    		}
    	}
    }
    if(lowest == 0){
		std::cout << -1 << '\n';
		return 0;
    }
    for(int i = 0; i < base; i++){
    	if(p[i] == -1 and in[i] == 0){
    		std::queue<int> q;
    		q.push(i);

    		while(!q.empty()){
    			int fr = q.front();
    			p[fr] = lowest;
    			lowest++;
    			q.pop();

    			for(auto i : send[fr]){
    				in[i]--;
    				if(in[i] == 0){
    					q.push(i);
    				}
    			}
    		}
    	}
    }

    for(int i = 0; i < numbers - 1; i++){
    	for(int j = 0; j <= digits; j++){
    		if(j == digits or (val[i][j] != val[i + 1][j] and p[val[i][j]] > p[val[i + 1][j]])){
    			std::cout << -1 << '\n';
    			return 0;
    		}
    		if(val[i][j] != val[i + 1][j] and p[val[i][j]] < p[val[i + 1][j]]){
    			break;
    		}
    	}
    }

    for(int i = 0; i < base; i++){
    	std::cout << p[i] << ' ';
    }
    std::cout << '\n';
}