#include <iostream>

using namespace std;

string trans(int x,int b)
{
    string s;
    int p=x;
    while(p>0)
    {
        if(p%b == 11) s+='A';
        else if(p%b == 12) s+='B';
        else if(p%b == 13) s+='C';
        else if(p%b == 14) s+='D';
        else if(p%b == 15) s+='E';
        else if(p%b == 16) s+='F';
        else if(p%b == 17) s+='G';
        else if(p%b == 18) s+='H';
        else if(p%b ==  19) s+='I';
        else s+=(p%b) + '0';
        p/=b;
    }
    return s;
}

bool pali(string s)
{
    if(s == "0") return 0;
    string t;
    for(int i=s.length()-1;i>=0;i--)
        t+=s[i];
    if(t == s) return 1;
    return 0;
}

int main()
{
    int b;
    cin>>b;
    for(int i=1; i<=300; i++)
    {
        string a=trans(i,b);
        string c=trans((i*i),b);
        if(pali(c) && a != "0") cout<<a<< " " << c << endl;
    }
    return 0;
}


