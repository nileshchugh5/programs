//============================================================================
// Name        : BT.cpp
// Author      : Prabodh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
public:
	node *left;
	int data;
	node *right;
};

class BT
{
public:
	node *root;
	BT()
	{
		root = NULL;
	}
	void create();
	void insert(node*, node*);
	void inorder(node*);
	void preorder(node*);
	void postorder(node*);
};

void BT::create()
{
	node *temp;
	temp = new node;
	cout<<"Enter data: ";
	cin>>temp->data;
	temp->left = temp->right = NULL;
	if(root == NULL) root = temp;
	else insert(root, temp);
}

void BT::insert(node *root, node *temp)
{
	char op;
	cout<<"Current node: "<<root->data<<endl;
	cout<<"Where to place - L/R: ";
	cin>>op;
	if(op == 'l' || op == 'L')
	{
		if(root->left == NULL) root->left = temp;
		else insert(root->left, temp);
	}
	else if(op == 'r' || op == 'R')
	{
		if(root->right == NULL) root->right = temp;
		else insert(root->right, temp);
	}
	else
		cout<<"Invalid option."<<endl;
}

void BT::inorder(node *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<" ";
		inorder(temp->right);
	}
}
void BT::preorder(node *temp)
{
	if(temp != NULL)
	{
		cout<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void BT::postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<" ";
	}
}

int main() {
	BT B;
	int n;
	cout<<"How many nodes you want to enter: ";
	cin>>n;
	for(int i=0; i<n; i++)
		B.create();
	cout<<"\nPreorder: ";
	B.preorder(B.root);
	cout<<"\nInorder: ";
	B.inorder(B.root);
	cout<<"\nPostorder: ";
	B.postorder(B.root);
	return 0;
}
