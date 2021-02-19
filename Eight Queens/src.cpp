#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int x[maxn];

int main(){
    std::ios::sync_with_stdio(false);
    std::string s[8];
    for(int i = 0; i < 8; i++){
        std::cin >> s[i];
    }

    int g = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(s[i][j] == '*'){
                g++;
            }
        }
    }
    if(g != 8){
        std::cout << "invalid\n";
        return 0;
    }
    for(int i = 0; i < 8; i++){
        int c = 0;
        for(int j = 0; j < 8; j++){
            if(s[i][j] == '*'){
                c++;
            }
        }
        if(c >= 2){
            std::cout << "invalid\n";
            return 0;
        }
    }

    for(int j = 0; j < 8; j++){
        int c = 0;
        for(int i = 0; i < 8; i++){
            if(s[i][j] == '*'){
                c++;
            }
        }
        if(c >= 2){
            std::cout << "invalid\n";
            return 0;
        }
    }

    for(int d = -30; d <= 30; d++){
        int c = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(j - i == d and s[i][j] == '*'){
                    c++;
                }
            }
        }
        if(c >= 2){
            std::cout << "invalid\n";
            return 0;
        }
    }

    for(int d = -30; d <= 30; d++){
        int c = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(j + i == d and s[i][j] == '*'){
                    c++;
                }
            }
        }
        if(c >= 2){
            std::cout << "invalid\n";
            return 0;
        }
    }

    std::cout << "valid\n";
}