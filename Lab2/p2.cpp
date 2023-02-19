#include<bits/stdc++.h>
using namespace std;

struct node
{
    int num;
    int coeff;
    struct node *next;
};

struct List{
    node *pHead, *pTail;
};

void KhoiTaoDS(List &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
//Hàm tạo 1 node mới
node *createNode(int h, int s){
    node *p = new node();
    if(p == NULL) exit(1);
    p->num = s;
    p->coeff = h;
    p->next = NULL;
    return p;
}

void addTail(List &l, node *p){
    if(l.pHead ==NULL){
        l.pHead = p;
        l.pTail = p;
    }else{
        l.pTail->next = p;
        l.pTail = p;
    }
}

void input(List &l){
    int x, n;
    cout<<"\nNhap bac cua da thuc: "; cin>>n;
    for(int i = n; i >= 0; i--){
        cout<<"Nhap he so cua x^"<<i<<": ";cin>>x;
        node *p = createNode(x, i);
        addTail(l,p);
    }
}

void add(List &l, List l1, List l2){
    node *p = new node;
    node *q = new node;
    if(l1.pHead->num > l2.pHead->num){
        l = l1;
        p = l2.pHead;
    }else{
        l = l2;
        p = l1.pHead;
    }
    q = l.pHead;
    while (q->num > p->num)
    {
        q = q->next;
    }
    while (q!=NULL)
    {
        q->coeff += p->coeff;
        p = p->next;
        q = q->next;
    }
}

void sub(List &l, List l1, List l2){
    node *p = new node;
    node *q = new node;
    if(l1.pHead->num > l2.pHead->num){
        l = l1;
        p = l2.pHead;
    }else{
        l = l2;
        p = l1.pHead;
    }
    q = l.pHead;
    while (q->num > p->num)
    {
        q = q->next;
    }
    while (q!=NULL)
    {
        q->coeff -= p->coeff;
        p = p->next;
        q = q->next;
    }
}

void output(List l){
    node *p = l.pHead;
    while (p!=l.pTail)
    {
        if(p->coeff) 
            cout << p->coeff << "x^" <<p->num;
        p = p->next;

        if(p->coeff){
            if(p->coeff > 0) cout<<" + ";
            else cout<<" ";
        }
    }
    p = l.pTail;
    cout << p->coeff;
}

int main(){
    List l, l1, l2;   

    while (1)
    {
        cout << "\n----------------------MENU--------------------\n";
		cout << "1. Input a polynomial and store it in a linked list.\n";
		cout << "2. Print the polynomial.\n";
		cout << "3. Perform addition on two polynomials.\n";
		cout << "4. Perform subtraction on two polynomials.\n";
        cout << "-----------------------------------------------\n";
		cout << "Choose: ";
		int lc; cin >> lc;

        if(lc==1){
            KhoiTaoDS(l);
            cout << "\nInput a polynomial and store it in a linked list.\n";
            input(l);

        }else if(lc==2){
            cout << "\nPrint the polynomial.\n";
            output(l);
        }else if(lc==3){
            cout << "\nPerform addition on two polynomials.\n";
            KhoiTaoDS(l);
            KhoiTaoDS(l1);
            KhoiTaoDS(l2);
            cout<<"\nNhap P(x): "; input(l1);
            cout<<"\nNhap Q(x): "; input(l2);
            cout<<"\nP(x) = "; output(l1);
            cout<<"\nQ(x) = "; output(l2);
            add(l, l1, l2);
            cout<<"\n=> R(x) = "; output(l);
        }else if(lc==4){
            cout << "Perform subtraction on two polynomials.\n";
            KhoiTaoDS(l);
            KhoiTaoDS(l1);
            KhoiTaoDS(l2);
            cout<<"\nNhap P(x): "; input(l1);
            cout<<"\nNhap Q(x): "; input(l2);
            cout<<"\nP(x) = "; output(l1);
            cout<<"\nQ(x) = "; output(l2);
            sub(l, l2, l1);
            cout<<"\n=> R(x) = "; output(l);
        }
    }
    return 0;
}