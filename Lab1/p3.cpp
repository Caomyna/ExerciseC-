#include <iostream>
using namespace std ;

int gcd(int a, int b)
{
    if(b==0)
    	return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b,c;
    cin >>a>>b;
    c = gcd(a,b);
    cout << "Greatest Common Divisor: "<<c<< endl;
    cout << "Lowest Common Multiple: "<<(a*b)/c << endl;
    return 0;
}