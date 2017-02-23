#include <iostream>

using namespace std;

int main()
{
    int mesec;
    cin>>mesec;

    if(mesec == 4 || mesec == 6 || mesec == 9 || mesec == 11){
        cout<<30;
    } else if(mesec == 2){
        cout<<28;
    } else{
        cout<<31;
    }
    return 0;
}
