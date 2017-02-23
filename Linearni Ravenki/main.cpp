#include <iostream>

using namespace std;

int main()
{
    int broja, brojb;
    cin>>broja>>brojb;
    if(broja == 0 && brojb == 0){
        cout<<"ima beskonecno resenija";
    } else if(broja == 0){
        cout<<"nema resenie";
    }
    else{
        cout<<-brojb/broja;
    }
    return 0;
}
