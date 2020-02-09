/*Title: Implementation of Dictionary using BST*/
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
	string word;
	string meaning;
	node *right;
};

class Dict
{
public:
	node *root;
	Dict()
	{
		root = NULL;
	}
	void create();
	void insert(node*, node*);
	void inorder(node*);
	void descend(node*);
	void search(node*, string);
	void modify(node*, string);
	node* minValue(node*);
	node* deleteNode(node*, string);
};

void Dict::create()
{
    node *temp;
	temp = new node;
    cout<<"Enter word: ";
    cin>>temp->word;
    getline(cin, temp->meaning);
    cout<<"Enter meaning: ";
    getline(cin, temp->meaning);
    temp->left = temp->right = NULL;
    if(root == NULL) root = temp;
    else insert(root, temp);
}

void Dict::insert(node *root, node *temp)
{
	if(temp->word < root->word)
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

void Dict::inorder(node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<temp->word<<endl;
		inorder(temp->right);
	}
}

void Dict::descend(node *temp)
{
	if(temp != NULL)
	{
		descend(temp->right);
		cout<<temp->word<<endl;
		descend(temp->left);
	}
}

void Dict::search(node *root, string str_key)
{
    if(str_key.compare(root->word)<0)
    {
        if(root->left == NULL) cout<<"Word not found"<<endl;
        else search(root->left, str_key);
    }
	else if(str_key.compare(root->word)>0)
    {
        if(root->right == NULL) cout<<"Word not found"<<endl;
        else search(root->right, str_key);
    }
    else
	{
		cout<<"Word: "<<root->word<<endl;
		cout<<"Meaning: "<<root->meaning<<endl;
	}
}

void Dict::modify(node *root, string str_key)
{
	if(str_key.compare(root->word)<0)
	{
	        if(root->left == NULL) cout<<"Word not found"<<endl;
	        else modify(root->left, str_key);
	}
	else if(str_key.compare(root->word)>0)
	{
	    if(root->right == NULL) cout<<"Word not found"<<endl;
	    else modify(root->right, str_key);
	}
	else
	{
		cout<<"Word: "<<root->word<<endl;
		getline(cin, root->meaning);
		cout<<"Enter new meaning: ";
		getline(cin, root->meaning);
	}
}

node* Dict::minValue(node *root)
{
	node *curr;
	curr = new node;
	curr = root;
	while(curr->left != NULL)
		curr = curr->left;
	return curr;
}

node* Dict::deleteNode(node *root, string str_key)
{
	if(root == NULL) return root;
	node *temp;
	temp = new node;
	if(str_key.compare(root->word)<0)
    {
        if(root->left == NULL)
            cout<<"Word not found"<<endl;
        else
            root->left = deleteNode(root->left, str_key);
    }
	else if(str_key.compare(root->word)>0)
    {
        if(root->right == NULL)
            cout<<"Word not found"<<endl;
        else
            root->right = deleteNode(root->right, str_key);
    }
	else
	{
		if(root->left == NULL)
		{
			temp = root->right;
			delete(root);
			return temp;
		}
		if(root->right == NULL)
		{
			temp = root->left;
			delete(root);
			return temp;
		}
		temp = minValue(root->right);
		root->word = temp->word;
		root->right = deleteNode(root->right, temp->word);
	}
	return root;
}

int main() {
	Dict B;
	string key;
	int n, op;
    x:B.create();
    cout<<"Do you want to continue(1/0): ";
    cin>>n;
    if(n==1) goto x;
	while(1)
	{
		cout<<"\n1. Enter a word";
		cout<<"\n2. Ascending order";
		cout<<"\n3. Descending order";
		cout<<"\n4. Search";
		cout<<"\n5. Modify";
		cout<<"\n6. Delete";
		cout<<"\n7. Exit";
		cout<<"\nEnter your choice: ";
		cin>>op;
		switch(op)
		{
			case 1: B.create(); break;
			case 2: cout<<"\nAscending order: "<<endl; B.inorder(B.root); break;
			case 3: cout<<"\nDescending order: "<<endl; B.descend(B.root); break;
			case 4: cout<<"\nEnter word you want to search: "; cin>>key; B.search(B.root, key); break;
			case 5: cout<<"\nEnter word you want to modify: "; cin>>key; B.modify(B.root, key); break;
			case 6: cout<<"\nEnter word you want to delete: "; cin>>key; B.root = B.deleteNode(B.root, key); break;
			case 7: exit(1); break;
			default: cout<<"\nInvalid choice"; break;
		}
	}
	return 0;
}

/*
Enter word: king
Enter meaning: monarch
Do you want to continue(1/0): 1
Enter word: queen
Enter meaning: wife of king
Do you want to continue(1/0): 1
Enter word: zebra
Enter meaning: name of animal
Do you want to continue(1/0): 1
Enter word: mango
Enter meaning: king of fruits
Do you want to continue(1/0): 1
Enter word: apple
Enter meaning: apple iphone
Do you want to continue(1/0): 1
Enter word: apache
Enter meaning: native american tribe
Do you want to continue(1/0): 0

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 1
Enter word: age
Enter meaning: age is a number

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 2

Ascending order:
age
apache
apple
king
mango
queen
zebra

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 3

Descending order:
zebra
queen
mango
king
apple
apache
age

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 4

Enter word you want to search: appy
Word not found

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 4

Enter word you want to search: age
Word: age
Meaning: age is a number

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 5

Enter word you want to modify: appy
Word not found

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 5

Enter word you want to modify: age
Word: age
Enter new meaning: age is not a word but a number

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 6

Enter word you want to delete: monarch
Word not found

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 6

Enter word you want to delete: age

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 2

Ascending order:
apache
apple
king
mango
queen
zebra

1. Enter a word
2. Ascending order
3. Descending order
4. Search
5. Modify
6. Delete
7. Exit
Enter your choice: 7

*/
