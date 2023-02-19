#include <bits/stdc++.h>
using namespace std;

struct Student
{
    char name[30];
    char dob[10];
    float math;
    float physic;
    float language;
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
        cout << "\nEnter name: ";
        gets(s.name);
        cout << "Enter date of birth: ";
        gets(s.dob);
        cout << "Math mark: ";
        cin >> s.math;
        cout << "Physic mark: ";
        cin >> s.physic;
        cout << "Language mark: ";
        cin >> s.language;
        cin.ignore();
        NODE *p = new NODE;
        p = makeNode(s);
        insertLast(list, p);
    }
}

void printList(LIST list)
{
    NODE *p = list.pHead;
    while (p != NULL)
    {
        cout << p->data.name << "\t" << p->data.dob << "\t" << p->data.math << "\t" << p->data.physic << "\t" << p->data.language;
        p = p->next;
        cout<<endl;
    }
}

void check_exits(LIST list){
    int dem = 0;
    char name1[30];
    cout<<"\nEnter name to check: "; gets(name1);
    for(NODE *p = list.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.name, name1)==0){
            dem++;
            cout << p->data.name << "\t" << p->data.dob << "\t" << p->data.math << "\t" << p->data.physic << "\t" << p->data.language;
            cout<<endl;
        }
    }
    if(dem==0){
        cout << "Not Found !!";
        cout << endl;
    }
}

void deletebyname(LIST &list){
    NODE *p, *q;
    q=NULL;
    char name1[30];
    cout<<"\nEnter name to delete: "; gets(name1);
    for(p = list.pHead; p!= NULL; p=p->next){
        if(strcmp(p->data.name, name1)==0) break;
        q=p;  
    }
    if(q!=NULL){
        if(p!=NULL){
            q->next=p->next;
            delete (p);
            if(p==list.pTail)  list.pTail=q;
            delete(p);
        }
    }
    else{
        list.pHead=p->next;
        delete(p);
        if(list.pHead==NULL) list.pTail=NULL;
    }
}

void maxAver(LIST list){
    NODE *p, *q;
    float max=0, aver = 0;
    for(p=list.pHead; p!=NULL; p=p->next){
        aver = ((p->data.math + p->data.physic + p->data.language)/3);
        if(aver > max){
            max = aver;
            q=p;
        }else if(aver == max){
            cout << p->data.name << "\t" << p->data.dob << "\t" << p->data.math << "\t" << p->data.physic << "\t" << p->data.language;
            cout<<endl;
        }
    }
    cout << q->data.name << "\t" << q->data.dob << "\t" << q->data.math << "\t" << q->data.physic << "\t" << q->data.language;
    cout<<endl;
}

void mathMarkless_5(LIST list){
    int dem=0;
    for(NODE *p=list.pHead; p!=NULL; p=p->next){
        if(p->data.math < 5){
            dem++;
            cout << p->data.name << "\t" << p->data.dob << "\t" << p->data.math << "\t" << p->data.physic << "\t" << p->data.language;
            cout<<endl;
        } 
    }
    if(dem==0){
        cout<<"No student has a math mark less than 5."<<endl;
    }
}

void writeFile(ofstream &fileOut, NODE *p){
    fileOut<<p->data.name << "\t" << p->data.dob << "\t" << p->data.math << "\t" << p->data.physic << "\t" << p->data.language<<endl;
}

void OutFile(LIST &list){
    ofstream fileout;
    fileout.open("StudentList.txt", ios::out);
    for(NODE *p=list.pHead; p!=NULL; p=p->next){
        writeFile(fileout, p);
    }
    fileout.close();
}

int main()
{
    LIST list;
    while(1){
		cout << "----------------------MENU--------------------\n";
		cout << "1. Input n students'information.\n";
		cout << "2. Print out the student list.\n";
		cout << "3. Add a new student to the list.\n";
		cout << "4. Count the number of students in a given year of the birth.\n";
		cout << "5. Check if a student name x exits in the list or not.\n";
		cout << "6. Delete a student from the list by a given name x.\n";
		cout << "7. Find the student having the biggest average of math, physic and language marks.\n";
		cout << "8. Print the list of the students whose math mark is less than 5.\n";
		cout << "9. Write the student list to a file named SrudentList.txt/\n";
        cout << "0. Exit.\n";
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
            printList(list);

        }else if(lc==3){
            input(list,1);

        }else if (lc==4){
            
        }else if(lc==5){
            cout<<"\nCheck if a student name x exits in the list or not. ";
            check_exits(list);
        }else if(lc==6){
            cout<<"\nDelete a student from the list by a given name ";
            deletebyname(list);
        }else if(lc==7){
            cout << "\nFind the student having the biggest average of math, physic and language marks.\n";
            maxAver(list);
        }else if(lc==8){
            cout << "\nPrint the list of the students whose math mark is less than 5.\n";
            mathMarkless_5(list);
        }else if(lc==9){
            cout << "\nWrite the student list to a file named SrudentList.txt/\n";
            OutFile(list);
        }else if(lc==0){
            cout << "Exit!!";
            exit(0);
        }
    }
    return 0;
}