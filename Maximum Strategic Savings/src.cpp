//============================================================================
// Name        : Kruskal's.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;

class vertex {
    ll rank = 1;
    vertex *parent = this;

    public:
    vertex* FindHead(){
        if(parent != parent->parent){
            parent = parent->FindHead();
        }

        return parent;
    }

    void Merge(vertex* second_node){
        vertex* head = FindHead();
        second_node = second_node->FindHead();
        if(head->rank > second_node->rank){
            second_node->parent = head;
        } else if(second_node->rank > head->rank){
            head->parent = second_node;
        } else{
            head->parent = second_node;
            head->rank++;
        }
    }
};

const ll maxn = 1e6 + 1e2;
vertex u[maxn];
ll res = 0;

struct edge{
    vertex* loc[2];
    ll cost;

    bool operator<(const edge &x) const{
        return (cost < x.cost);
    }
};

int main(){
    ll planets, cities, flights, portals;
    std::cin >> planets >> cities >> flights >> portals;
    edge e[flights + portals];

    for(ll i = 0, loc1, loc2; i < flights; i++){
        std::cin >> loc1 >> loc2 >> e[i].cost;

        loc1--, loc2--;
        e[i].loc[0] = &u[loc1];
        e[i].loc[1] = &u[loc2];

        std::cerr << loc1 << ' ' << loc2 << '\n';
    }

    for(ll i = flights, loc1, loc2; i < flights + portals; i++){
        std::cin >> loc1 >> loc2 >> e[flights + i].cost;

        loc1--, loc2--;
        e[i].loc[0] = &u[loc1 + cities];
        e[i].loc[1] = &u[loc2 + cities];

        std::cerr << loc1 + cities << ' ' << loc2 + cities << '\n';
    }

    std::sort(e, e + flights);
    std::sort(e + flights, e + flights + portals);

    for(ll i = 0; i < flights; i++){
        if(e[i].loc[0]->FindHead() != e[i].loc[1]->FindHead()){
            e[i].loc[0]->Merge(e[i].loc[1]);
            res += e[i].cost;
        }
    }
    for(ll i = flights; i < flights + portals; i++){
        if(e[i].loc[0]->FindHead() != e[i].loc[1]->FindHead()){
            e[i].loc[0]->Merge(e[i].loc[1]);
            res += e[i].cost;
        }
    }

    std::cout << res << '\n';
    return 0;
}