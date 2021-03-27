// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284

#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll INF = 1000000000000000010;

int val[maxn];
int correct[maxn];
int n, q;

void lower_call(std::vector<int> v, int up, int ind);
void upper_call(std::vector<int> v, int down, int ind);

void lower_call(std::vector<int> v, int up, int ind){
    if(v.empty()){
        return;
    }
    int m = v[std::rand() % v.size()];

    std::vector<int> lower, upper;

    for(int i : v){
        if(i == m){
            continue;
        }
        std::cout << i + 1 << ' ' << m + 1 << ' ' << up + 1 << std::endl;
        int x;
        std::cin >> x;
        if(x == m + 1){
            lower.push_back(i);
        } else if(x == i + 1){
            upper.push_back(i);
        } else {
            exit(0);
        }
    }

    lower_call(lower, m, ind);
    correct[ind + lower.size()] = m;
    upper_call(upper, m, ind + lower.size() + 1);
}

void upper_call(std::vector<int> v, int down, int ind){
    if(v.empty()){
        return;
    }
    int m = v[std::rand() % v.size()];

    std::vector<int> lower, upper;

    for(int i : v){
        if(i == m){
            continue;
        }
        std::cout << i + 1 << ' ' << m + 1 << ' ' << down + 1 << std::endl;
        int x;
        std::cin >> x;
        if(x == m + 1){
            upper.push_back(i);
        } else if(x == i + 1){
            lower.push_back(i);
        } else {
            exit(0);
        }
    }

    lower_call(lower, m, ind);
    correct[ind + lower.size()] = m;
    upper_call(upper, m, ind + lower.size() + 1);

}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases >> n >> q;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::srand(std::time(0));

        int a, b;
        do {
            a = std::rand() % n;
            b = std::rand() % n;
        } while(a == b);

        std::vector<int> lower, middle, upper;
        for(int i = 0; i < n; i++){
            if(i == a or i == b){
                continue;
            }
            std::cout << i + 1 << ' ' << a + 1 << ' ' << b + 1 << std::endl;
            int x;
            std::cin >> x;
            if(x == a + 1){
                lower.push_back(i);
            } else if(x == i + 1){
                middle.push_back(i);
            } else if(x == b + 1){
                upper.push_back(i);
            } else {
                return 0;
            }
        }

        lower_call(lower, a, 0);
        correct[lower.size()] = a;
        lower_call(middle, b, lower.size() + 1);
        correct[lower.size() + 1 + middle.size()] = b;
        upper_call(upper, b, lower.size() + 1 + middle.size() + 1);

        for(int i = 0; i < n; i++){
            std::cout << correct[i] + 1;
            if(i != n - 1){
                std::cout << ' ';
            }
        }
        std::cout << std::endl;

        int noop;
        std::cin >> noop;

    }
}