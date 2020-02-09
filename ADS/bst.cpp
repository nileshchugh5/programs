#include<iostream>
#include <cstdlib>
using namespace std;
class node
{
  public:
  int data;
  node *left,*right;
 
};

 class bst
 {
   public:
   int lht,rht;
   node *root,*temp,*curr;
   bst()
   {
     root=NULL;
     lht=0,rht=0;
   }
   void insert(node*,node*);
   void create();
   void display(node*);
   void min(node*);
   void search(node*,int);
   int depth(node *);
   void mirror(node*);
 };
 
    
      int main()
      {
        bst s;
        int b,ch;
      do 
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. Display "<<endl;
       cout<<" 3. Minmum "<<endl;
       cout<<" 4. Search "<<endl;
       cout<<" 5. Depth "<<endl;
       cout<<" 6. Mirror "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 1 : cout<<" Enter Number to be inserted : ";
                    s.create();
                    break;
           case 2 : cout<<endl;
                     s.display(s.root);
                    cout<<endl<<" -------------------"<<endl;
                   
                    break;
           case 3 : cout<<endl;
                    s.min(s.root);
                    cout<<endl<<" -------------------"<<endl;
                    
                    break;
           case 4 : cout<<endl;
		cout<<"\n enter the element you want to search  ";
        	 cin>>b;
        	s.search(s.root,b);
		cout<<endl<<" -------------------"<<endl;
		 break;

           case 5 : //cout<<" The Depth of Tree : ";
		    s.depth(s.root);
		    cout<<"\ndepth of tree is:"<<s.depth(s.root)<<endl;
		cout<<endl<<" -------------------"<<endl;
                    break;

           case 6 : cout<<endl;
		    s.mirror(s.root);
       		   s.display(s.root);
		    //cout<<"\nMirror of tree is: \t"<<s.mirror(s.root)<<endl; 
			//s.depth(s.root);
			cout<<endl<<" -------------------"<<endl;
	    default : system("pause");
                    return 0;
                    break;
       	}
      }while(1); 
	return 0; 
     }
     
  void bst::create()
  { 
    char op;
    do{
     	temp=new node;
     	cout<<"\n enter data ";
     	cin>>temp->data;
     	temp->left=NULL;
     	temp->right=NULL;
      	if(root==NULL)
        	 root =temp;
      	else
        	 insert(root,temp);
        	 
       cout<<"\n do you want to enter data (y for yes / n for no ) ";
       cin>>op;
       }while(op=='Y'|| op=='y');
   }
   
   void bst :: insert(node *root ,node *temp)
    {
        curr=root;
        if(temp->data == curr->data)
       		cout<<"dont add data  ";
       	else if(temp->data < curr->data)
       		{
       		   if(curr->left==NULL)
       		   	curr->left=temp;
       		   else
       		   	insert(curr->left,temp);
       		}
       	else if(temp->data > curr->data)
       		{
       		   if(curr->right==NULL)
       		   	curr->right=temp;
       		   else
       		   	insert(curr->right,temp);
       		}
             
     
         
    }
      
     void bst :: display(node *temp)
      {
         if(temp!=NULL)
         {
            display(temp->left);
            cout<<temp->data<<"  ";
            display(temp->right);
          }
      }
      
      
   void bst :: min(node *curr)
   {
      int k;
      while(curr-> left !=NULL)
      {
        curr=curr->left;
      }
         k=curr->data;
      cout<<"\n minimun is :   "<<k;
    
   }
   
    void bst :: search(node*curr ,int a)
    {
    	/*if(curr->data==a)
    		cout<<"data found successfully";
    	else if(a < curr->data)
    		{
    		  search(curr->left,a);
    		 }
    	else if(a > curr->data)
    		search(curr->right,a);*/
    		
         if(curr!=NULL)
          {
          search(curr->left,a);
            if(a==curr->data)
                cout<<"data  found   "<<a;
            else
 	cout<<"Data Not  found   ";
            search(curr->right,a);
          }
     }
    
    int bst::depth(node *root)
     {
       
       
         if(root==NULL)
         {
            return 0;
          }
       
        lht=depth(root->left);
        rht=depth(root->right);
            if(lht<rht)
               return(rht+1);
            else
            
            	return(lht+1);
            	         	  
       }
                     
     
    void bst::mirror(node *root)
    {
       node *temp;
      if(root!=NULL)
      {
      mirror(root->left);
      mirror(root->right);
      temp=root->left;
      root->left=root->right;
      root->right=temp;
     }
 
    }
      
    		  
    	
   
      
   
       
             
        
        
