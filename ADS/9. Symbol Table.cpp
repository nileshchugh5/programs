/*Title: Implementation of BST*/
/*Name: Prabodh Wankhede
Roll No.: 57
SE(B)
*/

#include <iostream>
#include <cstdlib>
using namespace std;
class node
{
public:
	node *left;
	string symbol, dt;
	int size, l_no;
	node *right;
};
class Symbol
{
public:
	node *root;
	Symbol()
	{
		root = NULL;
	}
	void create();
	void insert(node*, node*);
	void display(node*);
	void update(node*, string);
};
void Symbol::create()
{
	node *temp;
	temp = new node;
	cout<<"Enter symbol: ";
    cin>>temp->symbol;
    getline(cin, temp->dt);
    cout<<"Enter data type: ";
    getline(cin, temp->dt);
    cout<<"Enter size: ";
    cin>>temp->size;
    cout<<"Enter line no.: ";
    cin>>temp->l_no;
    temp->left = temp->right = NULL;
    if(root == NULL) root = temp;
    else insert(root, temp);
}
void Symbol::insert(node *root, node *temp)
{
	if(temp->symbol < root->symbol)
	{
		if(root->left == NULL) root->left = temp;
		else insert(root->left, temp);
	}
	else
	{
		if(root->right == NULL) root->right = temp;
		else insert(root->right, temp);
	}
}
void Symbol::display(node *temp)
{
	if(temp != NULL)
	{
		display(temp->left);
		cout<<temp->symbol<<"\t"<<temp->dt<<"\t"<<temp->size<<"\t"<<temp->l_no<<endl;
		display(temp->right);
	}
}
void Symbol::update(node *root, string str_key)
{
	if(str_key.compare(root->symbol)<0)
	{
	        if(root->left == NULL) cout<<"Symbol not found"<<endl;
	        else update(root->left, str_key);
	}
	else if(str_key.compare(root->symbol)>0)
	{
	    if(root->right == NULL) cout<<"Symbol not found"<<endl;
	    else update(root->right, str_key);
	}
	else
	{
		cout<<"Symbol: "<<root->symbol<<endl;
		cout<<"Enter new data type: ";
		cin>>root->dt;
		cout<<"Enter new size: ";
		cin>>root->size;
		cout<<"Enter new line no.: ";
		cin>>root->l_no;
	}
}
int main() {
	Symbol S;
	string str;
	int n,ch;
	x:S.create();
	cout<<"Do you want to continue(1/0): ";
	cin>>n;
	if(n==1) goto x;
	while(true)
	{
		cout<<"\n1. Enter symbol"<<endl;
		cout<<"2. Display symbol table"<<endl;
		cout<<"3. Update line no.: "<<endl;
		cout<<"4. Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1: S.create(); break;
		case 2: S.display(S.root); break;
		case 3: cout<<"Enter symbol: ";
				cin>>str;
				S.update(S.root, str);
				break;
		case 4: exit(1); break;
		}
	}
	return 0;
}
/*
Enter symbol: a
Enter data type: char
Enter size: 1
Enter line no.: 10
Do you want to continue(1/0): 1
Enter symbol: *
Enter data type: pointer
Enter size: 8
Enter line no.: 12
Do you want to continue(1/0): 1
Enter symbol: 21
Enter data type: int
Enter size: 4
Enter line no.: 25
Do you want to continue(1/0): 0

1. Enter symbol
2. Display symbol table
3. Update line no.:
4. Exit
1
Enter symbol: 6.5
Enter data type: float
Enter size: 6
Enter line no.: 43

1. Enter symbol
2. Display symbol table
3. Update line no.:
4. Exit
2
*       pointer 8       12
21      int     4       25
6.5     float   6       43
a       char    1       10

1. Enter symbol
2. Display symbol table
3. Update line no.:
4. Exit
3
Enter symbol: 6.5
Symbol: 6.5
Enter new data type: double
Enter new size: 10
Enter new line no.: 156

1. Enter symbol
2. Display symbol table
3. Update line no.:
4. Exit
4
*/
