
#include<iostream>
#include<stack>
using namespace std;

void check()
{
    string s; 
    cout<<"Nhap: ";
    cin>>s;
    stack<char> st;
    for(char x : s){
        if (x == '(' || x=='{')
        {
            st.push(x);
        }else if(x==')' || x=='}'){
            if(st.empty()){
                cout<<"Invalid!\n";
                return;
            }else 
            {
                st.pop();
                cout<<"Valid!\n";
            }
            
        }else
        {
            continue;
        }
    }

    // if(st.empty()){
    //     cout<<"Valid!\n";
    // }else cout<<"Invalid!\n";
}

int main()
{
    while (true)
    {
        check();
    }
    return 0;
}

