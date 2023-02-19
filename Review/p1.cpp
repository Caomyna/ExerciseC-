#include <iostream>
using namespace std;

void input(int a[] , int n) {
    for(int i = 0; i < n; i++) {
    	cout << "a["<<i<<"] =  ";
    	cin >> a[i];
	}
}

void output(int a[], int n) {
	cout << "\nDanh sach phan tu trong mang: \n";
	for(int i = 0; i < n; i++) {
		cout << "a["<<i<<"] = " << a[i] << " ";
	}
    cout<<endl;
}
void Partition(int A[], int left, int right)
{
    
    if (left >= right)
        return;

    int pivot = A[(left + right) / 2]; 

    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot) 
            i++;
        while (A[j] > pivot) 
            j--;
        if (i <= j)
        {
            if (i < j)
                swap(A[i], A[j]); 
            i++;
            j--;
        }
    }


    Partition(A, left, j);

    Partition(A, i, right);
}


void QuickSort(int A[], int n)
{
    Partition(A, 0, n - 1);
}

int SearchEle(int a[], int n, int x) {
	for(int i = 0; i < n; i++) {
		if(a[i] == x) {
			return i;
		} 
	}
	return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
 
        else
            r = m - 1;
    }

    return -1;
}
 

int main() {
	int a[1000];
	int n;
    cout << "Nhap so luong mang: \n";
    cin >> n;
	input(a,n);
	output(a,n);
	QuickSort(a,n);
	output(a,n);
	cout << "Tim kiem phan tu theo tim kiem tuyen tinh \n";
	int x; 
	cout << "Nhap phan tu can tim: \n";
	cin >> x;
	int results = SearchEle(a,n,x);
	if(results != -1) {
		cout << "Element is present in array with index is " << endl;
        cout << results;
	} else {
		cout << "Element isn't present in array with Result is" << endl;
	}
	cout << "\nTim kiem phan tu theo tim kiem nhi phan \n";
	cout << "Nhap phan tu can tim: \n";
	cin >> x;
	int results_1 = binarySearch(a,0,n,x);
	if(results_1 == -1)
    cout << "Element is not present in array";
    cout << "Element is present at index " << results_1;
	return 0;
}
