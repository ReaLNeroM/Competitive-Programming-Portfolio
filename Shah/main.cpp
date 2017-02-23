#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char horkni;
    int verkni;
    cin>>horkni>>verkni;
    int inp;
    cin>>inp;

    char horp;
    int verp, horpi, napadnati = 0;
    for(int i = 0; i < inp; i++){
        cin>>horp>>verp;
        horpi = fabs(horkni - (int) horp);
        verp = fabs(verkni - verp);
        if((horpi == 1 && verp == 2) || (horpi == 2 && verp == 1))
            napadnati++;
    }
    cout<<napadnati;
    return 0;
}
