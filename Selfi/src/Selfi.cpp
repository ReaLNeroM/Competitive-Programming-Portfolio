#include <iostream>
#include <queue>

struct state {
    long long l, r;
    int size;
} copy;

int main(){
    long long lowerb, upperb;
    std::cin >> lowerb >> upperb;

    int lsize = 1, usize = 1;
    for(long long i = 10; i < lowerb; i *= 10){
        lsize++;
    }
    for(long long i = 10; i < upperb; i *= 10){
        usize++;
    }
    long long mult[20][10];
    long long power = 1;
    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 10; j++){
            mult[i][j] = j * power;
        }
        power *= 10;
    }

    long long res = 0;
    std::queue<state> q;
    q.push(copy);

    copy.l = 0;
    copy.r = 0;
    copy.size = 1;
    while(!q.empty()){
        state fr = q.front();
        q.pop();
        state copy = fr;
        if(fr.size <= usize + 1){
            long long c = fr.l * mult[fr.size / 2][1] + fr.r;
            if(lowerb <= c and c <= upperb){
                res++;
            }
            if(fr.l > 0 and fr.l % 10 != 5 and fr.l % 10 != 2){
                c = (fr.l / 10) * mult[fr.size / 2][1] + fr.r;

                if(lowerb <= c and c <= upperb){
                    res++;
                }
            }
        }
        if(fr.size <= usize - 1){
            copy.l *= 10;
            if(copy.l != 0){
                copy.size = fr.size + 2;
                q.push(copy);
            }

            copy.size = fr.size + 2;

            copy.l += 1;
            copy.r += mult[fr.size / 2][1];
            q.push(copy);

            copy.l += 4;
            copy.r += mult[fr.size / 2][1];
            q.push(copy);

            copy.l -= 3;
            copy.r += mult[fr.size / 2][3];
            q.push(copy);

            copy.l += 6;
            copy.r += mult[fr.size / 2][3];
            q.push(copy);

        }
    }

    std::cout << res;
}
