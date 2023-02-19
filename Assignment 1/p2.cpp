#include <iostream>
using namespace std;

int main(){
    int n, dv, ch, tr;

    cout<<"Enter the number: "; cin>>n;
    cout<<"Roman number is be: ";
    tr=n/100; n=n%100;
    ch=n/10; dv=n%10;

    switch (tr)
    {
    case 1:
        cout<<"C";
        break;
    case 2:
        cout<<"CC";
        break;
    case 3:
        cout<<"CCC";
        break;
    case 4:
        cout<<"CD";
        break;
    case 5:
        cout<<"D";
        break;
    case 6:
        cout<<"DC";
        break;
    case 7:
        cout<<"DCC";
        break;
    case 8:
        cout<<"DCCC";
        break;
    case 9:
        cout<<"CM";
        break;
    }

switch (ch)
    {
    case 1:
        cout<<"X";
        break;
    case 2:
        cout<<"XX";
        break;
    case 3:
        cout<<"XXX";
        break;
    case 4:
        cout<<"XL";
        break;
    case 5:
        cout<<"L";
        break;
    case 6:
        cout<<"LX";
        break;
    case 7:
        cout<<"LXX";
        break;
    case 8:
        cout<<"LXXX";
        break;
    case 9:
        cout<<"XC";
        break;
    }

switch (dv)
    {
    case 1:
        cout<<"I";
        break;
    case 2:
        cout<<"II";
        break;
    case 3:
        cout<<"III";
        break;
    case 4:
        cout<<"IV";
        break;
    case 5:
        cout<<"V";
        break;
    case 6:
        cout<<"VI";
        break;
    case 7:
        cout<<"VII";
        break;
    case 8:
        cout<<"VIII";
        break;
    case 9:
        cout<<"IX";
        break;
    }
    return 0;
}