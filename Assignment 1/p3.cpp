#include <iostream>
using namespace std;

double add(double a, double b){
    return a+b;
}
double sub(double a, double b){
    return a-b;
}
double mul(double a, double b){
    return a*b;
}
double div(double a, double b){
    return a/b;
}
int main(){
    double a, b;
    cout<<"Enter a = "; cin>>a;
    cout<<"Enter b = "; cin>>b;

    cout<<"a + b = "<<add(a,b)<<endl;
    cout<<"a - b = "<<sub(a,b)<<endl;
    cout<<"a * b = "<<mul(a,b)<<endl;
    cout<<"a / b = "<<div(a,b)<<endl;
    return 0;
}