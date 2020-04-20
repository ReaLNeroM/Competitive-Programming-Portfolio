#include <bits/stdc++.h>

typedef long long ll;

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        int x, y;
        std::cin >> x >> y;

        if(x > 100 or y > 100){
            std::cout << "IMPOSSIBLE\n";
            continue;
        }

        bool win = false;
        std::string res = "";

        for(int bitset = 0; bitset < (1 << (2 * 8)); bitset++){
            int cx = 0, cy = 0;

            std::string str = "";

            for(int bit = 3, j = 0, jmp = 1; j < 8; bit *= 4, j += 1, jmp *= 2){
                if(cx == x and cy == y){
                    if(!win or res.size() > str.size()){
                        res = str;
                    }
                    win = true;
                    break;
                }

                if((bitset & bit) == 0){
                    str += "S";
                    cy -= jmp;
                } else if(((bitset & bit) >> (2 * j)) == 1){
                    str += "N";
                    cy += jmp;
                } else if(((bitset & bit) >> (2 * j)) == 2){
                    str += "W";
                    cx -= jmp;
                } else { // (bitset & bit) == bit
                    str += "E";
                    cx += jmp;
                }

            }

            if(cx == x and cy == y){
                if(!win or res.size() > str.size()){
                    res = str;
                }
                win = true;
            }
        }

        if(win){
            std::cout << res;
        } else {
            std::cout << "IMPOSSIBLE";
        }

        std::cout << '\n';
    }
}
