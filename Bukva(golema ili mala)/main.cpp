#include <iostream>

using namespace std;

int main()
{
    char bukva;
    cin>>bukva;
    if(bukva > 64 && bukva < 91){
        cout<<"GOLEMA";
    } else if(bukva > 96 && bukva < 123){
        cout<<"MALA";
    } else{
        cout<<"GRESKA";
    }
    return 0;
}
