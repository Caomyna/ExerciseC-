#include <bits/stdc++.h>
using namespace std;

typedef struct Student
{
 	char ten[30];
	char lop[10];
	float mMath, mPhysical; 
};
void nhap(Student &k) 
{
	cout << "Nhap ten: "; cin.getline(k.ten,30);
	cout << "Nhap lop: "; cin.getline(k.lop,30);
	cout << "Nhap diem Toan: "; cin >> k.mMath;
	cout << "Nhap diem Vat Ly: "; cin >> k.mPhysical;
    cin.ignore();
}
void xuat(Student k)
{
	cout << "\nTen: " << k.ten << endl;
	cout << "Lop: " << k.lop << endl;
	cout << "Diem Toan: " << k.mMath << endl;
	cout << "Diem Vat Ly: " << k.mPhysical << endl;
	cout<<"------------------------------------------";
}
void nhapmang(Student danhsach[],int n) 
{
	cout << "Nhap so hoc sinh can nhap: "; cin >> n;
    cin.ignore();
	for(int i=0; i<n; i++) 
		nhap(danhsach[i]);
}
void xuatmang(Student danhsach[], int n) 
{
	for(int i=0; i<n; i++)
		xuat(danhsach[i]);
}
void themhs (Student danhsach[], int n) 
{ 
    for(int i=0; i<1; i++)
	    nhap(danhsach[i]);
    n++; 
} 

void timkiemten (char tenhs[30], Student danhsach[], int n) 
{
	for (int i=0; i<n; i++) {
		int res = strcmp(danhsach[i].ten, tenhs);
		if ( res == 0 ) // so sanh == chi so sanh vs 2 so nguyen, 2 so thuc, 2 ky tu, 2 kieu bool
			xuat(danhsach[i]);
	}
}
int main()
{
	Student danhsach[100];
	int n;
    char ten[30];
	nhapmang(danhsach,n);
	xuatmang(danhsach,n);
 //   themhs(danhsach, n);
    timkiemten(ten, danhsach, n);
    return 0;
}