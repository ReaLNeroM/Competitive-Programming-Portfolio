#include <iostream>
 
int main()
{
    int x, y;
    std::cin >> x >> y;
 
    long long vals[x][y], res[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            res[i][j] = vals[i][j] = 0;
            std::cin >> vals[i][j];
        }
    }
 
    res[0][0] = vals[0][0];
    for(int i = 0; i < x - 1; i++){
        long long bestskok[] = {0, 0};
        int bestpos = 0;
        for(int j = 0; j < y; j++){
            if(i == 0){
                bestskok[0] = vals[0][0];
                break;
            } else if(i == 1 and j == 0){
                continue;
            } else if(bestskok[0] == 0 or res[i][j] > bestskok[0]){
                bestskok[1] = bestskok[0];
                bestskok[0] = res[i][j];
                bestpos = j;
            } else if(bestskok[1] == 0 or res[i][j] > bestskok[1]){
                bestskok[1] = res[i][j]; // was j, this was THE BUG
            }
        }
        for(int j = 0; j < y; j++){
            if(i + j != 0){
                res[i][j] = std::max(res[i][j], bestskok[(bestpos == j)] + vals[i][j]);
                res[i + 1][j] = std::max(res[i + 1][j], res[i][j] + vals[i + 1][j]);
            }
        }
    }

    long long best = 0;
    for(int j = 0; j < y - 1; j++){
        best = std::max(res[x - 1][j], best);
    }
    res[x - 1][y - 1] = std::max(res[x - 1][y - 1], best + vals[x - 1][y - 1]);
 
    std::cout << res[x - 1][y - 1];
    return 0;
}
