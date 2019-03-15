#include <iostream>
using namespace std;
 
int main(){
 
    int dolzina, brzina, lizganje, denovi = 0;
    cin>>dolzina>>brzina>>lizganje;
    for(int loc = 0;loc < dolzina;denovi++){
        if (denovi != 0){
        loc -= lizganje;
        }
        loc += brzina;
    }
    cout<<denovi;
    return 0;
}