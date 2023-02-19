#include <iostream>
using namespace std;

void input(int *a, int n){
	int *arr = new int[100];
	for(int i = 0; i<n; i++){
		cin >> *(a+i);
	}
	delete[] arr;
}

void output(int *a, int n){
	for(int i = 0; i < n ; i++){
		cout << *(a+i) << " ";
	}
}

int main()
{
	int n;
	int a[100];
    
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter the elements of the array: " << endl;
	input(a,n);
	cout << "Print out the array: ";
	output(a,n);
	
	return 0;
}





