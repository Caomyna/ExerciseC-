#include<bits/stdc++.h>
using namespace std;

# define MAX_SIZE 100
typedef struct {
    int key;
/* other fileds */
} element;
element list[MAX_SIZE];

void bubbleSort(element list[], int n){
    int i, j, min;
    element tmp;
    for (i = 0; i < n-1; i++){
        for (j = n-1; j > i; j--){
            if (list[j-1].key > list[j].key) {
                /* exchange two elements */
                tmp = list[j-1];
                list[j-1] = list[j];
                list[j] = tmp;
            }
        }
    }
    
}

int main(){
    element list[100];
    int n;
    cout<<"Enter n = "; cin>>n;
    for(int i=0; i<list.length() ; i++){
        cout<<"list["<<i<<"] = "; 
        cin>>list[i];
    }
    bubbleSort(list,n);
    return 0;
}
