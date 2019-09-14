#include <bits/stdc++.h>

typedef long long ll;
int n;

const int N=500000,INF=1000000000;
std::string a;
int t[N][26],l[N],r[N],p[N],s[N],tv,tp,ts,la;

void ukkadd (int c) {
    suff:;
    if (r[tv]<tp) {
        if (t[tv][c]==-1) { t[tv][c]=ts;  l[ts]=la;
            p[ts++]=tv;  tv=s[tv];  tp=r[tv]+1;  goto suff; }
        tv=t[tv][c]; tp=l[tv];
    }
    if (tp==-1 || c==a[tp]-'a') tp++; else {
        l[ts+1]=la;  p[ts+1]=ts;
        l[ts]=l[tv];  r[ts]=tp-1;  p[ts]=p[tv];  t[ts][c]=ts+1;  t[ts][a[tp]-'a']=tv;
        l[tv]=tp;  p[tv]=ts;  t[p[ts]][a[l[ts]]-'a']=ts;  ts+=2;
        tv=s[p[ts-2]];  tp=l[ts-2];
        while (tp<=r[ts-2]) {  tv=t[tv][a[tp]-'a'];  tp+=r[tv]-l[tv]+1;}
        if (tp==r[ts-2]+1)  s[ts-2]=tv;  else s[ts-2]=ts;
        tp=r[tv]-(tp-r[ts-2])+2;  goto suff;
    }
}

void build() {
    ts=2;
    tv=0;
    tp=0;
    std::fill(r,r+N,(int)a.size()-1);
    s[0]=1;
    l[0]=-1;
    r[0]=-1;
    l[1]=-1;
    r[1]=-1;
    memset (t, -1, sizeof t);
    std::fill(t[1],t[1]+26,0);
    for (la=0; la<(int)a.size(); ++la)
        ukkadd (a[la]-'a');
}

class Solution {
public:
    std::string lastSubstring(std::string st) {
        a = st;
        n = st.size();
        build();

        int pos = 0;

        std::vector<char> v;
        for(int i = 0; i < n; i++){
            for(int a = 25; a >= 0; a--){
                if(t[pos][a] != -1){
                	for(int j = l[pos]; l[pos] != -1 and j <= r[pos]; j++){
                		v.push_back(st[j]);
                	}
                    pos = t[pos][a];
                    break;
                }
            }
        }

        for(int i = l[pos]; i <= r[pos]; i++){
        	v.push_back(st[i]);
        }
        std::string str(v.begin(), v.end());

        return str;
    }
};

typedef long long ll;

int main(){
	Solution x;
	std::string v = "cbbbacbbbba";
	 std::cout << x.lastSubstring(v);
}
