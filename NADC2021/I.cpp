// https://nadc21.kattis.com/problems/nadc21.simplecronspec

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 101;
string cron[maxn][3];
int goods[maxn][3][100];

void parse(int i, int j, string s){
    if(s == "*"){
        for(int k = 0; k < ((j == 0) ? 24 : 60); k++){
            goods[i][j][k]++;
        }
        return;
    }

    int state = 0;
    int currl = 0;
    int currr = 0;

    for(char c : s){
        if(c == ','){
            if(state == 0){
                goods[i][j][currl]++;
            } else if(state == 1){
                for(int k = currl; k <= currr; k++){
                    goods[i][j][k]++;
                }
            }
            state = 0;
            currl = 0;
            currr = 0;
            continue;
        } else if(c == '-'){
            state = 1;
        } else {
            if(state == 0){
                currl *= 10;
                currl += c - '0';
            } else {
                currr *= 10;
                currr += c - '0';
            }
        }
    }

    if(state == 0){
        goods[i][j][currl]++;
    } else if(state == 1){
        for(int k = currl; k <= currr; k++){
            goods[i][j][k]++;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    cin >> n;
    string input;
    getline(cin, input);

    for(int i = 0; i < n; i++){
        getline(cin, input);
        int lastspace = 0;
        int spacesseen = 0;
        for(int j = 0; j < input.size(); j++){
            if(input[j] == ' '){
                cron[i][spacesseen] = input.substr(lastspace, j - lastspace);
                lastspace = j + 1;
                spacesseen++;
            }
        }
        cron[i][spacesseen] = input.substr(lastspace, input.size() - lastspace);
        // cout << cron[i][0] << '\n' << cron[i][1] << '\n' << cron[i][2] << endl;
        parse(i, 0, cron[i][0]);
        parse(i, 1, cron[i][1]);
        parse(i, 2, cron[i][2]);
    }

    int times = 0;
    int total = 0;
    for(int h = 0; h < 24; h++){
        for(int m = 0; m < 60; m++){
            for(int s = 0; s < 60; s++){
                bool seen = false;
                for(int i = 0; i < n; i++){
                    if(goods[i][0][h] and goods[i][1][m] and goods[i][2][s]){
                        total++;
                        seen = true;
                    }
                }
                if(seen){
                    times++;
                }
            }
        }
    }

    cout << times << '\n' << total << '\n';

}
