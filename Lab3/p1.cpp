#include<iostream>
#include <string>
using namespace std;

struct Node{
    char data;
    Node *pLink;
};

typedef Node *STACK;
void initialize(STACK &stack){
    stack=NULL;
}
Node *createNode(char d){
    Node *pNode=new Node;
    pNode->data=d;
    pNode->pLink=NULL;
    return pNode;
}
void push(STACK &stack,char d){
    Node *pNode=createNode(d);
    if(stack==NULL){
        stack=pNode;
    }else{
        pNode->pLink=stack;
        stack=pNode;
    }
}
char pop(STACK &stack){
    char d=stack->data;
    Node *pDel=stack;
    stack=stack->pLink;
    pDel->pLink=NULL;
    delete pDel;
    return d;
}
char top(STACK &stack){
    char d=stack->data;
    return d;
}

//NODEVALUE
struct NodeValue{
    float data;
    NodeValue *pLink;
};
typedef NodeValue *STACKVALUE;
void initializeValue(STACKVALUE &stack){
    stack=NULL;
}
NodeValue *createNodeValue(float d){
    NodeValue *pNode=new NodeValue;
    pNode->data=d;
    pNode->pLink=NULL;
    return pNode;
}
void pushValue(STACKVALUE &stack,float d){
    NodeValue *pNode=createNodeValue(d);
    if(stack==NULL){
        stack=pNode;
    }else{
        pNode->pLink=stack;
        stack=pNode;
    }
}
float popValue(STACKVALUE &stack){
    float d=stack->data;
    NodeValue *pDel=stack;
    stack=stack->pLink;
    pDel->pLink=NULL;
    delete pDel;
    return d;
}
float topValue(STACKVALUE &stack){
    float d=stack->data;
    return d;
}

bool CheckOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true;
    }else{
        return false;
    }
}
int Precedence(char c){
    if(c == '^'){
        return 3; 
    } 
    else if(c == '*' || c == '/'){
        return 2; 
    } 
    else if(c == '+' || c == '-') {
        return 1; 
    }
    else{
        return -1; 
    }
}
string InfixToPostfix(STACK &stack, string infix){
    string postfix;
    for(int i=0;i<infix.length();i++){
        if((infix[i] >= '0' && infix[i] <= '9')){
            postfix+=infix[i];
        }else if(infix[i]=='('){
            push(stack, infix[i]);
        }else if(infix[i]==')'){
            while(top(stack)!='('&&stack!=NULL){
                postfix+=pop(stack);
            }
            pop(stack);
        }else if(CheckOperator(infix[i])){
            if(stack==NULL){
                push(stack,infix[i]);
            }else{
                if(Precedence(top(stack))<Precedence(infix[i])){
                    push(stack,infix[i]);
                }else{
                    while(stack!=NULL&&Precedence(top(stack))>=Precedence(infix[i])){
                        postfix+=pop(stack);
                    }
                    push(stack,infix[i]);
                }
            }
        }
    }
    while(stack!=NULL)
	{
		postfix+=pop(stack);
	}
	return postfix;
}
void ValueOfPostfix(STACKVALUE &value,string postfix){
    float v;
    for(int i=0;i<postfix.length();i++){
        float p=0;
        float b=0;
        if((postfix[i] >= '0' && postfix[i] <= '9')){
            int n=postfix[i]-48;
            pushValue(value,n);
        }
        else{
            if(postfix[i]=='+'){
                p=popValue(value);
                b=popValue(value);
                v=b+p;
                pushValue(value,v);
            }else if(postfix[i]=='-'){
                p=popValue(value);
                b=popValue(value);
                v=b-p;
                pushValue(value,v);
            }else if(postfix[i]=='*'){
                p=popValue(value);
                b=popValue(value);
                v=b*p;
                pushValue(value,v);
            }else{
                p=popValue(value);
                b=popValue(value);
                v=b/p;
                pushValue(value,v);
            }
        }
    }
    cout<<topValue(value);
}
int main(){
    string infix;
    cin>>infix;
    cout<<"Infix: "<<infix<<endl;
    STACK stack;
    initialize(stack);
    cout<<"Postfix: "<<InfixToPostfix(stack,infix)<<endl;
    // Compute value
    STACKVALUE value;
    initializeValue(value);
    ValueOfPostfix(value,InfixToPostfix(stack,infix));

}
