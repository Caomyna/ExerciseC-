#include <bits/stdc++.h>
using namespace std;

typedef struct
{
	char name[30];
	char Class[10];
	float mMath;
	float mPhysical;
}Student;

void inputStudent(Student &st){
	cout<<"Enter Name: "; cin.getline(st.name,30);
	cout<<"Enter Class: "; cin.getline(st.Class,10);
	cout<<"Enter Math score: "; cin>>st.mMath;
	cout<<"Enter Physical score: "; cin>>st.mPhysical; cin.ignore();
	cout<<endl;
	
}
void outputStudent(Student &st){
	cout<<"\nName: "<<st.name<<endl;
	cout<<"Class: "<<st.Class<<endl;
	cout<<"Math: "<<st.mMath<<endl;
	cout<<"Physical: "<<st.mPhysical<<endl;
}

void add(Student st[], int n){
	for(int i=0; i<n; i++){
		inputStudent(st[i]);
	}
    cout<<"\n-------------------------------------"<<endl;
	
}
void SearchByName(Student st[], int n){
	char name1[30];
	cout<<"\nEnter name to search: ";
	cin.getline(name1,30);
	for(int i=0; i<n; i++){
        if (strcmp(st[i].name, name1) == 0){
	        outputStudent(st[i]);
	    }
    }
    cout<<"\n-------------------------------------"<<endl;
}

void edit(Student st[], int n){
	char name1[30];
	cout<<"\nEnter name to search: ";
	cin.getline(name1,30);
	for(int i=0; i<n; i++)
	{
        if (strcmp(st[i].name, name1) == 0){
        	cout<<"Edit class: ";
        	cin.getline(st[i].Class,10);
	    }
    }
    cout<<"\n-------------------------------------"<<endl;
}
int main()
{
	int n, c;
	do{
		cout<<"Enter the number of students: ";cin>>n;
	}while(n<=0);
	Student st[n];
		
	while(true){
		cout<<"\n-----Managing a list of students----"<<endl;
		cout<<"  1.Add new student "<<endl;
		cout<<"  2.Search a student by name"<<endl;
		cout<<"  3.Search a student and edit class"<<endl;
		cout<<"\nChoose: ";
		cin>>c;
		cin.ignore();
		switch(c){
			case 1:
				cout<<"\n1.Add new student"<<endl;
				add(st,n);
				break;
			case 2:
				cout<<"\n2.Search a student by name";
				SearchByName(st, n);
				break;
			case 3:	
				cout<<"\n3.Search a student and edit class";
				edit(st,n);
				break;
			default:
				cout<<"This function is not available!!"<<endl;
				break;
		}
	}
	return 0;
}

