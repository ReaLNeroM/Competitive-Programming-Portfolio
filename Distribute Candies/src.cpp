#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
int val[maxn];
ll res = 0;

bool equal_adjacent(std::vector<ll> &v){
    for(int i = 0; i + 1 < v.size(); i++){
        if(v[i] == v[i + 1]){
            return true;
        }
    }

    return false;
}

int main(){
    std::ios::sync_with_stdio(false);
    
    ll candies, boxes;
    std::cin >> candies >> boxes;
    
    ll limit = (boxes + 1) / 2;
    
    std::multiset<std::pair<ll, ll>> occurences;
    std::map<ll, ll> m;

    occurences.insert({candies % boxes, candies / boxes + 1});
    occurences.insert({boxes - candies % boxes, candies / boxes});
    
    m[candies / boxes + 1] = candies % boxes;
    m[candies / boxes] = boxes - candies % boxes;
    
    while(occurences.rbegin()->first > limit){
        auto pair = *(occurences.rbegin());
        
        occurences.erase(--occurences.end());
        auto ite = occurences.find({m[pair.second + 1], pair.second + 1});
        if(ite != occurences.end()){
            occurences.erase(ite);
        }
        ite = occurences.find({m[pair.second - 1], pair.second - 1});
        if(ite != occurences.end()){
            occurences.erase(ite);
        }

        m[pair.second - 1]++;
        m[pair.second] -= 2;
        m[pair.second + 1]++;
        
        occurences.insert({m[pair.second - 1], pair.second - 1});
        occurences.insert({m[pair.second], pair.second});
        occurences.insert({m[pair.second + 1], pair.second + 1});
    }
    
    std::vector<ll> v;

    for(int i = 0; i + 1 < boxes; i += 2){
        auto copy = *occurences.rbegin();
        occurences.erase(--occurences.end());
        auto secondcopy = *occurences.rbegin();
        occurences.erase(--occurences.end());

        v.push_back(copy.second);
        v.push_back(secondcopy.second);

        copy.first -= 1;
        secondcopy.first -= 1;
        occurences.insert(copy);
        occurences.insert(secondcopy);
    }
    
    if(boxes % 2 == 1){
        v.push_back(occurences.rbegin()->second);
    }
    
    
    if(*std::min_element(v.begin(), v.end()) <= 0 or equal_adjacent(v)){
        std::cout << -1 << '\n';
        return 0;
    }

    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << ' ';
    }

    std::cout << '\n';
}
