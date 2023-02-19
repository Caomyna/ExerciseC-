#include <iostream>
using namespace std;

void input(double a[], int n){
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"a["<<i<<"]= ";cin>>a[i];
    }

}
double aver_a(double a[], int n){
    float sum=0, aver=0;
    for(int i=0; i<n; i++){
        sum = sum + a[i];
    }
    aver = sum/n;
    cout<<"Average = "<<aver<<endl;
    return aver;
}
double aver_b(double a[], int n){
    double sum1=0, sum2=0, aver1=0, aver2=0;
    int count1=0, count2=0;
    for(int i=0; i<n; i++){
        if(a[i]<0.01){
            count1++;
            sum1 = sum1 + a[i];
        }else{
            count2++;
            sum2 = sum2 + a[i];
        }
    }
    aver1 = sum1/count1;
    aver2 = sum2/count2;   
    cout<<"Average1 = "<<aver1<<";  "<<"Average2 = "<<aver2<<endl;
    return 0;
}
int main(){
    int n;
    double a[1000];
    do{
        cout<<"Enter n: ";
        cin>>n;
    }while(n<0);
    input(a,n);
    aver_a(a,n);
    aver_b(a,n);
    return 0;
}