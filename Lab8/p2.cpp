#include<iostream>
using namespace std;

#define M 9

struct Node
{
    int key;
    Node *next;
};

typedef Node *HashTable[M];

void InitHashTable(HashTable &HT)
{
    for (int i = 0; i < M; i++)
        HT[i] = NULL;
}

int Hash(int k)
{
    return k % M;
}

void AddTail(Node *&l, int k)
{
    Node *newNode = new Node{k, NULL};
    if (l == NULL)
    {
        l = newNode;
    }
    else
    {
        Node* p = l;
        while (p != NULL && p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}

void InsertNode(HashTable &HT, int k)
{
    int i = Hash(k);
    AddTail(HT[i], k);
}

void DeleteHead(Node *&l)
{
    if (l != NULL)
    {
        Node *p = l;
        l = l->next;
        delete p;
    }
}

void DeleteAfter(Node *&q)
{
    Node *p = q->next;
    if (p != NULL)
    {
        q->next = p->next;
        delete p;
    }
}

void DeleteNode(HashTable &HT, int k)
{
    int i = Hash(k);
    Node *p = HT[i];
    Node *q = p;
    while (p != NULL && p->key != k)
    {
        q = p;
        p = p->next;
    }
    if (p == NULL)
        cout << k << " not found!" << endl;
    else if (p == HT[i])
        DeleteHead(HT[i]);
    else
        DeleteAfter(q);
}

Node *SearchNode(HashTable HT, int k)
{
    int i = Hash(k);
    Node *p = HT[i];
    while (p != NULL && p->key != k)
        p = p->next;
    if (p == NULL)
        return NULL;
    return p;
}

void Traverse(Node *p)
{
    while (p != NULL)
    {
        cout << p->key << ' ';
        p = p->next;
    }
    cout << endl;
}

void TraverseHashTable(HashTable HT)
{
    for (int i = 0; i < M; i++)
    {
        cout << "Bucket " << i << ": ";
        Traverse(HT[i]);
    }
}

// MENU
void Menu(HashTable &mHashTable)
{
	int choose;
	while(true)
	{
		system("cls");
		cout << "\n\n\t============ MENU =============";
		cout << "\n\t1.Add a number to the table";
		cout << "\n\t2.Print out the hash table";
		cout << "\n\t3.Search for a given value";
		cout << "\n\t4.Remove a number from the hash table";
		cout << "\n\t0.Exit";
		cout << "\n\n\t============= END =============";
		
		cout << "\nInput the slection: ";
		cin >> choose;
		
		if(choose <0 || choose > 4)
		{
			cout << "\nInvalid selection. Please check again!";
			system("pause");
		}
		else if(choose == 1)
		{ 
			int num;
			cout << "\nInput a number:";
			cin >> num;
			InsertNode(mHashTable, num);
			system("pause");
		}
		else if(choose == 2)
		{
			TraverseHashTable(mHashTable);
			system("pause");
		}
		else if(choose == 3)
		{
			int x;
			cout << "\nInput a number to search:";
			cin >> x;
			Node *result = SearchNode(mHashTable, x);
    		if (result == NULL)
        	{
    			cout << "Not found!";
			}
    		else
        	cout << "Found!";
        	system("pause");
		}
		else if(choose == 4)
		{
			int z;
			cout << "\nInput a number to delete:";
			cin >> z;
			DeleteNode(mHashTable, z);
			system("pause");
		}
		else 
		{
			break; 
		}
	}
}
int main()
{
	HashTable mHashTable;
    InitHashTable(mHashTable);	
	Menu(mHashTable);
		
	system("pause");
	return 0;
}
