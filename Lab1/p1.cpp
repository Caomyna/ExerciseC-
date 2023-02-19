#include <bits/stdc++.h>
using namespace std;

void input(int *a, int n){
    srand(time(0));
    for (int i=1; i<=n; i++)
        *(a+i)=rand() %100; 
}

void output(int *a, int n){
    for (int i=1; i<=n; i++)
        cout<< *(a+i)<<" ";
}

void removeOddNumber(int *a, int n){
    for (int i=1; i<=n; i++)
        if (*(a+i)%2==0)
			cout<< *(a+i)<<" ";
        	delete[]a;
}

int main()
{
	int n;
	int *a= new int[100];

	cout<<"Enter n: ";
	cin>>n;
	input(a, n);
    cout << "Values in array: " << endl;
    output(a, n);
    cout << "\nArray after remove all odd numbers: " << endl;
    removeOddNumber(a, n);
    return 0;
}
