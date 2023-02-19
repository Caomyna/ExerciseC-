#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* pLeft;
    struct node* pRight;
};
typedef struct node NODE;
typedef NODE* TREE;

//Khởi tạo Tree
void KhoiTaoTree(TREE &t)
{
    t = NULL;
}

//Chèn ptu x vào BST
void ChenNodeVaoTree(TREE &t, int x)
{
    if(t==NULL)
    {
        NODE *p = new NODE;
        p->data = x; 
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // node p chính là node gốc
    }else{
        if(x < t->data)
        {
            ChenNodeVaoTree(t->pLeft, x); //duyệt qua trái để thêm phần tử x
        }else if(x > t->data){
            ChenNodeVaoTree(t->pRight, x);
        }
    }
}


//Hàm xuất BST theo N-L-R
void Duyet_NLT(TREE t)
{
    if(t != NULL){
        cout<< t->data <<" ";
        Duyet_NLT(t->pLeft); //Duyệt qua trái
        Duyet_NLT(t->pRight);
    }
}
//Nhập dữ liệu
void Menu(TREE &t)
{
    while(true){
        cout<<"\n============MENU===============";
        cout<<"\n1. Nhap du lieu";
        cout<<"\n2. Xuat du lieu cay theo NLR";
        cout<<"\n0. Thoat";

        int chon;
        cout<<"\nNhap lua chon: ";
        cin>>chon;

        if(chon<0 ||chon>2){
            cout<<"\nKhong hop le";
            system("pause");
        }else if(chon == 1){
            int x;
            cout<<"\nNhap so nguyen x: ";
            cin>>x;
            ChenNodeVaoTree(t, x);
        }else if(chon == 2){
            cout<<"\n.Duyệt cây theo NLR: ";
            Duyet_NLT(t);
            system("pause");
        }else{
            system(0);
        }
    }
}

int main(){
    TREE t;
    KhoiTaoTree(t);
    Menu(t); 
    system("pause");
    return 0;
}