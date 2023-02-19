#include<bits/stdc++.h>
using namespace std;

void input(int a[], int n){
     for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

void output(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << a[i] << "  ";
    }
}

void selectionSort(int a[], int n){
    for(int i=0; i <n-1; i++){
        //Dung 1 bien de luu chi so cua ptu nho nhat
        int min_pos = i;
        //Duyet tat ca cac ptu dung sau ptu hien tai va cap nhat chi so cua ptu nho nhat
        for(int j=i+1; j<n; j++){
            if(a[j] < a[min_pos]){
                min_pos = j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}

void bubbleSort(int a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }
}

void insertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        //Lay ra ptu ở chỉ số i
        int x = a[i], pos = i-1;
        while(pos >=0 && x<a[pos]){
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
    }
}

int linearSearch(int a[], int n, int x) 
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;

}

int BinSearch(int a[], int n, int x){
	int l = 0, r = n-1;
	while (l < r){
		int mid = (l+r)/2;
		if (a[mid] < x){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	if (a[l] == x){
		return l;
	}
	return -1;
}

void executionTime(int a[], int n)
{
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;      // Thời gian sử dụng
    start = clock();     // Lấy thời gian trước khi thực hiện thuật toán

    cout<<endl;   // Thực hiện thuật toán
    end = clock();  // lấy thời gian sau khi thực hiện 
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay bubbleSort(a,n): "<<time_use<<endl;
}

int main(){
    int a[10000], n;
    // int n=1000;
    // int a[n];
    // srand(time(0));
    // for( int i=0; i<n; i++)
    // {
    //     a[i] = rand()%10000;
    // }
    cout<<"enter n : ";
    cin>>n;
    input(a,n);
    selectionSort(a,n);
    cout<<"\nselectionSort: ";output(a,n);
    // int result = linearSearch(a, n, x);
    // cout<<"Element found at index: " << result;

    bubbleSort(a,n);
    cout<<"\nbubbleSort: ";output(a,n);
    insertionSort(a,n);
    cout<<"\ninsertionSort: ";output(a,n);

    return 0;
}