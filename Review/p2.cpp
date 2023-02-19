#include <iostream>
#include <string.h>
#define max 100
using namespace std;

struct Student {
	char id[12];
    char name[30];
    char Class[10];
    float mMath;
    float mPhysical;
};

typedef Student student;

void nhapSLSV(int &n, student a[]);
void nhapTTSV(student &s);
void xuatSV(student a[], int n);
void xuat1SV(student &s);
void timkiemsvtheoid(student a[], int n, char idcantim[]);
void sortsvDtvgiamdan(student a[], int n);

int main() {
	student a[max];
	int n;
	nhapSLSV(n,a);
	xuatSV(a,n);
	cout << "Giam dan theo diem trung binh " << endl;
	float dtbi,dtbj;
	sortsvDtvgiamdan(a,n);
	xuatSV(a,n);
	return 0;
}

void nhapSLSV(int &n, student a[]) {
	cout << "Nhap so luong sinh vien \n";
	cin >> n;
	for(int i = 0; i < n; i++) {
		nhapTTSV(a[i]);
	}
}

void nhapTTSV(student &s) {
	cout << "ID: " << endl;
	fflush(stdin);
	cin.getline(s.id,11);
	cout << "Name: " << endl;
	cin.getline(s.name,29);
	cout << "CLASS: " << endl;
	cin.getline(s.Class,9);
	cout << "MATH: " << endl;
	cin >> s.mMath;
	cout << "PHYCICAL: " << endl;
	cin >> s.mPhysical;
}

void xuatSV(student a[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "Thong tin sinh vien thu :" << i+1 << endl;
		cout << "ID: " << a[i].id << "| \t NAME: " << a[i].name << "| \tCLASS: " << a[i].Class << "| \tMATH: " << a[i].mMath << "| \tPHYSICAL: " << a[i].mPhysical << endl;
	}
}

void xuat1SV(student &s) {
	cout << "ID: " << s.id << "| \t NAME: " << s.name << "| \tCLASS: " << s.Class << "| \tMATH: " << s.mMath << "| \tPHYSICAL: " << s.mPhysical << endl;
}

void timkiemsvtheoid(student a[], int n, char idcantim[]) {
	for(int i = 0; i < n; i++) {
		if(stricmp(a[i].id,idcantim) == 0) {
			xuat1SV(a[i]);
		}
	}
}

void sortsvDtvgiamdan(student a[], int n) {
	student temp;
	for(int i = 0; i < n-1; i++) {
	    for(int j = n-1; j > i; j--) {
	    	float dtbi = (a[j].mMath+a[j].mPhysical)/2;
	    	float dtbj = (a[j-1].mMath+a[j-1].mPhysical)/2;
	    	if(dtbi > dtbj) {
	    	    temp = a[j];
	    	    a[j] = a[j-1];
	    	    a[j-1] = temp;
			}
		}
	}
}


