#include <iostream>
#include <vector>

using namespace std;

int x, y;
std::vector<int> vci, ovci;
int adder[] = {1, -1, 0, 0};
int copies[] = {0, 0};

void flood(int lx, int ly){

    if(mat[lx][ly] == 'v'){
        copies[0]++;
    } else if(mat[lx][ly] == 'o'){
        copies[1]++;
    }

    mat[lx][ly] = '#';
    for(int i = 0; i < 4; i++){
        int cx = lx + adder[i], cy = ly + adder[(i + 2) % 4];
        if(cx < x and cx >= 0 and cy < y and cy >= 0 and mat[cx][cy] != '#'){
            flood(cx, cy);
        }
    }


    return;
}

int main()
{
    cin >> x >> y;
char mat[250][250];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(mat[i][j] != '#'){
                flood(i, j);
                vci.push_back(copies[0]);
                ovci.push_back(copies[1]);
                copies[0] = copies[1] = 0;
            }
        }
    }

    int vk = 0, ovca = 0;
    for(int i = 0; i < vci.size(); i++){
        if(ovci[i] > vci[i]){
            ovca += ovci[i];
        } else{
            vk += vci[i];
        }
    }

    cout << ovca << " " << vk;
    return 0;
}
