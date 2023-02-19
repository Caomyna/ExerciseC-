#include <iostream>
using namespace std;

void maxHeap(int a[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; // chỉ số con bên trái
    int r = 2 * i + 2; // chỉ số con bên phải
 
    
    if (l < n && a[l] > a[largest])
        largest = l;
 
    if (r < n && a[r] > a[largest])
        largest = r;
 
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeap(a, n, largest);
    }
}

void build_maxHeap(int a[], int n)
{
    for(int i = n/2 - 1; i>=0; i--)
        maxHeap(a, n, i);
}

void insertNode(int a[], int& n, int x)
{
    n = n + 1; 
    a[n - 1] = x;  // Chèn phần tử ở cuối Heap
    maxHeap(a, n, n - 1);
}

//Xóa Root 
void deleteRoot(int a[], int& n)
{
    int lastElement = a[n - 1];  // Get the last element
    a[0] = lastElement; // Replace root with last element
    n = n - 1;
    maxHeap(a, n, 0);
}

void printHeap(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void HeapSort(int a[], int n){
    for(int i = n/2 - 1; i>=0; i--)
        maxHeap(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int tmpa = a[0];
        a[0] = a[i];
        a[i] = tmpa;
        maxHeap(a, 0, i-1);
    }
}

int main() {
    int n = 8, x = 10;
    int a[n] = {45,36,54,27,63,72,61,18};
    
    cout<<"Max heap H: ";
    build_maxHeap(a,n);
    printHeap(a,n);

    cout<<"\nAfter insert x = 10 into H: ";
    insertNode(a, n, x);
    printHeap(a,n);

    cout<<"\nDelete the Root from Heap: ";
    deleteRoot(a, n);
    printHeap(a,n);

    cout<<"\nSort the numbers in descending order: ";
    HeapSort(a,n);
    printHeap(a, n);
    
    return 0;
}