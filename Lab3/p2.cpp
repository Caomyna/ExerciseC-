#include<iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node *pNext;
};
typedef Node *STACK;

void initialize(STACK &stack){
    stack=NULL;
}
Node *createNode(char d){
    Node *p=new Node;
    p->data=d;
    p->pNext=NULL;
    return p;
}
void push(STACK &stack,char d){
    Node *p=createNode(d);
    if(stack==NULL){
        stack=p;
    }else{
        p->pNext=stack;
        stack=p;
    }
}
char pop(STACK &stack){
    char d=stack->data;
    Node *p=stack;
    stack=stack->pNext;
    p->pNext=NULL;
    delete p;
    return d;
}
char top(STACK &stack){
    char d=stack->data;
    return d;
}
bool checkAlgebraic(STACK &stack,string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(' || s[i]=='{'){
            push(stack, s[i]);
        }
        else if(s[i]==')'|| s[i]=='}')
        {
            if(s[i]==')')
            {
                if(top(stack)=='('){
                    pop(stack);
                }else{
                    return false;
                    break;
                }
            }else{
                if(top(stack)=='{'){
                    pop(stack);
                }else{
                    return false;
                    break;
                }
            }
        }else{
            continue;
        }
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    STACK stack;
    initialize(stack);
    if(checkAlgebraic(stack,s)){
        cout<<"Valid";
    }else{
        cout<<"Invalid";
    }
    return 0;
}

