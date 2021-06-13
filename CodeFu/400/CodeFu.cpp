#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
// #include <iostream>

using namespace std;
typedef long long ll;

struct cube {
    vector<int> v;
    cube(){
        v.resize(24);
        for(int i = 0; i < 24; i++){
            v[i] = i / 4;
        }
    }
    ll tohash(){
        ll s = 0;
        for(int i = 0; i < 24; i++){
            s *= 6LL;
            s += v[i];
        }
        return s;
    }
    bool isgood(){
        for(int i = 0; i < 6; i++){
            int col = v[4 * i];
            bool good = true;
            for(int j = 0; j < 4; j++){
                if(col != v[4 * i + j]){
                    good = false;
                }
            }
            if(good){
                return true;
            }
        }
        return false;
    }
};

enum erotate {
    l,
    lp,
    r,
    rp,
    f,
    fp,
    b,
    bp,
    u,
    up,
    d,
    dp
};

erotate conv(string s){
    if(s == "L"){
        return erotate::l;
    } else if(s == "L'"){
        return erotate::lp;
    }
    if(s == "R"){
        return erotate::r;
    } else if(s == "R'"){
        return erotate::rp;
    }
    if(s == "F"){
        return erotate::f;
    } else if(s == "F'"){
        return erotate::fp;
    }
    if(s == "B"){
        return erotate::b;
    } else if(s == "B'"){
        return erotate::bp;
    }
    if(s == "U"){
        return erotate::u;
    } else if(s == "U'"){
        return erotate::up;
    }
    if(s == "D"){
        return erotate::d;
    } else if(s == "D'"){
        return erotate::dp;
    }
    return erotate::dp;
}

vector<erotate> moves = {
    erotate::l,
    erotate::lp,
    erotate::r,
    erotate::rp,
    erotate::f,
    erotate::fp,
    erotate::b,
    erotate::bp,
    erotate::u,
    erotate::up,
    erotate::d,
    erotate::dp
};

void rot4(int &a, int &b, int &c, int &d){
    int tmp = d;
    d = c;
    c = b;
    b = a;
    a = tmp;
}


cube rotateL(cube in){
    cube c;
    c.v = in.v;
    rot4(c.v[0], c.v[1], c.v[3], c.v[2]);
    rot4(c.v[4], c.v[8], c.v[12], c.v[23]);
    rot4(c.v[6], c.v[10], c.v[14], c.v[21]);
    return c;
}
cube rotateR(cube in){
    cube c;
    c.v = in.v;
    rot4(c.v[16], c.v[17], c.v[19], c.v[18]);
    rot4(c.v[7], c.v[20], c.v[15], c.v[11]);
    rot4(c.v[5], c.v[22], c.v[13], c.v[9]);
    return c;
}
cube rotateF(cube in){
    cube c;
    c.v = in.v;
    rot4(c.v[8], c.v[9], c.v[11], c.v[10]);
    rot4(c.v[6], c.v[16], c.v[13], c.v[3]);
    rot4(c.v[7], c.v[18], c.v[12], c.v[1]);
    return c;
}
cube rotateB(cube in){
    cube c;
    c.v = in.v;
    rot4(c.v[20], c.v[21], c.v[23], c.v[22]);
    rot4(c.v[17], c.v[4], c.v[2], c.v[15]);
    rot4(c.v[19], c.v[5], c.v[0], c.v[14]);
    return c;
}
cube rotateU(cube in){
    cube c;
    c.v = in.v;
    rot4(c.v[4], c.v[5], c.v[7], c.v[6]);
    rot4(c.v[0], c.v[20], c.v[16], c.v[8]);
    rot4(c.v[1], c.v[21], c.v[17], c.v[9]);
    return c;
}
cube rotateD(cube in){
    cube c;
    c.v = in.v;
    rot4(c.v[12], c.v[13], c.v[15], c.v[14]);
    rot4(c.v[10], c.v[18], c.v[22], c.v[2]);
    rot4(c.v[11], c.v[19], c.v[23], c.v[3]);
    return c;
}

cube rotateLp(cube in){
    return rotateL(rotateL(rotateL(in)));
}
cube rotateRp(cube in){
    return rotateR(rotateR(rotateR(in)));
}
cube rotateFp(cube in){
    return rotateF(rotateF(rotateF(in)));
}
cube rotateBp(cube in){
    return rotateB(rotateB(rotateB(in)));
}
cube rotateUp(cube in){
    return rotateU(rotateU(rotateU(in)));
}
cube rotateDp(cube in){
    return rotateD(rotateD(rotateD(in)));
}

cube dorotate(cube in, erotate given){
    if(given == erotate::l){
        return rotateL(in);
    } else if(given == erotate::lp){
        return rotateLp(in);
    } else if(given == erotate::r){
        return rotateR(in);
    } else if(given == erotate::rp){
        return rotateRp(in);
    } else if(given == erotate::f){
        return rotateF(in);
    } else if(given == erotate::fp){
        return rotateFp(in);
    } else if(given == erotate::b){
        return rotateB(in);
    } else if(given == erotate::bp){
        return rotateBp(in);
    } else if(given == erotate::u){
        return rotateU(in);
    } else if(given == erotate::up){
        return rotateUp(in);
    } else if(given == erotate::d){
        return rotateD(in);
    } else { // given == erotate::dp
        return rotateDp(in);
    }
}

// int mat[6][8] = {
//     {-1, -1, 4, 5, -1, -1, -1, -1},
//     {-1, -1, 6, 7, -1, -1, -1, -1},
//     {0, 1, 8, 9, 16, 17, 20, 21},
//     {2, 3, 10, 11, 18, 19, 22, 23},
//     {-1, -1, 12, 13, -1, -1, -1, -1},
//     {-1, -1, 14, 15, -1, -1, -1, -1}
// };

// char convc[] = {'O', 'W', 'G', 'Y', 'R', 'B'};

// void printcube(cube c){
//     for(int i = 0; i < 6; i++){
//         for(int j = 0; j < 8; j++){
//             if(mat[i][j] == -1){
//                 cout << ' ';
//             } else {
//                 cout << convc[c.v[mat[i][j]]];
//             }
//         }
//         cout << '\n';
//     }
//     cout << '\n';
// }

class RubiksCube {
public:
    int solve(string scramble){
        cube c;
        int pos = 0;
        while(pos < scramble.size()){
            if(pos + 1 < scramble.size() and scramble[pos + 1] == '\''){
                string ss = scramble.substr(pos, 2);
                c = dorotate(c, conv(ss));
                pos += 2;
            } else {
                string ss = scramble.substr(pos, 1);
                c = dorotate(c, conv(ss));
                pos += 1;
            }
        }

        std::set<ll> seens;
        std::queue<cube> q;
        std::queue<int> qcost;
        q.push(c);
        qcost.push(0);
        seens.insert(c.tohash());
        while(!q.empty()){
            cube fr = q.front();
            int cc = qcost.front();
            q.pop();
            qcost.pop();

            if(fr.isgood()){
                return cc;
            }

            for(erotate ee : moves){
                cube nnext;
                nnext.v = fr.v;
                nnext = dorotate(nnext, ee);
                if(seens.find(nnext.tohash()) == seens.end()){
                    seens.insert(nnext.tohash());
                    q.push(nnext);
                    qcost.push(cc + 1);
                }
            }
        }

        return -1;
    }
};
