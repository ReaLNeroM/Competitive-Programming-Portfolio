#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e4 + 100;
int val[maxn];
std::vector<int> extra[maxn];
std::unordered_set<int> pushed[maxn];
std::set<int> m;
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    std::vector<int> v;
    for(int i = 1; i * i <= n; i++){
    	if(n % i == 0){
    		v.push_back(i);
    		v.push_back(n / i);
    	}
    }
    
    std::sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
    	extra[i].push_back(0);

    	for(int j = 0; j < i; j++){
    		if(v[i] % v[j] == 0){
    			extra[i].push_back(j);
    		}
    	}
    }

    std::queue<int> q, qsum;
   	q.push(v.size() - 1), qsum.push(0);

   	while(!q.empty()){
   		int fr = q.front();
   		int frsum = qsum.front();

   		q.pop();
   		qsum.pop();

   		if(fr == 0){
   			m.insert(frsum);
   			continue;
   		}

   		for(int i : extra[fr]){
   		    if(pushed[i].find(frsum + (v[fr] / v[i] - 1)) == pushed[i].end()){
       			pushed[i].insert(frsum + (v[fr] / v[i] - 1));
       			q.push(i);
       			qsum.push(frsum + (v[fr] / v[i] - 1));
   		    }
   		}
   	}

   	std::cout << m.size() << '\n';

   	for(int i : m){
   		std::cout << i << ' ';
   	}
   	std::cout << '\n';
}