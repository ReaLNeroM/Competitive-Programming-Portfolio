#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
int val[maxn];
ll res = 0;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m11, s11, m12, s12;
    cin >> m11 >> s11 >> m12 >> s12;
    int m21, s21, m22, s22;
    cin >> m21 >> s21 >> m22 >> s22;

    s11 += s12;
    if(s11 >= 60){
        m11++;
        s11 -= 60;
    }
    m11 += m12;


    s21 += s22;
    if(s21 >= 60){
        m21++;
        s21 -= 60;
    }
    m21 += m22;

    if(m11 > m21 or (m11 == m21 and s11 > s21)){
        cout << 'D' << endl;
        m11 -= m21;
        s11 -= s21;

        if(s11 < 0){
            s11 += 60;
            m11--;
        }
        cout << m11 << ' ' << s11 << endl;
    } else {
        cout << 'T' << endl;
        m21 -= m11;
        s21 -= s11;

        if(s21 < 0){
            s21 += 60;
            m21--;
        }
        cout << m21 << ' ' << s21 << endl;
    }
}
