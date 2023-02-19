#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *pLink;
};
struct queue{
    Node *pFront;
    Node *pRear;
};
void initialize(queue &q){
    q.pFront=NULL;
    q.pRear=NULL;
}
Node *CreateNode(int d){
    Node *pNode=new Node;
    if(pNode==NULL){
        cout<<"Error allocated memory";
        exit(0);
    }
    pNode->data=d;
    pNode->pLink=NULL;
    return pNode;
}
void Enqueue(queue &q,int d){
    Node *pNode=CreateNode(d);
    if(q.pFront==NULL){
        q.pFront=q.pRear=pNode;
    }else{
        q.pRear->pLink=pNode;
        q.pRear=pNode;
    }
}
int Dequeue(queue &q){
    if(q.pFront==NULL){
        cout<<"Queue is empty";
        exit(0);
    }
    int d=q.pFront->data;
    Node *pDel=q.pFront;
    q.pFront=q.pFront->pLink;
    pDel->pLink=NULL;
    delete pDel;
    return d;
}
int Pfront(queue q){
    if(q.pFront==NULL){
        return -1;
    }
    int d=q.pFront->data;
    return d;
}
int checkDele(queue q,int d){
    if(q.pFront==NULL){
        return -1;
    }
    // int d;
    Node *ptm=q.pFront;
    while(ptm!=NULL){
        if(d==ptm->data){
            return d;
            break;
        }
        ptm=ptm->pLink;
    }
    return -1;
}
void Josephus(queue &q){
    queue dele;
    initialize(dele);

    int n,k,check=0,checkFor=0,checkQ=0;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter k:";
    cin>>k;
    int a=0;
    cout<<"Các vị trí bị loại bỏ là: ";
    for(int i=1;i<=n;i++){
        if(checkFor>=1){
            if(checkQ==(n-1)){
                cout<<endl;
                // if(q.pFront!=NULL){
                //     Node *ptm=q.pFront;
                //     while(ptm!=NULL){
                //         // cout<<ptm->data;
                //         Enqueue(dele,Dequeue(q));
                //         ptm=ptm->pLink;
                //     }
                // }
                // cout<<Dequeue(q)<<"\n";
                // cout<<Dequeue(dele)<<"\n";
                // cout<<Dequeue(dele)<<"\n";
                // cout<<Dequeue(dele)<<"\n";
                exit(0);
            }
            if(check==(k-1)&&i!=checkDele(dele,i)){
                if(i==Pfront(q)){
                    // cout<<"Dequeue: "<<Dequeue(q);
                    // Dequeue(q);
                    Enqueue(dele,Dequeue(q));
                    // check=0;
                    if(i==n){
                        i=0;
                    }
                }else{
                    cout<<i<<",";
                    Enqueue(q,i);
                    checkQ++;
                    check=0;
                    if(i==n){
                        i=0;
                    }
                }
            }else{
                if(i==Pfront(q)){
                    // cout<<"Dequeue: "<<Dequeue(q);
                    Enqueue(dele,Dequeue(q));
                    // check=0;
                    if(i==n){
                        i=0;
                    }
                }else{
                    if(checkDele(dele,i)==i){
                        // Dequeue(dele);
                        if(i==n){
                            i=0;
                        }
                        continue;
                    }else{
                        check++;
                        if(i==n){
                            i=0;
                        }
                    }
                }
            }
        }else{
            if(check==(k-1)){
                // if(check)
                cout<<i<<",";
                Enqueue(q,i);
                checkQ++;
                check=0;
                if(i==n){
                    checkFor++;
                    i=0;
                }
            }else{
                check++;
                if(i==n){
                    checkFor++;
                    i=0;
                }
                // continue;
            }
        }
    }
}
int main(){
    queue q;
    initialize(q);
    Josephus(q);
    return 0;
}