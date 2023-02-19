#include<bits/stdc++.h>
using namespace std;

struct Student
{
    char id[12];
    char name[30];
    char Class[10];
    float mMath;
    float mPhysical;
};

struct Node
{
    Student data;
    Node *next;
};
typedef struct Node NODE;

struct List
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct List LIST;

//Khởi tạo danh sách liên kết đơn
void KhoiTaoDS(LIST &list)
{
    list.pHead = NULL;
    list.pTail = NULL;
}

// Cap phat mot NODE moi
NODE *makeNode(Student s)
{
    NODE *p = new NODE;
    p->data = s;
    p->next = NULL;
    return p;
}

// Kiem tra rong
int empty(LIST list)
{
    if (list.pHead == NULL)
    {
        return 1;
    }
    return 0;
}

void insertLast(LIST &list, NODE *p)
{

    if (list.pHead == NULL)
    {
        list.pHead = p;
        list.pTail = p;
    }
    else
    {
        list.pTail->next = p;
        list.pTail = p;
    }
}

void input(LIST &list, int n)
{
    cout << "Input students information.";
    for (int i = 0; i < n; i++)
    {
        Student s;
        cout << "\nEnter id: ";
        gets(s.id);
        cout << "Enter name: ";
        gets(s.name);
        cout << "Enter class: ";
        gets(s.Class);
        cout << "Math mark: ";
        cin >> s.mMath;
        cout << "Physical mark: ";
        cin >> s.mPhysical;
        cin.ignore();
        NODE *p = new NODE;
        p = makeNode(s);
        insertLast(list, p);
    }
}

void outputList(LIST list)
{
    NODE *p = list.pHead;
    while (p != NULL)
    {
        cout << p->data.id << "\t" << p->data.name << "\t" << p->data.Class << "\t" << p->data.mMath<< "\t" << p->data.mPhysical;
        p = p->next;
        cout<<endl;
    }
}

void searchID(LIST list){
    int dem = 0;
    char idSearch[12];
    cout<<"\nEnter ID to search: "; gets(idSearch);
    for(NODE *p = list.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.id, idSearch)==0){
            dem++;
            cout << p->data.id << "\t" << p->data.name << "\t" << p->data.Class << "\t" << p->data.mMath<< "\t" << p->data.mPhysical;
            cout<<endl;
        }
    }
    if(dem==0){
        cout << "Not Found !!";
        cout << endl;
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

void avg(LIST list){
    NODE *p, *q;
    float aver = 0, a[100];
    for(p=list.pHead; p!=NULL; p=p->next){
        aver = ((p->data.mMath + p->data.mPhysical)/2);
        // if(aver > max){
        //     max = aver;
        //     q=p;
        // }else if(aver == max){
        //     cout << p->data.name << "\t" << p->data.dob << "\t" << p->data.math << "\t" << p->data.physic << "\t" << p->data.language;
        //     cout<<endl;
        // }
    }

    cout<<endl;
}

int main(){
    LIST list;
    while (1)
    {
        cout << "----------------------MENU--------------------\n";
        cout << "1. Input a list of student.\n";
        cout << "2. Output a list of student.n.\n";
        cout << "3. Search a student by identification.\n";
        cout << "4. Sort the list in descending order based on avg (avg = (mMath+ mPhysical)/2).\n";
        cout << "-----------------------------------------------\n";
        cout << "Choose: ";
        int lc; cin >> lc; cin.ignore();

        if(lc==1){
            int n;
            cout << "Enter n: ";
            cin >> n;
            cin.ignore();
            KhoiTaoDS(list);
            input(list, n);
        }else if(lc==2){
            cout<<"\nThe Student List"<<endl;
            outputList(list);

        }else if(lc==3){
            cout<<"\nSearch a student by identification.. ";
            searchID(list);
        }
    }
    
    
    return 0;
}