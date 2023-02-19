#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 10
#define MAX_LIST 100

typedef struct Product {
    string code;
    string name;
    float price;
} product;


int h(string str) {
    int i = 0;
    for(int j=0; str[j]; j++ )
        i += str[j];
    return i % MAX_LIST;
}

void insert(product item, product ht[]) {
    int i, hash_value;
    i = hash_value = h(item.code);
    while(ht[i].code.size()) {
        i = (i+1) % MAX_LIST;
        if(i == hash_value) {
            cout<<"The table is full";
            return;
        }
    }
    ht[i] = item;
}

product search(string code, product ht[]) {
    int i;
    i = h(code);
    if(ht[i].code == "") {
        cout<<"Have no product like that";
        exit(0);
    }
    while(ht[i].code != code) {
        i = (i+1) % MAX_LIST;
    }
    return ht[i];
}

void remove(product item, product ht[]) {
    int i = h(item.code);
    while(ht[i].code != item.code) {
        i = (i+1) % MAX_LIST;
    }
    ht[i].code = "";
}

void printProducts(product ht[]) {
    for(int i=0;i<MAX_LIST;i++) {
        if(ht[i].code.size()) 
            cout<<ht[i].code<<' '<<ht[i].name<<' '<<ht[i].price<<'\n';
    }
}

int main() {

    product ht[MAX_LIST];

    product item1;
    item1.code = "10001";
    item1.name = "Sugar";
    item1.price = 50000;

    product item2;
    item2.code = "10002";
    item2.name = "Salt";
    item2.price = 7500;

    product item3;
    item3.code = "10003";
    item3.name = "Rice";
    item3.price = 15000;

    product item4;
    item4.code = "10004";
    item4.name = "Fish sauce";
    item4.price = 300000;

    insert(item1, ht);
    insert(item2, ht);
    insert(item3, ht);
    insert(item4, ht);
    
    product pro = search("10001", ht);
    cout<<pro.code<<' '<<pro.name<<' '<<pro.price;

    remove(pro, ht);
}
