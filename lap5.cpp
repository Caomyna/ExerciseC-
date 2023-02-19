#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    Node()
    {
        this->left = this->right = NULL;
    }
};

struct ExpressionTree
{
    Node *root;
    ExpressionTree()
    {
        this->root = NULL;
    }
};

bool IsLeaf(Node *&tree)
{
    return tree->left == NULL && tree->right == NULL;
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;

    return 0;
}

string postfit(string s)
{
    string pos = "";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '(':
        {
            st.push(s[i]);
            break;
        }

        case ')':
        {
            while (st.top() != '(')
            {
                pos += st.top();
                st.pop();
            }
            st.pop();
            break;
        }
        case '+':
        case '-':
        case '*':
        case '/':
        {
            while (precedence(st.top()) > precedence(s[i]))
            {
                pos += st.top();
                st.pop();
            }
            st.push(s[i]);
            break;
        }
        default:
        {
            pos += s[i];
            break;
        }
        }
    }
    return pos;
}

void addToExpression(Node *&tree, string s)
{
    s = postfit(s);
    stack<Node *> stackNode;
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        {
            Node *p = new Node;
            p->data = s[i];
            p->right = stackNode.top();
            stackNode.pop();
            p->left = stackNode.top();
            stackNode.pop();
            stackNode.push(p);
            break;
        }
        default:
        {
            Node *p = new Node;
            p->data = s[i];
            stackNode.push(p);
            break;
        }
        }
    }
    tree = stackNode.top();
}

void showInfix(Node *&tree)
{
    if (tree)
    {
        showInfix(tree->left);
        cout << tree->data;
        showInfix(tree->right);
    }
}
void showPostfix(Node *&tree)
{
    if (tree)
    {
        showPostfix(tree->left);
        showPostfix(tree->right);
        cout << tree->data;
    }
}
void showPrefix(Node *&tree)
{
    if (tree)
    {
        cout << tree->data;
        showPrefix(tree->left);
        showPrefix(tree->right);
    }
}

double EvaluateExpressionTree(Node *&tree)
{
    double t = 0;
    if (IsLeaf(tree))
        t = float(tree->data);
    else
    {
        float x = EvaluateExpressionTree(tree->left);
        float y = EvaluateExpressionTree(tree->right);

        switch (tree->data)
        {
        case '+':
            t = x + y;
            break;
        case '-':
            t = x - y;
            break;
        case '*':
            t = x * y;
            break;
        case '/':
            t = x / y;
            break;
        }
    }
    return t;
}

int main()
{
    string s;
    getline(cin, s);
    ExpressionTree tree;

    addToExpression(tree.root, s);
    cout << "\nPreFix: \n";
    showPrefix(tree.root);
    cout << "\nInFix: \n";
    showInfix(tree.root);
    cout << "\nPostFix: \n";
    showPostfix(tree.root);
    cout << "\nvalue of the expressio: " << EvaluateExpressionTree(tree.root);
}