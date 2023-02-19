#include <iostream>
using namespace std;

struct List{
	int data;
	List *next;
};

List *insertFirst(int item, List *ptr){
	List *p = new List;
	p->data=item;
	p->next=ptr;
	return p;
}

void printList(List *prt){
	List *p=prt;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
List *deleteFirst(List *ptr){
	if(ptr){
		List *tmp = ptr;
		List *p=ptr->next;
		delete tmp;
	}
	return p;

	return 0;
}
List *insertLast(int item, List *ptr){
	List *tmp = new List;
	tmp->data= item;
	tmp->next=0;
	if(!ptr){
		return tmp;
	}else{
		List *q=ptr;
		while(q->next) q=q->next;
		q->next=tmp;
		return ptr;
	}
}
int main(){
	List *l1=0;
	l1=insertFirst(2,l1);
	l1=insertFirst(3,l1);
	l1=insertFirst(4,l1);
	printList(l1);
}
